#include <iostream>
#include <vector>

using namespace  std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size()<3) return result;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-1; i++){
            if (i>0 && nums[i] == nums[i-1]) continue;
            int left = i+1, right = nums.size()-1;
            while (left<right) {
                int tempsum = nums[i]+nums[left]+nums[right];
                if (tempsum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left ++;
                    right --;
                    while (nums[left] == nums[left-1] && left<right) left ++;
                    while (nums[right] == nums[right+1] && left < right) right --;}
                else if (tempsum<0) {left++;}
                else {right --;}
            }
        }
        return result;
    }
};

int main15(){
//    Solution solution;
//    vector<vector<int>> result;
//    vector<int> input;
//    input.push_back(-1);
//    input.push_back(0);
//    input.push_back(1);
//    input.push_back(2);
//    input.push_back(-1);
//    input.push_back(-4);
//    result = solution.threeSum(input);
//    for (int i=0; i<result.size(); i++){
//        cout<<result[i][0]<<' '<<result[i][1]<<' '<<result[i][2]<<' ';
//    };

    Solution solution2;
    vector<vector<int>> result2;
    vector<int> input2;
//    input2.push_back(1);
//    input2.push_back(2);
//    input2.push_back(-2);
//    input2.push_back(-1);
    input2.push_back(1);
    input2.push_back(-1);
    input2.push_back(-1);
    input2.push_back(0);
    //result2 = solution2.threeSum({0,0,0,0});
    result2 = solution2.threeSum(input2);

    for (int i=0; i<result2.size(); i++){
        cout<<result2[i][0]<<' '<<result2[i][1]<<' '<<result2[i][2]<<' ';
    }
}