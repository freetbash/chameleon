#include <apps/test_app/views.h>
// test_app.views.o
void test_app::test(HttpRequest *request){
    render(request,"test_app/index.html",{{"sb",Test::all()}});
}