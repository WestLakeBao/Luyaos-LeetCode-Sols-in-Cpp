#include <vector>
#include <unordered_map>
#include <tuple>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> strs_map;
        for (string str : strs){
            string s = str;
            sort(s.begin(), s.end());
            strs_map[s].push_back(str);
        }
        vector<vector<string>> result;
        for (unordered_map<string, vector<string>>::iterator it = strs_map.begin(); it != strs_map.end(); it++){
            result.push_back(it->second);
        }
        return result;
    }
};

int main49(){
    Solution solution;
    vector<string> strs={"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result=solution.groupAnagrams(strs);
    return 0;
}