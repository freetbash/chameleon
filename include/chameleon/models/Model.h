#ifndef CHAMELEON_MODELS_MODEL
#define CHAMELEON_MODELS_MODEL
#include <string>
#include <chameleon/template/template.h>
#include <vector>
class Model{
    friend class hiberlite::access;
public:
    virtual std::string toJson()=0;
    static std::string all();

    EasyJson::JSONObject obj(){
        std::string json=this->toJson();
        return *(EasyJson::JSONBase::parse_obj(json));
    }
    static std::string models_list_to_json(std::vector<Model *> data){
        std::string list;
        list="[";
        for(Model *m:data){
            list+=m->toJson()+", ";
        }
        list.pop_back();
        list.pop_back();
    list+="]";
        return list;
    }
    
    
};


#endif