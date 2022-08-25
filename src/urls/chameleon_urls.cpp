#include <chameleon/views/views.h>
#include <chameleon/conf/vars.h>


void chameleon_urls_init(){
    url_patterns//->path("/",(void *)Views::index)
                ->path("/chameleon",(void *)Views::chameleon)// banner
                ->path(STATIC_ROOT+"/(.*+)",(void *)Views::handle_static) // for static
                ->path("/chameleon_not_found",(void *)Views::notfound)  // 404 notfound
    ;
}
