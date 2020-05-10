#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i=0;
        long long result=0;
        while (i<str.length()){
            if (str[i]==' ') i++;
            else break;
        }
        bool sign=true;
        if (str[i] == '+') i++;
        else if (str[i] == '-'){
            i++;
            sign=false;
        }
        while (i<str.length() && isdigit(str[i])){
            int outflow = str[i]-'0';
            if (result<214748365){
                result *= 10;
            }
            else {
                return sign? 2147483647:-2147483648;
            }
            if (sign && result+outflow > 2147483647) {
                return 2147483647;
            }
            else if (!sign && result+outflow > 2147483648) {
                return -2147483648;
            }
            result += outflow;
            i++;
        }
        return sign ? result:-result;
    }
};

int main8(){
    Solution solution;
    //string str="   -42";
    //string str="-91283472332";
    string str="-2147483648";
    int result;
    result=solution.myAtoi(str);
    return 0;
}