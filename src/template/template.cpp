#include <chameleon/template/template.h>
#include <chameleon/views/views.h>
#include <exception>
#include <chameleon/conf/vars.h>

void render(HttpRequest *request,std::string template_path,std::vector<EasyJson::JSONObject> data){
                                                        // {}
    std::string file_path = TEMPLATE_DIR+"/"+template_path;
    
    if(FileExists(file_path)){
        cJinja::HtmlTemplate html(file_path,0);
        for(EasyJson::JSONObject obj:data){
            html.setValue(obj);
        }
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
