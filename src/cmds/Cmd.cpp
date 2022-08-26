#include <chameleon/cmds/Cmd.h>
#include <chameleon/app/app.h>
#include <chameleon/utils/tools.h>
#include <chameleon/utils/toml.h>
#include <chameleon/conf/vars.h>
#include <iostream>
#include <unistd.h>

Cmd::Cmd(int argc,char *argv[]){
    if (argc<2) {
        std::cout<<"Please enter '"<<argv[0]<<" help' to check your args."<<std::endl;
        exit(-3);
    }
    
    // ccao     new     app         app_name
    // agrv[0]  argv[1] argv[2]     argv[3]
    //          op      vector[0]   vector[1]
    this->op=argv[1];
    
    for (int i = 2; i<argc; i++){
        this->args.push_back(argv[i]);
    }
    
}
void Cmd::init(){
    root=get_current_dir_name();
    const toml::value data = toml::parse(root+"/chameleon.toml");
    const auto project_data = toml::find(data, "chameleon");
    name = toml::find<std::string>(project_data, "name");
    DEBUG = toml::find<bool>(project_data,"debug");
    
    TEMPLATE_DIR = root + toml::find<std::string>(project_data,"TEMPLATE_DIR");
    STATIC_DIR = root + toml::find<std::string>(project_data,"STATIC_DIR");
    STATIC_ROOT = toml::find<std::string>(project_data,"STATIC_ROOT");
    port = toml::find<int>(project_data,"port");
    db->open(toml::find<std::string>(project_data,"DATABASE_PATH"));
    for (std::string app :toml::find<std::vector<std::string>>(project_data, "apps")){
            INSTALLED_APPS.push_back(
                App(app)
            );
        }


    
}

void Cmd::start(){
    server =HttpServer::build(port);
    server->Receiver();
}

void Cmd::compare(){
    if(this->op == "run"){
        this->start();
    }else if(this->op == "help"){
        this->show_help();
    }else if(this->op=="urls"){
        this->show_urls();
    }else{
        this->show_help();
    }




}

void Cmd::show_help(){
    log("manage run");
    log("manage urls");
}

void Cmd::show_urls(){
        for(auto url:url_patterns->patterns){
            log(url.first);
        }
}
