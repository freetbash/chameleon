#ifndef PROJECT_test_app_VIEWS
#define PROJECT_test_app_VIEWS
#include <chameleon/http/HttpRequest.h>
#include <chameleon/http/HttpResponse.h>
#include <apps/test_app/models.h>
// urls.cpp
void test_app_urls_init();

namespace test_app{
    void test(HttpRequest *request);
}

#endif