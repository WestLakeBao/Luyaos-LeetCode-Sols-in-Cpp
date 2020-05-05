#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows==0) return result;
        result.push_back({1});
        for (int i=2; i<numRows+1; i++){
            vector<int> row(i,1);
            for (int j=1; j<i-1; j++){
                row[j] = result[i-2][j]+result[i-2][j-1];
            }
            result.push_back(row);
        }
        return result;
    }
};

int main118(){
    Solution solution;
    vector<vector<int>> result;
    result = solution.generate(5);
    return 0;
}