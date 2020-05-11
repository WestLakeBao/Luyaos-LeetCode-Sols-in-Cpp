#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int result=0;
        for (int i=0; i<s.size(); i++){
            result = 26*result+(s[i]-64);
        }
        return result;
    }
};