#include <chameleon/app/app.h>
#include <cstdlib>
#include <chameleon/utils/tools.h>
#include <chameleon/conf/vars.h>
App::App(std::string name){
    this->name = name;


}

void App::build(){
    std::string cmd;
    log("[*]Building ...("+this->name+")");
   for(std::string _:ls(root+"/apps/"+this->name+"/views/")){
        cmd="ccache g++ -c "+root+"/apps/"+this->name+"/views/"+_
            +" -I./  -o "+root+"/temp/"+this->name+".views."+_+".o -std=c++14 -O3";
        log("[*] "+cmd);
        check_error(system(cmd.c_str()));
   }
        cmd="ccache g++ -c "+root+"/apps/"+this->name+"/urls.cpp"
            +" -I./  -o "+root+"/temp/"+this->name+".urls.cpp.o -std=c++14 -O3";
        log("[*] "+cmd);
        check_error(system(cmd.c_str()));
   




}
