#include <regex>
#include <string>
#include <iostream>
#include <map>
#include <vector>
bool check_http(std::string http_content);
std::string get_http_method(std::string http_content);
std::string get_http_path(std::string http_content);
std::map<std::string,std::string> get_http_headers(std::string http_content);
std::string get_http_body(std::string http_content);
