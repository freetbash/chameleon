#ifndef CHAMELEON_MODELS_MODEL
#define CHAMELEON_MODELS_MODEL
#include <string>
#include <chameleon/template/template.h>

class Model{
    friend class hiberlite::access;
public:
    virtual std::string toJson()=0;
    EasyJson::JSONObject obj(){
        std::string json=this->toJson();
        return *(EasyJson::JSONBase::parse_obj(json));
    }
};


#endif