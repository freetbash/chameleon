#include <chameleon/urls/urls.h>

UrlPatterns *const UrlPatterns::path(std::string path,void *fuck){
    this->patterns.insert(
        std::pair<std::string,void *>(path,fuck)
    );
    return this;
}