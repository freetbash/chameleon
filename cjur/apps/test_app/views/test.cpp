#include <apps/test_app/views.h>
// test_app.views.o
void test_app::test(HttpRequest *request){
    HttpResponse(request,"test_app");
}