#include <string>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common;
        for (int i=0; i<strs[0].size(); i++){
            for (int j=1; j<strs.size(); j++){
                if (i >= strs[j].size() | strs[0][i]!=strs[j][i]){
                    return common;
                }
            }
            common += strs[0][i];
        }
        return common;
    }
}