#include <vector>

using namespace std;

// this solution is very slow
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        while (left<right){
            int mid_left=(left+right)/2, mid_right=mid_left+1;
            if (nums[mid_left]<nums[mid_right]) left=mid_right;
            else right=mid_left;
        }
        return left;
    }
};

int main162(){
    Solution solution;
    vector<int> nums{1,2,3,1};
    int result;
    result=solution.findPeakElement(nums);
    return 0;
}