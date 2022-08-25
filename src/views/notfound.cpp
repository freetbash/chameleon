#include <chameleon/views/views.h>

void Views::notfound(HttpRequest *request){
    HttpResponse *response = new HttpResponse;
    response->content="404 not found ";
    response->headers["Server"]=SERVER;
    response->headers["Content-type"]=mimetype.find(split(request->path,".").back());
    response->headers["Content-Length"]=std::to_string(response->content.length());
    response->headers["Date"]=http_gmtime();
    response->status_code="404";
    request->write(response->toString());
    log(" ["+request->method+"] "+request->ip+" ------------------><"+response->status_code+">("+request->path+")| text/html");

    request->rm();
}
