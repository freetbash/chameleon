#include <config/setting.h>

int main(int argc, char *argv[]){
    Cmd *cmd = new Cmd(argc,argv);
    cmd->init();
    // urls init
    {
        chameleon_urls_init();
        apps_urls_init();
        app_models_register();
    }
    cmd->compare();

    return 0;
}

// export classes
HIBERLITE_EXPORT_CLASS(Test)

// register class
void app_models_register(){
    db->registerBeanClass<Test>();
}