#include <chameleon/main.h>

void new_app(std::string app_name){
    std::string app_dir =root +"/apps/"+app_name;
    c_mkdir(app_dir);
    c_mkdir(app_dir+"/views");
    std::ofstream views;
    views.open(app_dir+"/views.h",std::ios::out);
{views<<"#ifndef PROJECT_"<<app_name<<"_VIEWS\n#define PROJECT_"<<app_name<<"_VIEWS\n#include <chameleon/http/HttpRequest.h>\n#include <chameleon/http/HttpResponse.h>\n#include <apps/"+app_name+"/models.h>\n\/\/ urls.cpp\nvoid "<< app_name <<"_urls_init();\n\nnamespace "<<app_name<<"{\n    void test(HttpRequest *request);\n}\n\n#endif";

}views.close();


    std::ofstream test;
    test.open(app_dir+"/views/test.cpp",std::ios::out);
{test<<"#include <apps/"<<app_name<<"/views.h>\n"
    <<"\/\/ "<<app_name<<".views.o\nvoid "<< app_name<<"::test(HttpRequest *request){\n    HttpResponse(request,"<<"\""<<app_name<<"\""<<");\n}";

}test.close();

    std::ofstream urls;
    urls.open(app_dir+"/urls.cpp",std::ios::out);
{urls<<"#include <apps/"<<app_name<<"/views.h>\n#include <chameleon/conf/vars.h>\n\nvoid "<<app_name<<"_urls_init(){\nurl_patterns\n            ->path("
<<"\"/"<<app_name<<"\",(void *)"<<app_name<<"::test)\n    ;\n}\n";

}urls.close();


    std::ofstream models;
    models.open(app_dir+"/models.h",std::ios::out);
{models<<"#ifndef PROJECT_"+app_name+"_MODELS\n"+"#define PROJECT_"+app_name+"_MODELS\n"<<R""(
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
)"";

}models.close();

    log("Please insert "+app_name+" into chameleon.toml[apps]]");
}
