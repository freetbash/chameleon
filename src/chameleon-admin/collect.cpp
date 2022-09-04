#include <chameleon/main.h>
void collect(){
    std::string collect_dir = root + "/collect";
    c_mkdir(collect_dir);
    std::string cmd;
    c_mkdir(collect_dir+"/usr");
    c_mkdir(collect_dir+"/usr/include");
    c_mkdir(collect_dir+"/usr/include/chameleon");
    cmd="cp /usr/include/chameleon "+collect_dir+"/usr/include/chameleon -rf";
    log(cmd);
    check_error(system(cmd.c_str()));
    
    c_mkdir(collect_dir+"/usr/bin");
    cmd="cp /usr/bin/chameleon-admin "+collect_dir+"/usr/bin/chameleon-admin";
    log(cmd);
    check_error(system(cmd.c_str()));
	
    c_mkdir(collect_dir+"/usr/lib");
    cmd="cp /usr/lib/libchameleon.a "+collect_dir+"/usr/lib/libchameleon.a";
    log(cmd);
    check_error(system(cmd.c_str()));

    c_mkdir(collect_dir+"/usr/include/hiberlite");
	cmd="cp /usr/include/hiberlite "+collect_dir+"/usr/include/hiberlite -rf";
    log(cmd);
    check_error(system(cmd.c_str()));

    cmd="cp /usr/include/sqlite3.h "+collect_dir+"/usr/include/sqlite3.h ";
    log(cmd);
    check_error(system(cmd.c_str()));

    cmd="cp /usr/lib/libhiberlite.a "+collect_dir+"/usr/lib/libhiberlite.a ";
    log(cmd);
    check_error(system(cmd.c_str()));

    cmd="cp /usr/lib/libsqlite3.a "+collect_dir+"/usr/lib/libsqlite3.a ";
    log(cmd);
    check_error(system(cmd.c_str()));
}