#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        unordered_map<int, int> map;
        int max_length = 0;
        for (int right=0; right<s.size(); right++){
            //auto right_index = map.find(s[right]);
//            if (right_index != map.end()) {
//                left = max(left, right_index->second + 1);}
            if (map.find(s[right]) != map.end()) left = max(left, map[s[right]]+1);
            map[s[right]] = right;
            max_length = max(max_length, (right -left + 1));
        }
        return max_length;
    }
};

int main3(){
    Solution solution;
    //string s="abcabcbb";
    //string s="bbbbb";
    string s="pwwkew";
    int result=solution.lengthOfLongestSubstring(s);
    return 0;
}

