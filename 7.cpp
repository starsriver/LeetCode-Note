#include <iostream>

class Solution {
    public:
        int reverse(int64_t x) {
            if(x > INT32_MAX || x < INT32_MIN){
                return 0;
            }
            int64_t result  = 0;
            int flag = 1;
            if(x < 0){
                flag = -1;
                x = -x;
            }
            int64_t i = 1000000000;
            int64_t ii = 1;
            while(i > 0){
                int64_t s = x / i;
                int64_t y = x % i;
                if(s != 0){
                    result += s * ii;
                    ii *= 10;

                    while(y < i / 10){
                        ii *= 10;
                        i /= 10;
                    }
                }
                x = y;
                i /= 10;
            }
            
            if(result > INT32_MAX || result < INT32_MIN){
                return 0;
            }
            return (int)result * flag;
        }
};

int main(void){
    Solution s;
    int x = s.reverse(2147483648);
    std::cout << x << std::endl;
    return 0;
}