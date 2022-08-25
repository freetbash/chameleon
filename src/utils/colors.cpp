#include <chameleon/utils/colors.h>

std::string color(std::string text, std::string color){
    std::string fuck_string = "\033["+color+text+"\033[0m";
    return fuck_string;
}