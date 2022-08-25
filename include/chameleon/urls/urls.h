#ifndef CHAMELEON_URLS_URLS
#define CHAMELEON_URLS_URLS
#include <vector>
#include <map>
#include <string>
#include <chameleon/http/HttpRequest.h>

class UrlPatterns{
public:
    std::map<std::string, void *> patterns;
    static void match(HttpRequest *request);
    UrlPatterns *const path(std::string path,void *fuck);
};
std::string contain(HttpRequest *request,UrlPatterns *url_patterns);
void chameleon_urls_init();








#endif
