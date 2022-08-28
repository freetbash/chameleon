#ifndef PROJECT_test_app_MODELS
#define PROJECT_test_app_MODELS

#include <chameleon/models/Model.h>

class Test:public Model{
public:
    std::string name;
    int fid;


    template<class Archive>
    void hibernate(Archive & ar){
        ar & HIBERLITE_NVP(name);
        ar & HIBERLITE_NVP(fid);
    }


    std::string toJson(){
        return "{\"name\":\""+this->name+"\",{\"fid\":"+std::to_string(this->fid)+"}";
    }
    static std::string all(){
        auto a = db->getAllBeans<Test>();
        std::string json;
        json="[";
        for(auto each:a){
            json+=each->toJson()+", ";
        }
        json.pop_back();
        json.pop_back();
        json+="]";
        return json;
    }

};

#endif
