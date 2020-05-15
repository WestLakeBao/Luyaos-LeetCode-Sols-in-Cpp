#include <string>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        int shortestLength = INT_MAX;
        string result;
//        for (int i=0; i<strs.size(); i++){
//            if (strs[i].size() < shortestLength){
//                shortestLength = strs[i].size();
//            }
//        }
        for (int i=0; i<strs[0].size(); i++){
            for (int j=1; j<strs.size(); j++){
                if (i>=strs[j].size() || strs[j][i] != strs[0][i]) return result;
            }
            result += strs[0][i];
        }
        return result;
    }
};