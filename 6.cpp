#include <iostream>
#include <string>
#include <vector>

enum Direction {
    Down,
    RampUp
};

class Solution {
    public:
        std::string convert(std::string s, int numRows) {
            if(numRows <= 1 ){
                return s;
            }
            if(s.size() <= 1){
                return s;
            }

            std::vector<std::vector<char>> vs;
            for(int i = 0; i < numRows; ++i){
                vs.push_back(std::vector<char>());
            }

            int length = s.size();
            int prevX = 0;
            int prevY = 0;
            int direction = Direction::Down;
            vs[prevY].push_back(s[0]);
            for(int index = 1; index < length; ++index){
                if(prevY == 0){
                    direction = Direction::Down;
                }
                if(prevY == numRows - 1){
                    direction = Direction::RampUp;
                }

                switch(direction){
                    case Direction::Down: {
                        ++prevY;
                    }break;
                    case Direction::RampUp: {
                        ++prevX;
                        --prevY;
                    }break;
                    default: {

                    }break;
                }

                vs[prevY].push_back(s[index]);
            }

            std::string result = "";
            for(auto i: vs){
                for(auto j: i){
                    result.append(1, j);
                }
            }
            return result;
        }
};

int main(void){
    Solution s;
    std::string str = "PAYPALISHIRING";
    auto x = s.convert(str, 4);
    std::cout << x << std::endl;
    return 0;
}