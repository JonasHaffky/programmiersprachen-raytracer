// -----------------------------------------------------------------------------
// Copyright  : (C) 2014-2017 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#include "renderer.hpp"
#include <cmath>
#include <glm/glm.hpp>

Renderer::Renderer(Scene const& scene) : 
  scene_ (scene),
  colorbuffer_(scene_.width_ * scene_.height_, Color(0.0, 0.0, 0.0)),
  ppm_(scene_.width_, scene_.height_)
  {}

void Renderer::render() {

  for (unsigned y = 0; y < scene_.height_; ++y) {
    for (unsigned x = 0; x < scene_.width_; ++x) {
      Ray ray = scene_.cam_.calc_eye_ray(x,y,scene_.height_,scene_.width_);
      Pixel p(x,y);

      p.color = raytrace(ray, 2);

      write(p);
    }
  }

  ppm_.save(scene_.fileOut_);
}

Color Renderer::raytrace(Ray const& ray, unsigned int depth) {
  OptiHit closest = scene_.composite_->intersect(ray); 
  Color color;

  if (closest.hit_){
    
    float c = 0.001;
    // Lichtberechnung
    for (auto const& lightsource : scene_.lights_){
      // Ray, das vom Oberflächenpunkt der Shape
      // aus zur Lightsource verläuft
      Ray lightray{closest.surface_pt_,
       lightsource.pos_-closest.surface_pt_};
      // Verschieben des Ursprungs weg von der Shape,
        // um ungewollte Kollision zu vermeiden
      lightray.origin_ += lightray.direction_ * c;

      // Erstellen der Parameter für ambiente Beleuchtung
      glm::vec3 l = lightray.direction_;
      float nl = glm::dot(closest.normalen_vec_,l);
      // Ambiente Lichtberechnung
      color = color + lightsource.ia_ *
        (closest.closest_shape_->material().ambient());

      // Diffuse Lichtberechnung
      // Einfache Spiegelung
      // Spekulare Reflexion
      if (scene_.composite_->intersect(lightray).hit_ == false){
        // Erstellen der Parameter
        glm::vec3 r = glm::normalize(2 *
          nl * closest.normalen_vec_ - l);
        glm::vec3 v = glm::normalize(glm::vec3 {ray.direction_.x * (-1),
          ray.direction_.y * (-1), ray.direction_.z * (-1)});
        // Lichtberechnung (diffus + spekular)
        color = color + lightsource.ip_ * (
        (closest.closest_shape_->material().specular()) *
        std::pow(glm::dot(r, v),
        closest.closest_shape_->material().exponent()) +
        (closest.closest_shape_->material().diffuse()) *
        std::max(nl, 0.0f));
      }
    }
    Color speculatius = closest.closest_shape_->material().specular();
    // Refraction (Glaskugeleffekt)
    if (depth > 0){
      glm::vec3 v = ray.direction_;
      float vnorm = glm::dot(closest.normalen_vec_, v);
      glm::vec3 r = glm::normalize(v - 2 *
        vnorm * closest.normalen_vec_);

      Ray reflection_ray{closest.surface_pt_, r};
      // Verschieben des Ursprungs weg von der Shape,
      // um ungewollte Kollision zu vermeiden 
      reflection_ray.origin_ += reflection_ray.direction_ * c;
      
      // Rekursion entsprechend der Tiefe (depth)
      Color reflection_color = raytrace(reflection_ray, depth - 1);
      Color refraction_color{};

        // Bedingung, dass das Objekt reflektiert
        // und die Tiefe noch nicht erreicht ist
      if (closest.closest_shape_->material().refraction() > 0.15f &&
        depth > 0){
        float q;
        float ri = closest.closest_shape_->material().refraction();
        float c1 = glm::dot(closest.normalen_vec_, v);
        // Überprüfung Kreuzprodukt (Winkelgröße)
        if (c1 < 0){
          c1 = c1 * (-1.0f);
          q = 1 / ri;
        }
        else{
          q = ri;
          closest.normalen_vec_ = closest.normalen_vec_ * (-1.0f);
        }
        float c2 = 1 - q * q * (1 - c1 * c1);
        if (c2 > 0){
          c2 = sqrt(c2);
        }
        else{
          c2 = 0;
        }
        // Rechnung nach Fresnel
        glm::vec3 fresnel_life_hack = glm::normalize(q * v +
          (q * c1 - c2) * closest.normalen_vec_);

        Ray refraction_ray{closest.surface_pt_, fresnel_life_hack};
        // Verschieben des Ursprungs weg von der Shape,
        // um ungewollte Kollision zu vermeiden
        refraction_ray.origin_ += refraction_ray.direction_ * c;

        refraction_color = raytrace(refraction_ray, depth - 1);
        
        color = color + refraction_color * 0.33f;
      }
      color = color + reflection_color * speculatius *
      closest.closest_shape_->material().refraction() * 0.4f;
    }
  }
  
  else {
    color = Color(0.6f,0.6f,0.7f); // dark grey background
  }

  return color;
}

void Renderer::write(Pixel const& p) {
  // flip pixels, because of opengl glDrawPixels
  size_t buf_pos = (scene_.width_*p.y + p.x);
  if (buf_pos >= colorbuffer_.size() || (int)buf_pos < 0) {
    std::cerr << "Fatal Error Renderer::write(Pixel p) : "
      << "pixel out of ppm_ : "
      << (int)p.x << "," << (int)p.y
      << std::endl;
  } else {
    colorbuffer_[buf_pos] = p.color;
  }

  ppm_.write(p);
}