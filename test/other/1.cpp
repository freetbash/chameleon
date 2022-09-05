#include <ctime>
#include <string>
#include <iostream>

std::string http_gmtime() {
        time_t now = time(0);
        tm* gmt = gmtime(&now);

        // http://en.cppreference.com/w/c/chrono/strftime
        // e.g.: Sat, 22 Aug 2015 11:48:50 GMT
        //       5+   3+4+   5+   9+       3   = 29
        const char* fmt = "%a, %d %b %Y %H:%M:%S GMT";
        char tstr[30];

        strftime(tstr, sizeof(tstr), fmt, gmt);

        return tstr;
}


#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
int main( void ){
    struct stat buf;
    int result;
    result =stat( "./yuan_jiang.txt", &buf );
    if( result != 0 ){
        perror( "显示文件状态信息出错" );//并提示出错的原因，如No such file or directory（无此文件或索引）
    }else{
        tm* gmt = gmtime(&buf.st_mtime);
        const char* fmt = "%a, %d %b %Y %H:%M:%S GMT";
        char tstr[30];

        strftime(tstr, sizeof(tstr), fmt, gmt);

        printf("最后修改日期: %s", tstr);
}
}
