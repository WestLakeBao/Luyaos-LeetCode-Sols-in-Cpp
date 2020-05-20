#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        backtracking(n, n, "");
        return result;
    }

    void backtracking(int left, int right, string current){
        if (left==0 && right==0) result.push_back(current);
        if (left > right) return;
        if (left > 0) backtracking(left-1, right, current+'(');
        if (right > 0) backtracking(left, right-1, current+')');
    }
private:
    vector<string> result;
};