#ifndef CHAMELEON_TEMPLATE_TEMPLATE
#define CHAMELEON_TEMPLATE_TEMPLATE
#include <chameleon/http/HttpRequest.h>
#include <chameleon/http/HttpResponse.h>
#include <string>
#include <chameleon/utils/tools.h>
#include <chameleon/template/cjinja.h>
#include <chameleon/conf/vars.h>
#include <vector>

void render(HttpRequest *request,std::string template_path,std::vector<EasyJson::JSONObject> data);


#endif 