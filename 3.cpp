#include <iostream>
#include <string>
#include <list>
#include <map>
#include <utility>

class Solution {
    public:
        int lengthOfLongestSubstring(std::string s) {
            int lenghth = s.length();
            if(lenghth <= 1){
                return lenghth;
            }

            std::list<char> l;
            std::map<char, int> m;

            l.push_front(s[0]);
            m.insert(std::pair<char, int>(s[0], 1));

            int maxLength = 0;

            for(int i = 1; i < lenghth; ++i){
                char c = s[i];
                std::map<char, int>::iterator findIndex = m.find(c);
                if(findIndex == m.end()){
                    l.push_back(c);
                    m.insert(std::pair<char, int>(c, 1));
                }
                else if(findIndex != m.end() && m[c] == 0){
                    l.push_back(c);
                    m[c] = 1;
                }
                else{
                    if(maxLength < l.size()){
                        maxLength = l.size();
                    }

                    char head = l.front();
                    while(head != c){
                        l.pop_front();
                        --m[head];

                        head = l.front();
                    }
                    l.pop_front();
                    // --m[c];

                    l.push_back(c);
                    // ++m[c];
                }
            }

            return maxLength > l.size() ? maxLength : l.size();
        }
};

int main(void){

    Solution s;
    std::cout << s.lengthOfLongestSubstring("obzybovnhlewcxhtbuoe");

    return 0;
}