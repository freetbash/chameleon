#ifndef FB_HTTP_CODE
#define FB_HTTP_CODE
#include <map>
#include <string>
class HttpCode{
private:
    std::map<std::string,std::string> data;
public:
    std::string find(std::string code);
    HttpCode();
};
#endif