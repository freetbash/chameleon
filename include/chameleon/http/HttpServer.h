#ifndef CHAMELEON_HTTP_SERVER
#define CHAMELEON_HTTP_SERVER
#include <pthread.h>
#include <queue>
class HttpRequest;

class HttpServer{
public:
    int nfd;
    int port;
    struct sockaddr_in *addr;
    std::vector<pthread_t> threads;



    static HttpServer *build(int port);
    void Receiver();
};



#endif