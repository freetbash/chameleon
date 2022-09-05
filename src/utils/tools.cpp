#include <chameleon/utils/tools.h>
// tools
#include <regex>
#include <fstream>
#include <iostream>
std::vector<std::string> ls(std::string path){
    DIR *dp;
    std::vector<std::string> dirs;
    struct dirent *dirp;

    if(
        (dp=opendir(path.c_str())) == NULL)
    {
        log(path);
        std::cout << "[-]List files failed . \n[-]Please check your permissions. "<<std::endl;
        exit(-2);
    }

    while (
        ((dirp=readdir(dp))!=NULL)
    )
    {
        if(
            (dirp->d_name != std::string(".") and dirp->d_name != std::string(".."))
        ){
            dirs.push_back(dirp->d_name);
        }
    }
    closedir(dp);
    return dirs;
}

void c_mkdir(std::string path){
    mkdir(path.c_str(),0775);
}

void check_error(int status){
    if(status<0){
        std::cout<<"[-] "<<strerror(errno)<<std::endl;
        exit(-99);
    }
}

void log(std::string msg){
    std::cout<<msg<<std::endl;
}




bool FileExists(std::string path)
{
    struct stat fileStat; 
    if ( stat(path.c_str(), &fileStat) )
    {
        return false;
    }
    if ( !S_ISREG(fileStat.st_mode) )
    {
        return false;
    }
    return true;
}

bool DirExists(std::string path)
{
    struct stat fileStat;
    if ( stat(path.c_str(), &fileStat) )
    {
        return false;
    }
    if ( !S_ISDIR(fileStat.st_mode) )
    {
        return false;
    }
    return true;
}

std::vector<std::string> split(std::string s, std::string d) { 
	std::string text = s;
	std::regex ws_re(d); 
	// whitespace 
	std::vector<std::string> tokens(std::sregex_token_iterator(text.begin(), text.end(), ws_re, -1), std::sregex_token_iterator()); 
	return tokens;
}
std::vector<std::string> readlines_fromfile(std::string file_path){
    std::vector<std::string> temp;
    std::string query;
    std::ifstream _in(file_path);
    while (getline(_in,query))
    {
        temp.push_back(query);
    }
    return temp;
}

std::string replace_all_distinct(std::string str, const std::string old_value, const std::string new_value){
    std::string temp = str;
    for(std::string::size_type pos(0); pos!=std::string::npos; pos+=new_value.length()) {
        if( (pos=temp.find(old_value,pos))!=std::string::npos ){
            temp.replace(pos,old_value.length(),new_value);
        }else{
            break;
        }
    
    }
    return temp;
}

long long int file_size(std::string path)
{
    struct stat statbuf;
    stat(path.c_str(),&statbuf);
    long long int size=statbuf.st_size;

    return size;
}
#include <sstream>
std::string ltos(long l)  
{  
    std::ostringstream os;  
    os<<l;  
    std::string result;  
    std::istringstream is(os.str());  
    is>>result;  
    return result;  
}  



std::string get_file_lastmodified(std::string file_path){

    struct stat buf;
    int result;
    result =stat(file_path.c_str(), &buf );
    tm* gmt = gmtime(&buf.st_mtime);
    const char* fmt = "%a, %d %b %Y %H:%M:%S GMT";
    char tstr[30];
    strftime(tstr, sizeof(tstr), fmt, gmt);
    return tstr;
}