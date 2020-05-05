//Given a non-empty array of integers, every element appears twice except for one. Find that single one.
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // solution 1: using hash map
    int singleNumber1(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int num:nums){
            map[num] ++;
        }
        for (unordered_map<int, int>::iterator it=map.begin(); it!=map.end(); it++){
            if (it->second == 1) return it->first;
        }
        return -1;
    }

    //solution 2: using XOR operator
    int singleNumber(vector<int>& nums) {
        int result=0;
        for (int num:nums){
            result ^= num;
        }
        return result;
    }
};