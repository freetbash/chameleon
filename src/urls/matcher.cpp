#include <chameleon/urls/urls.h>
#include <chameleon/http/HttpResponse.h>
#include <vector>
#include <chameleon/views/views.h>
#include <chameleon/utils/tools.h>
#include <chameleon/conf/vars.h>
#include <string>
#include <map>
#include <regex>
void UrlPatterns::match(HttpRequest *request){
    
    std::string mode = contain(request,url_patterns);
    void *fuck = url_patterns->patterns[mode];
    ((void (*)(HttpRequest *))fuck)(request);


}

std::string contain(HttpRequest *request, UrlPatterns *url_patterns){
    std::smatch results;
    std::vector<std::string> keys;
    std::vector<std::string> values;
    std::vector<std::string> temp;
    std::string mode;
    std::string path;
    std::vector<std::string> _ = single_split(request->path,"?");
    if(_.size()>1){
        path=_[0];
    }else{
        path= request->path; //"/asec/<asdasd>/<name>/<id>/";// --> /asec/(.*?)/(.*?)             /asec/qwexqwc/2
    }   
                              // url path /asec/<name>  -> /asec/(.*?)
    for (auto _ : url_patterns->patterns){
        temp.clear();
        std::string mode = _.first;
        std::string ts = _.first;
        if(std::regex_match(path,std::regex(mode))){
            return mode;
        }
        std::regex rp("<(.*?)>");
        if(std::regex_search(mode,results,rp)){
            std::string::const_iterator iterStart = mode.begin();
            std::string::const_iterator iterEnd   = mode.end();
            while(std::regex_search(iterStart,iterEnd,results,rp)){
                keys.push_back(results.str(1));
                iterStart=results[0].second;
                temp.push_back(results.str());
            }
            for(std::string __:temp){
                ts= std::regex_replace(ts,std::regex(__),"(.*?)");
            }
            
            if(std::regex_match(path,results,std::regex(ts))){
                for(int i=1;i<results.size();i++){
                    values.push_back(results.str(i));
                }

                for(int i=0;i<keys.size();i++){
                    request->path_data[keys[i]]=values[i];
                }

                return mode;
            }
    
        }
    }
        return std::string("/chameleon_not_found");
}
