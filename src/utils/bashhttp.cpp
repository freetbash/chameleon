#include <chameleon/utils/bashhttp.h>
bool check_http(std::string http_content){
    // (GET|HEAD|PUT|DELETE|CONNECT|OPTIONS|TRACE|PATCH|POST)(.+)HTTP
    std::string p("^(GET|HEAD|PUT|DELETE|CONNECT|OPTIONS|TRACE|PATCH|POST) (.*?) HTTP/(.*?)\\r\\n(.*?)");
    if(std::regex_search(http_content,std::regex(p))){
        return true;
    }else{
        return false;
    }
}
std::string get_http_method(std::string http_content){
    std::regex rp("^(GET|HEAD|PUT|DELETE|CONNECT|OPTIONS|TRACE|PATCH|POST)");
    std::smatch m;
    if(std::regex_search(http_content,m,rp)){
        return m.str();
    }else{
        return std::string("");
    }

}
std::string get_http_path(std::string http_content){
    std::regex rp("^(GET|HEAD|PUT|DELETE|CONNECT|OPTIONS|TRACE|PATCH|POST) (.*?) HTTP/");
    std::smatch m;
    if(std::regex_search(http_content,m,rp)){
        return m.str(2);
    }else{
        return std::string("");
    }

}
std::map<std::string,std::string> get_http_headers(std::string http_content){
    std::map<std::string,std::string> headers;
    std::regex r1("\\n(.*?)\\r");
    std::regex r2("(.*?)(: )(.*+)");
    std::smatch result;
    std::string temp;
    std::string::const_iterator iterStart = http_content.begin();
    std::string::const_iterator iterEnd   = http_content.end();
    while(std::regex_search(iterStart,iterEnd,result,r1)){
        temp=result.str(1);
        iterStart=result[0].second;
        if(std::regex_search(temp,result,r2)){
            headers.insert(std::pair<std::string,std::string>(result.str(1),result.str(3)));
        }
    }
    return headers;



}
std::string get_http_body(std::string http_content){
    std::regex rp("(\\r\\n\\r\\n)(.*+)");
    std::smatch m;
    if(std::regex_search(http_content,m,rp)){
        return m.str(2);
    }else{
        return std::string("");
    }


}
