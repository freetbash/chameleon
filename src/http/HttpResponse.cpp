#include <chameleon/http/HttpResponse.h>
#include <chameleon/conf/vars.h>
#include <chameleon/utils/tools.h>
#include <chameleon/template/template.h>
HttpResponse::HttpResponse(){}

HttpResponse::HttpResponse(HttpRequest *request, std::string content, std::string status_code){
    this->content = content;
    this->headers["Content-type"]=mimetype.find(split(request->path,"\\.").back());
    this->headers["Content-Length"]=std::to_string(content.length());
    this->headers["Date"]=http_gmtime();
    
    this->status_code=status_code;
    std::string final_http_response = this->toString();
    request->write(final_http_response);
    log(" ["+request->method+"] "+request->ip+" ------------------><"+this->status_code+">("+request->path+")| "+this->headers["Content-type"]);

    request->rm();
}

std::string HttpResponse::toString(){
    return std::string(
        // first line
        HTTP_VERSION + " "+this->status_code+" "+httpcode.find(this->status_code)+HTTP_DELIM
        // headers
        +SERVER+HTTP_DELIM
        +"Content-type: "+this->headers["Content-type"]+HTTP_DELIM
        +"Content-Length: "+this->headers["Content-Length"]+HTTP_DELIM
        +"Date: "+this->headers["Date"]+HTTP_DELIM
        +HTTP_DELIM
        // content
        +this->content
    );
}