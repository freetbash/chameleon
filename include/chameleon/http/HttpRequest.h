#ifndef CHAMELEON_HTTP_HTTPREQUEST
#define CHAMELEON_HTTP_HTTPREQUEST
#include <map>
#include <string>
class HttpServer;

class HttpRequest{
public:
    int nfd;
    bool bad;
    std::string ip;
    std::string path;
    std::string method;
    std::map<std::string, std::string> headers;
    std::map<std::string, std::string> path_data;
    std::string body;
    
    void write(std::string msg);
    std::string read();
    
    HttpRequest();
    ~HttpRequest();
    void rm();
};

HttpRequest *NewHttpRequest(HttpServer *server);

#endif
