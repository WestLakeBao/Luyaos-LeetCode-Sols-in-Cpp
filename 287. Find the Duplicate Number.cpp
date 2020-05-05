// Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive)
// DO NOT MODIFY THE INPUT ARRAY
#include <vector>

using namespace std;

class Solution {
public:
    // SOLUTION 1: TWO POINTERS
    int findDuplicate(vector<int>& nums) {
        int fast=0, slow = 0;
        fast = nums[nums[fast]];
        slow = nums[slow];
        while (fast != slow){
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        int head = 0;
        while (slow != head){
            slow = nums[slow];
            head = nums[head];
        }
        return slow;
    }
    // Solution 2: cyclic sort (not valid for this question, as it require array modification)
//    int findDuplicate(vector<int>& nums) {
//        int i=0;
//        while (i<nums.size()) {
//            if (nums[i] != i + 1) {
//                int j = nums[i] - 1;
//                if (nums[i] != nums[j]) swap(nums[i], nums[j]);
//                else return nums[i];
//            }
//            else i++;
//        }
//        return -1;
//    }
};

int main287(){
    Solution solution;
    vector<int> nums{1,3,4,2,2};
    int result=solution.findDuplicate(nums);
    return 0;
}