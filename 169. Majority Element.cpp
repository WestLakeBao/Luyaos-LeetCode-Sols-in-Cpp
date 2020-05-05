// using of count: Input iterators to the initial and final positions of the sequence of elements.
// The range used is [first,last), which contains all the elements between first and last,
// including the element pointed by first but not the element pointed by last.

// condition ? result_if_true : result_if_false
#include <vector>

using namespace std;

class Solution {
public:
    // Solution 1: divide & conquer
    int majorityElement(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }

    int helper(vector<int>& nums, int left, int right){
        if (left>right) return NULL;
        if (left==right) return nums[left];
        int left_majortiy=helper(nums, left, (left+right)/2);
        int right_majority=helper(nums, (left+right)/2+1, right);
        if (left_majortiy==right_majority) return left_majortiy;
        return count(nums.begin()+left, nums.begin()+right+1, left_majortiy)
               > count(nums.begin()+left, nums.begin()+right+1, right_majority) ? left_majortiy : right_majority;
    }

    // Solution 2: tricky
    int majorityElement2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};