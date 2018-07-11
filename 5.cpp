#include <iostream>
#include <string>

class Solution {
    public:
        std::string longestPalindrome(std::string s) {
            size_t length = s.size();
            if(length <= 1){
                return s;
            }
            int maxBegin = 0;
            int maxEnd = 1;
            for(int i = 0; i < length; ++i){
                // even Palindrome
                int begin = i;
                int end = i + 2;
                while(begin >= 0 && end <= length && s[begin] == s[end - 1]){
                    --begin;
                    ++end;
                }
                ++begin;
                --end;
                if(end - begin > maxEnd - maxBegin){
                    maxBegin = begin;
                    maxEnd = end;
                }

                // odd Palindrome
                begin = i - 1;
                end = i + 2;
                while(begin >= 0 && end <= length && s[begin] == s[end - 1]){
                    --begin;
                    ++end;
                }
                ++begin;
                --end;
                if(end - begin > maxEnd - maxBegin){
                    maxBegin = begin;
                    maxEnd = end;
                }
            }
            return s.substr(maxBegin, maxEnd - maxBegin);
        }
};

int main(void){
    Solution s;
    std::string str = "ccc";

    std::string result = s.longestPalindrome(str);
    std::cout << result << std::endl;
    
    return 0;
}