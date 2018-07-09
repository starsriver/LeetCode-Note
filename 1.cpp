#include "iostream"
#include "vector"

class Solution{
    public:
        Solution() = default;
        std::vector<int> twoSum(std::vector<int>& nums, int target){
            std::vector<int> result;
            for(int i = 0; i < nums.size() - 1; i++){
                for(int j = i + 1; j < nums.size(); j++){
                    if(nums[i] + nums[j] == target){
                        return result = {i, j};
                    }
                }
            }
            return result;
        }
};

int main(void){
    Solution s;
    std::vector<int> v = {1, 2, 3, 4};
    std::vector<int> r = s.twoSum(v, 5);
    std::cout << r.at(0) << "," << r.at(1) << std::endl;
}