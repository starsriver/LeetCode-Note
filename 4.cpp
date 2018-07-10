#include <iostream>
#include <vector>

class Solution {
    public:
        double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
            int length1 = nums1.size();
            int length2 = nums2.size();
            int setp = (length1 + length2) / 2;
            int helf = (length1 + length2) % 2;
            int* array = new int[setp + 1];
            int i = 0;
            std::vector<int>::iterator nums1Index = nums1.begin();
            std::vector<int>::iterator nums2Index = nums2.begin();
            while(i < setp + 1){
                bool nums1IsEnd = nums1Index == nums1.end();
                bool nums2IsEnd = nums2Index == nums2.end();
                if(!nums1IsEnd && !nums2IsEnd){
                    if(*nums1Index < *nums2Index){
                        *(array + i) = *nums1Index;
                        ++i;
                        ++nums1Index;
                    }
                    else{
                        *(array + i) = *nums2Index;
                        ++i;
                        ++nums2Index;
                    }
                }
                else if(nums1IsEnd && !nums2IsEnd){
                    *(array + i) = *nums2Index;
                    ++i;
                    ++nums2Index;
                }
                else if(!nums1IsEnd && nums2IsEnd){
                    *(array + i) = *nums1Index;
                    ++i;
                    ++nums1Index;
                }
                else{
                    break;
                }
            }
            double result = 0;
            if(helf == 0){
                result = (*(array + setp - 1) + *(array + setp)) / 2.0;
            }
            else{
                result = *(array + setp);
            }
            return result;
        }
};

int main(void){
    std::vector<int> nums1({1, 3});
    std::vector<int> nums2({2, 4});
    Solution s;

    double result = s.findMedianSortedArrays(nums1, nums2);
    std::cout << result << std::endl;
    // Solution s;
    return 0;
}