#include "scene.hpp"

Scene Scene::loadScene(std::string const& fileIn) const{
  Scene thisScene;

  std::ifstream file;
  std::string line;
  file.open(fileIn);

  if(file.is_open()){

    while(std::getline(file,line)){
      std::stringstream ss;
      std::string keyword;

      ss<<line;
      ss>>keyword;

      if(keyword == "define"){
        ss<<line;
        ss>>keyword;

        if(keyword == "material"){

          Material mat;

          ss>>mat.name_;

          ss>> mat.ka_.r;
          ss>> mat.ka_.g;
          ss>> mat.ka_.b;
          ss>> mat.kd_.r;
          ss>> mat.kd_.g;
          ss>> mat.kd_.b;
          ss>> mat.ks_.r;
          ss>> mat.ks_.g;
          ss>> mat.ks_.b;
          ss>> mat.m_;

          myScene.addMaterial(mat);
        }
        //here you can add shapes or whatever
      }
    }
    file.close();
  }

  myScene.printScene();

  return myScene;

}

void Scene::addMaterial(Material const& mat){
  auto sp = std::make_shared<Material>(mat);
  materials_.push_back(sp);
  std::cout<< sp->name_<<" wird gepusht.\n\n";
}

void Scene::printScene() const{
      std::cout<<"Materiealien der Szene:\n";
      for(const auto& i: materials_){
        Material m{i->name_, i->ka_, i->kd_, i->ks_, i->m_};
        std::cout<<m;
      }
      //here print for rest of objects
}