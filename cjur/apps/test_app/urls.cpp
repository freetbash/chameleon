#include <apps/test_app/views.h>
#include <chameleon/conf/vars.h>

void test_app_urls_init(){
url_patterns
            ->path("/test_app",(void *)test_app::test)
    ;
}
