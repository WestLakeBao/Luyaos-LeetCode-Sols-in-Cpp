#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n==1) return "1";
        string s = "1";
        while (n>1) {
            s = say(s);
            n -=1;
        }
        return s;
    }

    string say(string s){
        string result="";
        char current=s[0];
        int count = 1;
        for (int i=1; i<s.size(); i++){
            if (s[i] == current){
                count += 1;
            }
            else{
                result += to_string(count) + current;  // attention!!!
                current = s[i];
                count = 1;
            }
        }
        result += to_string(count) + current; // attention!!!
        return result;
    }
};

int main38(){
    Solution solution;
    string result = solution.countAndSay(4);
    return 0;
}