#include <chameleon/http/HttpRequest.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <sys/socket.h>

#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <chameleon/conf/vars.h>
#include <chameleon/utils/tools.h>




HttpRequest::HttpRequest(){
    
}
HttpRequest *NewHttpRequest(HttpServer *server){
    HttpRequest *request = new HttpRequest;
    sockaddr_in temp_addr;
    socklen_t cl;
    // 这里阻塞
    request->bad=false;
    request->nfd = accept(server->nfd,(sockaddr *)&temp_addr,&cl);
    request->ip = inet_ntoa(temp_addr.sin_addr);
    return request;
}



void HttpRequest::write(std::string msg){
    signal(SIGPIPE,SIG_IGN);
    send(this->nfd,msg.c_str(),strlen(msg.c_str()),MSG_NOSIGNAL);
}
void HttpRequest::rm(){
    close(this->nfd);

}
std::string HttpRequest::read(){
    char data[MAX_SIZE];
    memset(data,0,sizeof(data));
    recv(this->nfd,data,sizeof(data),0);
    return data;
}
HttpRequest::~HttpRequest(){
    
}

void HttpRequest::handle_http_data(){
    if(this->method=="GET"){
        std::vector<std::string> data = single_split(this->path,"?");
        if(data.size()>1){
            data.erase(data.begin());
            std::string temp;
            for(std::string each :data){
                temp+=each;
            }
            data = single_split(temp,"&");
            for(std::string each :data){
                std::vector<std::string> _ = single_split(each,"=");
                if(_.size()==2){
                    this->_GET.insert(std::pair<std::string,std::string>(_[0],_[1]));
                }
            }
        }
    
    }else if(this->method == "POST"){
        std::vector<std::string> data = single_split(this->body,"&");
        for(std::string each :data){
            std::vector<std::string> _ = single_split(each,"=");
                if(_.size()==2){
                    this->_POST.insert(std::pair<std::string,std::string>(_[0],_[1]));
                }
        }
    }
}


std::string HttpRequest::GET(std::string key){
    if(this->_GET.count(key)==1){
        return this->_GET[key];
    }else{
        return "GET has no key is "+key;
    }
}
std::string HttpRequest::POST(std::string key){
    if(this->_POST.count(key)==1){
        return this->_POST[key];
    }else{
        return "POST has no key is "+key;
    }
}