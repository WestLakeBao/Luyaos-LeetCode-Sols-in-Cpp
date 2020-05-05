// The highest value an 'int' type variable can take is 2147483647

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        while (i<nums.size()){
            if (nums[i] == INT_MIN) {
                i++;
                continue;};
            int j=nums[i]-1;
            if (nums[i]>0 && nums[i]<=nums.size() && nums[i] != nums[j]) swap(nums[i], nums[j]);
            else i ++;
            }
        for (int j=0; j<nums.size(); j++){
            if (nums[j] != j+1) return j+1;
        }
        return nums.size()+1;
    }
};

int main41(){
    Solution solution;
    vector<int> input;
//    input.push_back(3);
//    input.push_back(4);
//    input.push_back(-1);
//    input.push_back(1);

    input.push_back(2147483647);
    input.push_back(2147483646);
    input.push_back(2147483645);
    input.push_back(3);
    input.push_back(2);
    input.push_back(1);
    input.push_back(-1);
    input.push_back(0);
    input.push_back(-2147483648);

    int result;
    result = solution.firstMissingPositive(input);
    cout << result; //2
    return 0;
}