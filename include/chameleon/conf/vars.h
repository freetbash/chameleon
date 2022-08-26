#ifndef CHAMELEON_PUBLIC_VARS
#define CHAMELEON_PUBLIC_VARS
#define MAX_SIZE 8192
#define MAX_CLIENTS 512

#include <string>
#include <chameleon/utils/mimetype.h>
#include <chameleon/utils/httpcode.h>
#include <chameleon/utils/httptime.h>
#include <chameleon/cmds/Cmd.h>

extern MimeType mimetype;
extern HttpCode httpcode;

extern std::string SERVER;
extern std::string HTTP_VERSION;
extern std::string HTTP_DELIM;

#include <chameleon/urls/urls.h>
extern UrlPatterns *url_patterns;


#include <chameleon/http/HttpServer.h>
extern HttpServer *server;

#include <chameleon/app/app.h>
#include <vector>
extern std::vector<App> INSTALLED_APPS;

#include <hiberlite/hiberlite.h>
extern hiberlite::Database *db;

extern int port;
extern std::string TEMPLATE_DIR;
extern std::string STATIC_ROOT;
extern std::string STATIC_DIR;
extern std::string BASE_DIR;
extern std::string root;
extern std::string name;
extern bool DEBUG;
#endif
