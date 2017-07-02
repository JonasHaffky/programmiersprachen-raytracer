#include "SDFloader.hpp"

void SDFloader::print() const{
      std::cout<<"PrintMethode\n";
      for(const auto& i: materials_){
        std::cout<<"For Schleife\n";
        Material mp{i.name_, i.ka_, i.kd_, i.ks_, i.m_};
        std::cout<<mp;
      }
    }

void SDFloader::addMaterial(Material const& mat){
  materials_.push_back(mat);
}

void SDFloader::loadMaterial(std::string const& fileIn) const{
  SDFloader myLoader;

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

            myLoader.addMaterial(mat);

          }
        }
      }
      file.close();
      std::cout << "Das ist der Vector mit den Materialien:\n";
    }

    myLoader.print();

}