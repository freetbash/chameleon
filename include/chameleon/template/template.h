#ifndef CHAMELEON_TEMPLATE_TEMPLATE
#define CHAMELEON_TEMPLATE_TEMPLATE
#include <chameleon/http/HttpRequest.h>
#include <chameleon/http/HttpResponse.h>
#include <string>
#include <chameleon/utils/tools.h>
#include <chameleon/conf/vars.h>
#include <chameleon/template/cjinja.h>
#include <vector>
#include <map>

void render(HttpRequest *request,std::string template_path,std::map<std::string,std::string> data);


#endif 