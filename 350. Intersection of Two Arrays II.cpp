#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        for (int num:nums1) map[num]++;
        vector<int> result;
        for (int num2:nums2){
            if (--map[num2]>=0) result.push_back(num2);}
        return result;
    }
};

int main350(){
    vector<int> nums1={1,2,2,1};
    vector<int> nums2={2,2};
    Solution solution;
    vector<int> result;
    result = solution.intersect(nums1, nums2);
    return 0;
}