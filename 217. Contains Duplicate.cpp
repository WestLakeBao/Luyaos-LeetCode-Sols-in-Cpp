#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    // solution 1: using sort 39% & 78%
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i=1; i<nums.size(); i++){
            if (nums[i]==nums[i-1]) return true;
        }
        return false;
    }

    //solution 2: using map 27% & 5%
    bool containsDuplicate2(vector<int>& nums) {
        unordered_map<int, int> dict;
        for (auto num:nums){
            if (dict.find(num)!=dict.end()) return true;
            dict[num] = 1;
        }
        return false;
    }

    // solution 3: using set 6% & 5%
    bool containsDuplicate3(vector<int>& nums) {
        set<int> result;
        for(auto num:nums){
            if (result.find(num) != result.end()) return true;
            result.insert(num);
        }
        return false;
    }
};