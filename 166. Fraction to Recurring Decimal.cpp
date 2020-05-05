#include <string>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int n, int d) {
        long numerator=n;
        long denominator=d;
        if (numerator==0) return "0";
        if (denominator==0) return NULL;
        string result;
        bool sign=(numerator>0)==(denominator>0);
        if (!sign) result += '-';
        if (numerator<0) numerator *= (-1);
        if (denominator<0) denominator *= (-1);
        long divisor = numerator/denominator;
        result += to_string(divisor);
        long remainder = numerator%denominator;
        if (remainder==0) return result;
        result += '.';
        unordered_map<int, int> map;
        while (remainder){
            if (map.find(remainder) != map.end()){
                result.insert(result.begin()+map[remainder], '(');
                result.push_back(')');
                break;
            }
            map[remainder] = result.size();
            divisor = 10*remainder/denominator;
            remainder = 10*remainder%denominator;
            result.append(to_string(divisor));
        }
        return result;
    }
};

int main166(){
    int numerator = 1, denominator=2;
    Solution solution;
    string result;
    result = solution.fractionToDecimal(-2147483648, 1);
    return 0;
}