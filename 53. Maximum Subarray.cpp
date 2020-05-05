#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int sumx = nums[0], max_sum = nums[0];
        for (int i=1; i<nums.size(); i++){
            if (nums[i]>nums[i]+sumx) sumx = nums[i];
            else sumx += nums[i];
            if (sumx>max_sum) max_sum = sumx;
//            sumx = max(sumx+nums[i], nums[i]);
//            max_sum = max(sumx, max_sum);
        }
        return max_sum;
    }
};