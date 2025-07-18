#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

int countingOnesInNum(const int num){
    std::string numsStr = std::to_string(num);
    int counter = 0;
    for(char s : numsStr){
        if(s == '1'){
            counter++;
        }
    }

    return counter;
}

bool isPalindrome(const std::string str){
    for(int i = 0; i < str.size() / 2; i++){
        if(str[i] != str[str.size() - i - 1]){
            return false;
        }
    }
    return true;
}

int findSecondBiggest(const std::vector<int>& nums) {
    if (nums.size() < 2) {
        throw std::invalid_argument("Not enough elements.");
    }

    int max = INT_MIN, second = INT_MIN;

    for (int num : nums) {
        if (num > max) {
            second = max;
            max = num;
        } else if (num > second && num != max) {
            second = num;
        }
    }

    if (second == INT_MIN) {
        throw std::runtime_error("All elements are equal.");
    }

    return second;
}


int main(){

    int num = 112341;
    std::cout << countingOnesInNum(num) << std::endl;


    std::string str = "abccba";
    if(isPalindrome(str)){
        std::cout << "str is palindrome" << std::endl;
    } else {
        std::cout << "str is not palindrome" << std::endl;
    }


    std::vector<int> nums = {1,2,10,34,4,-9,17};
    std::cout << findSecondBiggest(nums) << std::endl;


}