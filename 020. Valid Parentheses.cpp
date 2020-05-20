#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string left="([{";
        string right=")]}";
        stack<char> stack;
        for (int i=0; i<s.size(); i++){
            if (left.find(s[i]) != string::npos){
                stack.push(s[i]);
            }
            else {
                if (stack.empty() || left.find(stack.top()) != right.find(s[i])){
                    return false;
                }
                stack.pop();
            }
        }
        return stack.empty()? true:false;
    }
};

int main20(){
    Solution solution;
    string s="]";
    string s1="{[]}";
    string s2="[";
    bool result=solution.isValid(s);
    bool result1=solution.isValid(s1);
    bool result2=solution.isValid(s2);
    return 0;
}