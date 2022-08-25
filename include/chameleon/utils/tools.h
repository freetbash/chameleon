#ifndef _CHAMELEON_TOOLS__H
#define _CHAMELEON_TOOLS__H
#include <string>
#include <errno.h>
#include <sys/stat.h> 
#include <sys/types.h>
#include <chameleon/utils/colors.h>
#include <vector>

#ifndef CCAO_TOOLS_TOOLS
#define CCAO_TOOLS_TOOLS
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/stat.h> 
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include <dirent.h>
#include <chameleon/utils/colors.h>
// tools
void c_mkdir(std::string path);
void check_error(int status);
void log(std::string msg);
long long int file_size(std::string path);
std::vector<std::string> ls(std::string path);
std::vector<std::string> readlines_fromfile(std::string file_path);// here !
std::string ltos(long l);
bool FileExists(std::string path);
bool DirExists(std::string path);
std::vector<std::string> split(std::string str, std::string pattern);
std::string replace_all_distinct(std::string str, const std::string old_value, const std::string new_value);
#endif
#endif