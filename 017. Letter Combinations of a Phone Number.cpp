#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return result;
        unordered_map<int, string> dict={{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"},
                                         {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};

        backtracking(dict, digits, "", 0);
        return result;
    }

    void backtracking(unordered_map<int, string> dict, string digits, string temp, int index){
        if (index==digits.size()) {
            result.push_back(temp);
            return;
        }
        int digit=digits[index]-48;
        for (int j=0; j<dict[digit].size(); j++){
            backtracking(dict, digits, temp+dict[digit][j], index+1);
        }
    }

private:
    vector<string> result={};
};

int main17(){
    Solution solution;
    string digits="23";
    vector<string> result=solution.letterCombinations(digits);
    return 0;
}