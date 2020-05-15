#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // solution 1: use hash map 34% sth very slow
    vector<int> intersect1(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        for (int num:nums1) map[num]++;
        vector<int> result;
        for (int num2:nums2){
            if (--map[num2]>=0) result.push_back(num2);}
        return result;
    }

    // solution 2: sort & two pointers 85% & 7%
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> result;
        int i=0;
        int j=0;
        while (i<nums1.size() && j<nums2.size()){
            if (nums1[i]==nums2[j]){
                result.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i]<nums2[j]){
                i++;
            }
            else {
                j++;
            }
        }
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