#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = nums.size()-1;
        for (int i = nums.size()-1; i>=0; i--){
            if (nums[i] + i>=maxReach) maxReach = i;
        }
        return maxReach == 0;
//        int maxReach = 0, i = 0;
//        while (i<nums.size() && i<=maxReach){
//            maxReach = max(maxReach, nums[i]+i);
//            i += 1;
//        }
//        return i == nums.size();
    }
};