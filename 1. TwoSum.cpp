#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution_twoSum {
public:
    vector<int> twoSum(vector<int> nums, int target) {
        std::unordered_map<int, int> map;
        for (int i=0; i<nums.size(); i++){
            int diff = target - nums[i];
            auto search = map.find(diff);
            if (search!=map.end()){
                return vector<int>{search->second, i};
            }
            map[nums[i]] = i;
        }
        return vector<int>();
    }
};

int main1(){
    Solution_twoSum twosum;
    vector<int> twosum_result;
    twosum_result = twosum.twoSum({2, 7, 11, 15}, 9);
    for (int i=0; i<twosum_result.size(); i++){
        cout << twosum_result[i];
    } //0 1
    return 0;
}