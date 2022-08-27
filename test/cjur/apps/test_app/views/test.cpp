#include <apps/test_app/views.h>
// test_app.views.o
void test_app::test(HttpRequest *request){
    auto _ = db->createBean<Test>();
    _->name="123123132";

    render(request,"test_app/index.html",{_->obj()});
}