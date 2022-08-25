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
    cmd="ccache g++ -c "+root+"/config/admin.cpp -o "+root+"/temp/config.admin.cpp.o -I./ -lchameleon -lsqlite3 -std=c++14 -O3";
    log("[*] "+cmd);
    check_error(system(cmd.c_str()));

    cmd="ccache g++ "+root+"/temp/*.o "+root+"/main.cpp -I./ -lchameleon -lpthread -lsqlite3 -o manage -std=c++14 -O3 -g";
    log("[*] "+cmd);
    log(color("[+]Build ok! {\n\tmanage\n}\n",GREEN));
    check_error(system(cmd.c_str()));



}
