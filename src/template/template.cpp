#include <chameleon/template/template.h>
#include <chameleon/views/views.h>
#include <exception>
#include <chameleon/conf/vars.h>

void render(HttpRequest *request,std::string template_path,std::map<std::string,std::string> data){
                                                        // {"key":value}
    std::string file_path = TEMPLATE_DIR+"/"+template_path;

    if(FileExists(file_path)){
        std::string content;
        if(!data.empty()){

            std::string json;
            json="{";
                for(std::pair<std::string,std::string> each :data){
                    json+="\""+each.first+"\":";
                    json+=each.second+", ";
                }
                json.pop_back();// "."
                json.pop_back();// " "
            json+="}";
        
            cJinja::HtmlTemplate html(file_path,0);
            EasyJson::JSONObject obj = *(EasyJson::JSONBase::parse_obj(json));
            html.setValue(obj);
        
            try {
                content = html.render();
            } catch(std::exception& e) {
                if(DEBUG){
                    content = e.what();
                }else{
                    content = "SERVER ERROR 500";
                }
            }
        }else{
            FileResponse(request,file_path);
        }
    }else{
        Views::notfound(request);
    }
}
