#include <vector>

using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minTemp=nums[0], maxTemp=nums[0], MAX=nums[0];
        for (int i=1; i<nums.size(); i++){
            int temp_min = minTemp*nums[i], temp_max=maxTemp*nums[i];
            minTemp = min(nums[i], min(temp_min, temp_max));
            maxTemp = max(nums[i], max(temp_min, temp_max));
            MAX = max(MAX, maxTemp);
        }
        return MAX;
    }
};

int main152(){
    Solution solution;
    vector<int> nums{2, 3, -2, 4};
    int result;
    result = solution.maxProduct(nums);
    return 0;
}