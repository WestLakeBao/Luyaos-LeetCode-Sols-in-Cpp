#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left_product=1, right_product=1;
        vector<int> result(nums.size(), 1);
        for (int i=0; i<nums.size(); i++){
            result[i] *= left_product;
            left_product *= nums[i];
            result[nums.size()-1-i] *= right_product;
            right_product *= nums[nums.size()-1-i];
        }
        return result;
    }
};