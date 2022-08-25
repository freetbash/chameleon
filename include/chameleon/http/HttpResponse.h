#ifndef CHAMELEON_HTTP_HTTPRESPONSE
#define CHAMELEON_HTTP_HTTPRESPONSE
#include <chameleon/http/HttpRequest.h>
#include <string>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <chameleon/views/views.h>
#include <sys/socket.h>

#include <unistd.h>
#include <string.h>
#include <chameleon/conf/vars.h>
#include <chameleon/utils/tools.h>
class HttpResponse{
public:
    std::string status_code;
    std::map<std::string, std::string> headers;
    std::string content;
    HttpResponse(HttpRequest *request, std::string content, std::string status_code="200");
    std::string toString();
    HttpResponse();
    
};
void FileResponse(HttpRequest *request, std::string file_path, std::string status_code="200");
void JsonResponse(HttpRequest *request, std::map<std::string, std::string> d, std::string status_code="200");



#endif