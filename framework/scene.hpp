#ifndef SCENE_HPP
#define SCENE_HPP

#include "material.hpp"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

struct Scene{

  Scene loadScene(std::string const& fileIn) const;
  void addMaterial(Material const& m);
  void printScene() const;

  std::vector<std::shared_ptr<Material>> materials_;
};
#endif //SCENE_HPP