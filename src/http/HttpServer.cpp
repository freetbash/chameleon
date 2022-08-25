#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <chameleon/utils/tools.h>
#include <chameleon/http/HttpServer.h>
#include <chameleon/http/HttpRequest.h>
#include <chameleon/conf/vars.h>
#include <chameleon/http/parser.h>
#include <chameleon/urls/urls.h>
#include <chameleon/views/views.h> // 也许重复包含 但可能不会

void *HandleRequest(void *request);

HttpServer *HttpServer::build(int port){
    HttpServer *temp = new HttpServer;
    temp->port = port;
    temp->nfd = socket(AF_INET,SOCK_STREAM, 0);
    temp->addr = new sockaddr_in;
    temp->addr->sin_family=AF_INET;
    temp->addr->sin_port=htons(port);
    temp->addr->sin_addr.s_addr=INADDR_ANY;
        int sock, ret, on; on = 1; 
        ret = setsockopt(temp->nfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on) ); 
    bind(temp->nfd,(struct sockaddr *)temp->addr,sizeof(struct sockaddr));
    listen(temp->nfd,MAX_CLIENTS);
    log(
        color("[*]Start Chameleon at http://0.0.0.0:"+std::to_string(port)+"/chameleon",BLUE)
    );
    return temp;
}

void HttpServer::Receiver(){
    for(;;){
        pthread_t temp;
        HttpRequest *request = NewHttpRequest(server);
        pthread_create(&temp,NULL,HandleRequest,(void *)request);
        pthread_detach(temp);
        this->threads.push_back(temp);
    }
}

void *HandleRequest(void *request){
    parser((HttpRequest *)request);
    UrlPatterns::match((HttpRequest *)request);
}
