#include <iostream>

class Solution {
    public:
        bool isPalindrome(int x) {
            if(x < 0){
                return false;
            }

            int a = x;
            int b = 0;
            int c = 0;
            while(a / 10 != 0 || a % 10 != 0){
                b = a % 10;
                c = c * 10 + b;
                a /= 10;
            }

            return c == x;
        }
};

int main(void){
    Solution s;
    std::cout << s.isPalindrome(0) << std::endl;
    return 0;
}