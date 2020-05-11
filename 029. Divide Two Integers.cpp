// Sorry I hate this question

#include <limits.h>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int divide(int dividend1, int divisor1) {
        if (dividend1==0) return 0;
        bool sign=(dividend1<0)==(divisor1<0); // true if positive result
        if ((dividend1==INT_MIN || dividend1==INT_MAX) && abs(divisor1)==1) {
            return sign?INT_MAX:INT_MIN;
        }
        long long dividend = labs(dividend1);
        long long divisor = labs(divisor1);
        if (dividend==divisor) return sign?1:-1;
        int result=0;
        while (dividend>=divisor){
            int val=1;
            uint32_t temp = divisor;
            while (dividend>=temp){
                result += val;
                dividend -= temp;
                val *= 2;
                temp *= 2;
            }
        }
        return sign ? result:-result;
    }
};

int main29(){
    Solution solution;
    int result;
    //result = solution.divide(-2147483648, 2);
    result = solution.divide(1100540749,-1090366779);
    return 0;
}