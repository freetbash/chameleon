#ifndef CHAMELEON_VIEWS_VIEWS
#define CHAMELEON_VIEWS_VIEWS
#include <chameleon/http/HttpRequest.h>
#include <chameleon/http/HttpResponse.h>
#include <chameleon/template/template.h>
#include <chameleon/conf/vars.h>
namespace Views{
    void chameleon(HttpRequest *request);
    void handle_static(HttpRequest *request);
    void notfound(HttpRequest *request);
}

#endif 
