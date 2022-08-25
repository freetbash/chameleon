#include <chameleon/http/HttpRequest.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <sys/socket.h>

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
    send(this->nfd,msg.c_str(),strlen(msg.c_str()),0);
}
void HttpRequest::rm(){
    close(this->nfd);
    delete this;

}
std::string HttpRequest::read(){
    char data[MAX_SIZE];
    memset(data,0,sizeof(data));
    recv(this->nfd,data,sizeof(data),0);
    return data;
}
HttpRequest::~HttpRequest(){
    
}
