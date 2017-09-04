#ifndef BUW_SCENE_HPP
#define BUW_SCENE_HPP
#include "material.hpp"
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"
#include "cylinder.hpp"
#include "camera.hpp"
#include "lightsource.hpp"
#include "color.hpp"
#include "composite.hpp"
#include <iostream>      
#include <fstream>
#include <sstream> 
#include <string>
#include <map>
#include <vector>

struct Scene {

    // member
  unsigned int width_; // canvas size (x * y)
  unsigned int height_; 
  std::map<std::string, Material> materials_; 
  std::shared_ptr<Composite> composite_; 
  std::vector<LightSource> lights_;
  Camera cam_; // std::shared_ptr<Camera>
  std::string fileOut_;

};

#endif // BUW_SCENE_HPP