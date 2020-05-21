#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() ||s.rfind("0", 0)==0) return 0;
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;  
        for (int i=1; i<s.size()+1; i++){
            if (s[i-1] != '0') {
                dp[i] = dp[i-1]; // attention: should use '0' rather than "0"
            }
            if (i>1 && 10 <= stoi(s.substr(i-2, 2)) && stoi(s.substr(i-2, 2)) <= 26) {
                dp[i] += dp[i-2];
            }
        }
        return dp[s.size()];
    }
};

int main91(){
    Solution solution;
    string s="12";
    int result=solution.numDecodings(s);
    return 0;
}