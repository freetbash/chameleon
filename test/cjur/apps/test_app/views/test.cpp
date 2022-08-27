#include <apps/test_app/views.h>
// test_app.views.o
void test_app::test(HttpRequest *request){
    auto c = db->createBean<Test>();
    c->name="fuck";


    render(request,"test_app/index.html",{{"sb",c->toJson()}});
}