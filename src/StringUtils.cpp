#include "StringUtils.h"

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    ssize_t length = str.length(); //length
    if (start < 0) {//negative
    start = length + start;
    }
    if (end <= 0) {
    end = length + end;
    }
    if (start < 0){
        start = 0;
        } 
    if (end > length) {
        end = length;
        };//oversize
    if (start >= end) {
        return ""; 
        }
    return str.substr(start, end - start);;
}

std::string Capitalize(const std::string &str) noexcept{
    if(str.empty()){//empry
        return"";
    }
    std::string result = str;//stroe
    result[0] = std::toupper(result[0]);//first
    for(size_t i = 1; i < result.length();i++){//other
        result[i] = std::tolower(result[i]);
    }

    return result;
}

std::string Upper(const std::string &str) noexcept{
    if(str.empty()){
        return"";
    }
    std::string result = str;
    for(size_t i = 0; i<result.length();i++){
        result[i]= std::toupper(result[i]);
    }
    return result;
}

std::string Lower(const std::string &str) noexcept{
    if(str.empty()){
        return"";
    }
    std::string result = str;
    for(size_t i = 0; i<result.length();i++){
        result[i]= std::tolower(result[i]);
    }
    return result;
}

std::string LStrip(const std::string &str) noexcept{
    size_t start = 0;
    while(start < str.length() && std::isspace(str[start])){
        start++;
    }
    return str.substr(start);
}

std::string RStrip(const std::string &str) noexcept{
    size_t end = str.length();
    while(end >0 && std::isspace(str[end-1])){//oversize
        end--;
    }
    return str.substr(0,end);
}

std::string Strip(const std::string &str) noexcept{
    std::string result;
   for (size_t i = 0; i < str.length(); i++) {
    char current = str[i];
    if (!std::isspace(current)) {
        result += current;//connect all
    }
}
    return result;
}

std::string Center(const std::string &str, int width, char fill) noexcept{
 int length = str.length();
 if(width <= length){
    return str;
 }
 int x = width - length;
 int leftx = x/2;
 int rightx = x - x/2;
return std::string(leftx, fill) + str + std::string(rightx, fill);
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
 int length = str.length();
 if(width <= length){
    return str;
 }
 int x = width - length;
return std::string(x, fill) + str;
}

std::string LJust(const std::string &str, int width, char fill) noexcept{//i change the order because I just figure out my return is wrong and I am lazy to fix the return hahaha
 int length = str.length();
 if(width <= length){
    return str;
 }
 int x = width - length;
return str+std::string(x, fill);
    return "";
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
std::string result = str;
size_t length = old.length();
for(size_t i = 0; i < str.length();){
    if(str.substr(i,length)==old){
        result += rep;
        i+=length;
    }else{
        result += str[i];
        i++;
    }
}
    return result;
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
std::vector< std::string > result;
size_t length = splt.length();
size_t start = 0;
if (length == 0) {//empty
    result.push_back(str);
    return result;
}
   while (true) {
        size_t find = str.find(splt, start);
        if (find == std::string::npos) {
            result.push_back(str.substr(start));
            break;
        }
        result.push_back(str.substr(start, find - start));
        start = find + length;
    }
    return result;
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
std::string result = vect[0];
for (size_t i = 1; i < vect.size(); i++) {
        result += str;
        result += vect[i];
    }
    return result;
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
std::string result;
size_t start = 0;
size_t t = 0;
    while (t = str.find('\t', start) != std::string::npos) {
        result += str.substr(start, t - start);
        result += std::string(tabsize, ' ');
        start = t + 1;
    }
    result += str.substr(start);
    return result;
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    // Replace code here
    return 0;
}
}
