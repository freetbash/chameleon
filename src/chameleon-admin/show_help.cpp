#include <chameleon/main.h>
void show_help(){
    log(
        color("chameleon-admin new project_name\n",WHITE)
       +color("chameleon-admin new app app_name\n",WHITE)
       +color("chameleon-admin build\n",WHITE)
       +color("chameleon-admin collect\n",WHITE)
    );
}
