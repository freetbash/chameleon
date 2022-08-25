
#include <chameleon/http/HttpRequest.h>
#include <chameleon/http/HttpResponse.h>
#include <chameleon/views/views.h>

void FileResponse(HttpRequest *request,std::string file_path, std::string status_code){
    if(FileExists(file_path)){
        std::string size = ltos(file_size(file_path));
        std::string filetype = mimetype.find(split(file_path,"\\.").back());
        
        std::string head=(
            HTTP_VERSION + " 200 "+httpcode.find("200")+HTTP_DELIM
        // headers
            +SERVER+HTTP_DELIM
            +"Content-type: "+filetype+HTTP_DELIM
            +"Content-Length: "+size+HTTP_DELIM
            +"Date: "+http_gmtime()+HTTP_DELIM
            +HTTP_DELIM
        );
        request->write(head);
        char buffer[1024];
        FILE *fp = fopen(file_path.c_str(), "r");  
            bzero(buffer, 1024);  
            int file_block_length = 0;  
            while( (file_block_length = fread(buffer, sizeof(char), 1024, fp)) > 0){
                send(request->nfd, buffer, file_block_length, 0);
            }
            bzero(buffer, sizeof(buffer)); 
            fclose(fp);
        log(" ["+request->method+"] "+request->ip+" ------------------><200>("+request->path+")| "+filetype);
        request->rm();
    }else{
        Views::notfound(request);
    }

    
}
