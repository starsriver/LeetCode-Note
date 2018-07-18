#include <iostream>
#include <string>

class Solution {
    public:
        int myAtoi(std::string str) {
            size_t length = str.size();
            if(length <= 0){
                return 0;
            }

            int i = 0;
            
            int64_t arr[11];
            int j = 0;
            int flag = 1;

            while(i < length && str[i] == ' '){
                ++i;
            }
            if(i >= length){
                return 0;
            }

            if(!isNumber(str[i]) && !isFlag(str[i])){
                return 0;
            }

            if(isFlag(str[i])){
                flag = (str[i] == '-' ? -1 : 1);
                ++i;
            }

            if(i >= length || !isNumber(str[i])){
                return 0;
            }

            int64_t k = 1;
            int64_t result = 0;

            for(;i < length; ++i){
                if(isNumber(str[i])){
                    int num = str[i] - 48;
                    if(num == 0 && j == 0){
                        continue;
                    }
                    else{
                        arr[j] = num;
                        ++j;
                    }

                    if(j >= 11){
                        return flag != -1 ? INT32_MAX : INT32_MIN;
                    }
                }
                else{
                    break;
                }
            }

            --j;
            while(j >= 0){
                result += arr[j] * k;
                k *= 10;
                --j;
            }
            
            result *= flag;

            if(result > INT32_MAX){
                return INT32_MAX;
            }

            if(result < INT32_MIN){
                return INT32_MIN;
            }
            return result;
        }

        bool isNumber(char c){
            return c >= 48 && c <= 57;
        }

        bool isFlag(char c){
            return c == '-' || c == '+';
        }
};

int main(void)
{
    Solution s;
    std::cout << s.myAtoi("-6147483648") << std::endl;
    return 0;
}
