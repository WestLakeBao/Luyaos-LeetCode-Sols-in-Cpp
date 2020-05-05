#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        for (int j=0; j<nums.size(); j++){ // this is a lot fast than for (auto num: nums)
            if (nums[j]!=0) {
                nums[i] = nums[j];
                i ++;
            }
        }
        for (int k=i;k<nums.size(); k++) nums[k] = 0;
    }
};