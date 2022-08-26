#include <chameleon/conf/vars.h>
MimeType mimetype;
HttpCode httpcode;

std::string SERVER="Server: Chameleon. by Freet";
std::string HTTP_VERSION="HTTP/1.1";
std::string HTTP_DELIM="\r\n";

UrlPatterns *url_patterns=new UrlPatterns;


HttpServer *server;

std::vector<App> INSTALLED_APPS;

hiberlite::Database *db=new hiberlite::Database;

bool DEBUG;
int port;
std::string TEMPLATE_DIR;
std::string STATIC_ROOT;
std::string STATIC_DIR;
std::string BASE_DIR;
std::string root;
std::string name;
