#ifndef CHAMELEON_CMDS_CMD
#define CHAMELEON_CMDS_CMD
#include <string>
#include <vector>
class Cmd{
public:
    std::string op;
    std::vector<std::string> args;
    Cmd(int argc,char *argv[]);
    int port;
    void init();
    void compare();
    void show_help();
    void show_urls();
private:
    void start();

};
#endif
