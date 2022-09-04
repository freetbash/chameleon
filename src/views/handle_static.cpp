#include <regex>
#include <chameleon/views/views.h>
#include <string>
void Views::handle_static(HttpRequest *request){
    std::smatch results;
    std::regex rp(STATIC_ROOT+"/(.*+)");
    std::regex_search(request->path,results,rp);
    FileResponse(request,STATIC_DIR+"/"+results.str(1));
}
// /star_name/version/star_name-version.tar.gz
