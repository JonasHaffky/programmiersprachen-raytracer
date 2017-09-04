#include "box.hpp"

    // Default Constructor 
  Box::Box() : 
  Shape {"Box", {}},
  min_ {0.0f, 0.0f, 0.0f}, 
  max_ {0.0f, 0.0f, 0.0f} {}

    // Constructor takes min and max
  Box::Box(glm::vec3 const& min, glm::vec3 const& max) :
  Shape {"Box", {}}, 
  min_ {min}, 
  max_ {max} {
      // corrects user input
    min_.x = std::min(min.x, max.x);
    min_.y = std::min(min.y, max.y);
    min_.z = std::min(min.z, max.z);
    max_.x = std::max(min.x, max.x);
    max_.y = std::max(min.y, max.y);
    max_.z = std::max(min.z, max.z);
  }

    // Constructor takes name, color, min and max
  Box::Box(std::string const& name, Material const& mat, glm::vec3 const& min, glm::vec3 const& max) : 
  Shape {name, mat},
  min_ {min}, 
  max_ {max} {
      // corrects user input
    min_.x = std::min(min.x, max.x);
    min_.y = std::min(min.y, max.y);
    min_.z = std::min(min.z, max.z);
    max_.x = std::max(min.x, max.x);
    max_.y = std::max(min.y, max.y);
    max_.z = std::max(min.z, max.z);
  }

    // Destructor
  Box::~Box() {
    
  }

    // gets area of box object
  float Box::area() const {
    glm::vec3 difference = max_ - min_;
    return 2 * (std::abs(difference.x * difference.y) + std::abs(difference.x * difference.z) + std::abs(difference.y * difference.z));
  }
  
    // gets volume of box object
  float Box::volume() const {
    glm::vec3 difference = max_ - min_;
    return std::abs(difference.x * difference.y * difference.z);
  }

    // prints Box object
  std::ostream& Box::print(std::ostream& os) const {
    Shape::print(os);
    os << "Minimum: (" << min_.x << ", " 
    << min_.y << ", " 
    << min_.z << ")" << "\n" 
    << "Maximum: (" << max_.x << ", " 
    << max_.y << ", " 
    << max_.z << ")" << std::endl;
    return os;
  }

    // get maximum
  glm::vec3 const& Box::maximum() const {
    return max_;
  }

    // get minimum
  glm::vec3 const& Box::minimum() const {
    return min_;
  }

    // set maximum
  void Box::maximum(glm::vec3 const& max) {
    max_ = max;
  }

    // set maximum
  void Box::minimum(glm::vec3 const& min) {
    min_ = min;
  }

  OptiHit Box::intersect(Ray const& rayn) const{

  OptiHit hit{this};
  Ray ray = rayn; //transformRay(get_transf_inv(), rayn);
  float new_min = -INFINITY, new_max = INFINITY;

  float t1 = (min_.x - ray.origin_.x)/ray.direction_.x;
  float t2 = (max_.x - ray.origin_.x)/ray.direction_.x;
  new_min = std::max(new_min,std::min(t1,t2));
  new_max = std::min(new_max,std::max(t1,t2));

  t1 = (min_.y - ray.origin_.y)/ray.direction_.y;
  t2 = (max_.y - ray.origin_.y)/ray.direction_.y;
  new_min = std::max(new_min,std::min(t1,t2));
  new_max = std::min(new_max,std::max(t1,t2));

  t1 = (min_.z - ray.origin_.z)/ray.direction_.z;
  t2 = (max_.z - ray.origin_.z)/ray.direction_.z;
  new_min = std::max(new_min,std::min(t1,t2));
  new_max = std::min(new_max,std::max(t1,t2));

  if (new_max > std::max(0.0f, new_min))
  {
    hit.distance_ = sqrt(new_min*new_min*(
                      ray.direction_.x*ray.direction_.x +
                      ray.direction_.y*ray.direction_.y +
                      ray.direction_.z*ray.direction_.z ));
    hit.surface_pt_ = this->calc_surface_pt(ray, hit.distance_);
    //hit.surface_pt_ = glm::vec3(hit.surface_pt_);
    hit.hit_ = true;  
    hit.normalen_vec_ = this->calc_normalen_vec(hit);
    //hit.normalen_vec_ = glm::normalize(glm::vec3(glm::transpose(get_transf_inv())*glm::vec4(hit.normalen_vec_, 0.0f)));
  }
  return hit;
}

//Zusatz zu intersect
glm::vec3 Box::calc_normalen_vec(OptiHit const& hit) const {
  auto surface_pt = hit.surface_pt_; 
  if(surface_pt.x == Approx(min_.x)){
    return glm::vec3{-1.0,0.0,0.0};
  }
  if(surface_pt.y == Approx(min_.y)){
    return glm::vec3{0.0,-1.0,0.0};
  }
  if(surface_pt.z == Approx(min_.z)){
    return glm::vec3{0.0,0.0,-1.0};
  }
  if(surface_pt.x == Approx(max_.x)){
    return glm::vec3{1.0,0.0,0.0};
  }
  if(surface_pt.y == Approx(max_.y)){
    return glm::vec3{0.0,1.0,0.0};
  }
  if(surface_pt.z == Approx(max_.z)){
    return glm::vec3{0.0,0.0,1.0};
  }
}

// member function: checks whether a given point is in a box or not
bool Box::in_box(glm::vec3 const& test) const{
  bool result = false;
  if (test.x >= min_.x && test.x <= max_.x){
      if (test.y >= min_.y && test.y <= max_.y){
        if (test.z >= min_.z && test.z <= max_.z){
          result = true;
        }
      }
    }
    return result;
}

// free function: checks whether a given point is in a box or not 
bool is_in_box(glm::vec3 const& min, glm::vec3 const& max, glm::vec3 const& point) {
  Box b {min, max};
    return b.in_box(point);
}

float distance_two_vecs(glm::vec3 const& p1, glm::vec3 const& p2) {
  return sqrt((p1.x-p2.x)*(p1.x-p2.x) +
    (p1.y-p2.y)*(p1.y-p2.y) +
    (p1.z-p2.z)*(p1.z-p2.z));
}