#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int digit_sum=0;
        int dict[1000] = {0}; //create an array with size 1000 and each value == 0. same logic as map, but same more time
        while (n != 1){
            digit_sum = 0;
            while (n){
                digit_sum += (n%10) * (n%10);
                n /= 10;
            }
            n = digit_sum;
            if (dict[n] > 0) return false;
            dict[digit_sum]++;

        }
        return true;
    }
};

int main202(){
    Solution solution;
    bool result=solution.isHappy(1999);
    return 0;
}