#include <iostream>
#include <vector>

using namespace std;

class Subsets {
public:
    static vector<vector<int>> findSubsets(const vector<int>& nums) {
        vector<vector<int>> subsets;
        // start by adding the empty subset
        subsets.push_back(vector<int>());
        for (auto currentNumber : nums) {
            // we will take all existing subsets and insert the current number in them to create new
            // subsets
            int n = subsets.size();
            for (int i = 0; i < n; i++) {
                // create a new subset from the existing subset and insert the current element to it
                vector<int> set(subsets[i]);
                set.push_back(currentNumber);
                subsets.push_back(set);
            }
        }
        return subsets;
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(vector<int> ());
//        for (int i=0; i<nums.size(); i++){
        for (auto num :nums){
            int n = result.size();
            for (int j=0; j<n; j++){
                vector<int> set(result[j]);
                set.push_back(num);
                result.push_back(set);
            }
        }
        return result;
    }
};

int main78(int argc, char* argv[]) {
    Solution solution;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    vector<vector<int>> result;
    result = solution.subsets(nums);
    return 0;

//    vector<vector<int>> result = Subsets::findSubsets(vector<int>{1, 3});
//    cout << "Here is the list of subsets: " << endl;
//    for (auto vec : result) {
//        for (auto num : vec) {
//            cout << num << " ";
//        }
//        cout << endl;
//    }
//
//    result = Subsets::findSubsets(vector<int>{1, 5, 3});
//    cout << "Here is the list of subsets: " << endl;
//    for (auto vec : result) {
//        for (auto num : vec) {
//            cout << num << " ";
//        }
//        cout << endl;
//    }
}
