#include <cstdlib>
#include <chameleon/main.h>
#include <chameleon/app/app.h>
#include <chameleon/utils/toml.h>
#include <chameleon/utils/tools.h>
#include <chameleon/utils/colors.h>
#include <chameleon/conf/vars.h>
void build(){
    const toml::value data = toml::parse(root+"/chameleon.toml");
    const auto project_data = toml::find(data, "chameleon");

    for (std::string app :toml::find<std::vector<std::string>>(project_data, "apps")){
                App(app).build();
        }
    std::string cmd("");
    cmd="ccache g++ -c "+root+"/config/urls.cpp -o "+root+"/temp/config.urls.cpp.o -I./ -std=c++14 -O3";
    log("[*] "+cmd);
    check_error(system(cmd.c_str()));

    cmd="ccache g++ "+root+"/temp/*.o "+root+"/main.cpp -I./ -lchameleon -lhiberlite -lsqlite3 -lpthread -ldl -o manage -std=c++14 -O3 -g";
    log("[*] "+cmd);
    check_error(system(cmd.c_str()));
    log(color("[+]Build ok! {\n\tmanage\n}\n",GREEN));



}
