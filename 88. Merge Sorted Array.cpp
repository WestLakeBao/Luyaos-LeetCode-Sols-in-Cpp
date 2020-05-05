#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1, j=n-1, end=m+n-1;
        while (i>=0 && j>=0){
            if (nums1[i] > nums2[j]){
                nums1[end] = nums1[i];
                i--;
            }
            else {
                nums1[end] = nums2[j];
                j--;
            }
            end--;
        }
        if (i<0) {
            while (j>=0) {
                nums1[j] = nums2[j];
                j -= 1;
            }
        }
    }
};

int main88(){
    Solution solution;
    vector<int> nums1{1,2,3,0,0,0};
    vector<int> nums2{2,5,6};

    solution.merge(nums1, 3, nums2, 3);
    return 0;
}