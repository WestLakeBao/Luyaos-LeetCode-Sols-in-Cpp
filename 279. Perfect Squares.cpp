#include <cmath>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        for (int i=0; i*i<=n; i++){
            dp[i*i] = 1;
        }
        for (int i=1; i<n+1; i++){
            for (int j=1; j<=i; j++){
                if (i+j*j<=n && dp[i] != 2147483648) dp[i+j*j]=min(dp[i+j*j], dp[i]+1);
            }
        }
        return dp[n];
    }
};

int main279(){
    Solution solution;
    int result=solution.numSquares(4);
    return 0;
}