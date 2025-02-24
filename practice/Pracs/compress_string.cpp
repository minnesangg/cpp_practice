#include<string>
#include<iostream>

std::string compress_string(const std::string& str){
    if (str.empty()) return "string is empty";

    std::string compressed_str;
    int count = 1;

    for(size_t i = 1; i < str.size(); i++){
        if(str[i] == str[i-1]){
            count++;
        } else {
            compressed_str += str[i-1];
            if(count > 1){
                compressed_str += std::to_string(count);
                count = 1;
            }
        }
    }

    compressed_str += str.back();
    if(count > 1){
        compressed_str += std::to_string(count);
    }
    return compressed_str;
}

int main(){
    std::string str = "aabcccccaaa";
    std::cout << compress_string(str) << std::endl;
    return 0;
}