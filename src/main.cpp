#include <chameleon/conf/vars.h>
#include <chameleon/main.h>
#include <iostream>
#include <string>
#include <exception>

using namespace std;
int main(int argc, char *argv[]){
    root = get_current_dir_name();
    if(argc >1){
        if(std::string(argv[1])==std::string("new") and argc > 2){
            if(std::string(argv[2])==std::string("app") and argc >3){
                check();
                new_app(argv[3]);
            }else{
                new_project(argv[2]);
            }
        }else if(std::string(argv[1])==std::string("build")){
            if(argc==2){
                build();
            }else{
                show_help();
            }
        }else{
            show_help();
        }
    }else{
        show_help();
    }
    return 0;
}


