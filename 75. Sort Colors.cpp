#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void sortColors(vector<int>& nums){
        int count=nums.size(), i=0;
        while (count > 0){
            if (nums[i] == 0){
                nums.erase(nums.begin()+i);
                nums.insert(nums.begin(), 0);
                i ++;
            }
            else if (nums[i] == 1) i++;
            else if (nums[i] == 2){
                nums.erase(nums.begin()+i);
                nums.push_back(2);
            }
            count --;
        }
    }
};

//class Solution {
//public:
//    void sortColors(vector<int>& nums) {
//        int left=0, right = nums.size()-1, zero=0;
//        while (left <=right){
//            if (nums[left]==0) {
//                swap(nums[left], nums[zero]);
//                left ++;
//                zero ++;
//            }
//            else if (nums[left] == 1) left ++;
//            else {
//                swap(nums[left], nums[right]);
//                right --;}
//        }
//    }
//};

int main75(){
    Solution solution;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(0);

    vector<int> result;
    solution.sortColors(nums);
    return 0;
}