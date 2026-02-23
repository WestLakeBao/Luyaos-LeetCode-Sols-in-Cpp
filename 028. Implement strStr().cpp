#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i=0, j=needle.length(); i+j<=haystack.length(); i++){
            if (haystack.substr(i, j)==needle) return i;
        }
        return -1;
    }
};