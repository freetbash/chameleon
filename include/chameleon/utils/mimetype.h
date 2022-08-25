#ifndef FB_HTTP_MIMETYPE
#define FB_HTTP_MIMETYPE
#include <map>
#include <string>
class MimeType{
private:
    std::map<std::string,std::string> data;
public:
    std::string find(std::string suffix);
    MimeType();
};
#endif