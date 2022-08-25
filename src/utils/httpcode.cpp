#include <chameleon/utils/httpcode.h>


std::string HttpCode::find(std::string code){
    std::string temp;
    temp = this->data[code];

    if(temp.empty()){
        return "no status";
    }
    return temp;
}
HttpCode::HttpCode(){
    this->data["100"]="Continue";
    this->data["101"]="Switching Protocols";
    this->data["102"]="Processing";
    this->data["103"]="Early Hints";
    this->data["200"]="OK";
    this->data["201"]="Created";
    this->data["202"]="Accepted";
    this->data["203"]="Non-Authoritative Information";
    this->data["204"]="No Content";
    this->data["205"]="Reset Content";
    this->data["206"]="Partial Content";
    this->data["207"]="Multi-Status";
    this->data["208"]="Already Reported";
    this->data["226"]="IM Used";
    this->data["300"]="Multiple Choices";
    this->data["301"]="Moved Permanently";
    this->data["302"]="Found";
    this->data["303"]="See Other";
    this->data["304"]="Not Modified";
    this->data["305"]="Use Proxy";
    this->data["307"]="Temporary Redirect";
    this->data["308"]="Permanent Redirect";
    this->data["400"]="Bad Request";
    this->data["401"]="Unauthorized";
    this->data["402"]="Payment Required";
    this->data["403"]="Forbidden";
    this->data["404"]="Not Found";
    this->data["405"]="Method Not Allowed";
    this->data["406"]="Not Acceptable";
    this->data["407"]="Proxy Authentication Required";
    this->data["408"]="Request Timeout";
    this->data["409"]="Conflict";
    this->data["410"]="Gone";
    this->data["411"]="Length Required";
    this->data["412"]="Precondition Failed";
    this->data["413"]="Request Entity Too Large";
    this->data["414"]="Request-URI Too Long";
    this->data["415"]="Unsupported Media Type";
    this->data["416"]="Requested Range Not Satisfiable";
    this->data["417"]="Expectation Failed";
    this->data["418"]="I'm a Teapot";
    this->data["421"]="Misdirected Request";
    this->data["422"]="Unprocessable Entity";
    this->data["423"]="Locked";
    this->data["424"]="Failed Dependency";
    this->data["425"]="Too Early";
    this->data["426"]="Upgrade Required";
    this->data["428"]="Precondition Required";
    this->data["429"]="Too Many Requests";
    this->data["431"]="Request Header Fields Too Large";
    this->data["451"]="Unavailable For Legal Reasons";
    this->data["500"]="Internal Server Error";
    this->data["501"]="Not Implemented";
    this->data["502"]="Bad Gateway";
    this->data["503"]="Service Unavailable";
    this->data["504"]="Gateway Timeout";
    this->data["505"]="HTTP Version Not Supported";
    this->data["506"]="Variant Also Negotiates";
    this->data["507"]="Insufficient Storage";
    this->data["508"]="Loop Detected";
    this->data["510"]="Not Extended";
    this->data["511"]="Network Authentication Required";
}