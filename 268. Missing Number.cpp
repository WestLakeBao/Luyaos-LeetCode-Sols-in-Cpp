#include <vector>

using namespace std;

class Solution {
public:
    // solution 1: cyclic sort 17% & 5%
    int missingNumber1(vector<int>& nums) {
        int i = 0;
        while (i<nums.size()){
            int j = nums[i];
            if (j<nums.size()-1 && nums[j] != nums[i]) swap(nums[i], nums[j]);
            else i++;
        }
        for(int j=0; j<nums.size(); j++){
            if (nums[j] != j) return j;
        }
        return nums.size();
    }

    // solution 2: XOR 14% & 5%
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        for (int i=0; i<nums.size(); i++) result ^= nums[i] ^i;
        return result;
    }
};

int main268(){
    vector<int> nums={3,0,1};
    int result=Solution().missingNumber(nums);
    return 0;
}