#include <chameleon/http/parser.h>
#include <iostream>
#include <chameleon/utils/tools.h>
#include <chameleon/utils/bashhttp.h>
#include <chameleon/conf/vars.h>
#include <string>
#include <chameleon/http/HttpResponse.h>

void parser(HttpRequest *request){
    std::string http_content = request->read();
    if(check_http(http_content)){
        request->path = get_http_path(http_content);
        request->method = get_http_method(http_content);
        // GET_DATA POST_DATA
        request->body = get_http_body(http_content);
        request->handle_http_data();
        request->headers = get_http_headers(http_content);
        
    }else{
        HttpResponse(request,"ERROR YOUR REQUEST!");
        log("[-] "+request->ip+request->path +" is not a http request! ");
        request->rm();
    }
}
