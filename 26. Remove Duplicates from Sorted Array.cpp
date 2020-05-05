#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i = 0;
        for (int j = 0; j<nums.size(); j++){
            if (nums[i] != nums[j]) {
                i += 1;
                swap(nums[i], nums[j]);
            }
        }
        return i+1;
    }
};

int main26(){
    Solution solution;
    int result;
    vector<int> input;
    input.push_back(1);
    input.push_back(1);
    input.push_back(2);
    result = solution.removeDuplicates(input);
    cout << result;
    return 0;
}