#ifndef BUW_CAMERA_HPP
#define BUW_CAMERA_HPP
#include <string>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <iostream>
#include "ray.hpp"

typedef glm::mat4 Matrix;

struct Camera {

   // Constructors 
  Camera();
  Camera(std::string const& name, double fovX);
  Camera(std::string const& name, double fovX, glm::vec3 const& ori, glm::vec3 const& dir, glm::vec3 const& up);
  Camera(std::string const& name, double fovX, glm::vec3 const& ori, glm::vec3 const& dir, glm::vec3 const& up,
    Matrix const& transform);
   // Destructor
  ~Camera();

  std::ostream& print(std::ostream& os) const;
  Ray calc_eye_ray(int x, int y, int height, int width) const;
  glm::mat4 transformCam() const;
  void translate(glm::vec3 const& v);
  void rotateX(float phi);
  void rotateY(float phi);
  void rotateZ(float phi);

   //member 
  std::string name_;
  double fovX_; // horizontal angle of view (x-axis)
  glm::vec3 origin_; // {0.0f, 0.0f, 0.0f}
  glm::vec3 direction_; // negative z-axis 
  glm::vec3 upVector_; // camera orientation (which way is up?)
  Matrix transform_;
  Matrix transformInv_;

};

std::ostream& operator << (std::ostream& os, Camera const& cam);

#endif // BUW_CAMERA_HPP