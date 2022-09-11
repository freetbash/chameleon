#ifndef CHAMELEON_HTTP_HTTPREQUEST
#define CHAMELEON_HTTP_HTTPREQUEST
#include <map>
#include <string>
class HttpServer;

class HttpRequest{
private:
    std::map<std::string, std::string> _GET;
    std::map<std::string, std::string> _POST;
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
    void handle_http_data();
    std::string GET(std::string key);
    std::string POST(std::string key);
    
    HttpRequest();
    ~HttpRequest();
    void rm();
};

HttpRequest *NewHttpRequest(HttpServer *server);

#endif
