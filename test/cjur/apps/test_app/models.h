#ifndef PROJECT_test_app_MODELS
#define PROJECT_test_app_MODELS

#include <chameleon/models/Model.h>

class Test:public Model{
public:
    std::string name;


    template<class Archive>
    void hibernate(Archive & ar){
        ar & HIBERLITE_NVP(name);
    }


    std::string toJson(){
        return "{\"name\":\""+this->name+"\"}";
    }

};

#endif
