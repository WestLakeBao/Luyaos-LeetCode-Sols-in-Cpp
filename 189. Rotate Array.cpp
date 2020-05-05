#include <vector>

using namespace std;

class Solution {
public:
    // solution 1: in-place reverse
    void rotate1(vector<int>& nums, int k) {
        k%=nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
    // solution 2 (very slow)
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        while (k>0){
            auto temp = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), temp);
            k--;
        }
    }
};