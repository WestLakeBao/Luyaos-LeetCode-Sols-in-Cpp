#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        s += "+0";
        int result = 0;
        stack<int> stack;
        string previous_operator = "+";
        for (int i=0; i<s.size(); i++){
            if (isdigit(s[i])) result = 10*result + stoi(s.substr(i, 1));
            else if (s.substr(i, 1) !=" "){
                if (previous_operator=="+") stack.push(result);
                else if (previous_operator=="-") stack.push(-result);
                else if (previous_operator=="*") {
                    int top = stack.top();
                    stack.pop();
                    stack.push(top*result);
                }
                else if (previous_operator=="/") {
                    int top = stack.top();
                    stack.pop();
                    stack.push(int(top/result));
                }
                previous_operator = s.substr(i, 1);
                result = 0;
            }
        }
        int sum=0;
        while (!stack.empty()){
            sum += stack.top();
            stack.pop();
        }
        return sum;
    }
};

int main227(){
    Solution solution;
    int result=solution.calculate("3+2*2");
    return 0;
}