#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        if (!binary_search(nums.begin(), nums.end(), target)) return result;
        int left = 0, right = nums.size()-1, mid = (left+right)/2;
        while (nums[mid]!=target){
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
            mid = (left+right)/2;
        }
        int i=mid;
        while (i>=0 && nums[i]==target) i --;
        result[0] = i+1;
        i = mid;
        while (i<nums.size() && nums[i]==target) i ++;
        result[1] = i-1;
        return result;
    }
};

int main34(){
    vector<int> input;
    input.push_back(5);
    input.push_back(7);
    input.push_back(7);
    input.push_back(8);
    input.push_back(8);
    input.push_back(10);
    int target = 8;

    Solution solution;
    vector<int> result;
    result = solution.searchRange(input, target);
    for (int i=0; i<2; i++){
        cout << result[i] << " ";
    } //3 4
    return 0;
}