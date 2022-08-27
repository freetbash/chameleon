#include <chameleon/template/template.h>
#include <chameleon/views/views.h>
#include <exception>
#include <chameleon/conf/vars.h>

void render(HttpRequest *request,std::string template_path,std::map<std::string,std::string> data){
                                                        // {"key":value}
    std::string file_path = TEMPLATE_DIR+"/"+template_path;
    
    if(FileExists(file_path)){
        std::string json;
        json="{";
        for(std::pair<std::string,std::string> each :data){
            json+="\""+each.first+"\":";
            json+=each.second+",";
        }
        json.pop_back();
        json+="}";
        log(json);
        cJinja::HtmlTemplate html(file_path,0);
        EasyJson::JSONObject obj = *(EasyJson::JSONBase::parse_obj(json));
        html.setValue(obj);
        try {
            HttpResponse(request,html.render());
        } catch(std::exception& e) {
            if(DEBUG){
                HttpResponse(request,std::string(e.what()));
            }else{
                HttpResponse(request,"SERVER ERROR 500","500");
            }
        }
    }else{
        Views::notfound(request);
    }
}
