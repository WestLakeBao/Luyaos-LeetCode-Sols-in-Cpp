#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.length()<needle.size()) return -1;
        if (haystack.length()==1) {
            if (haystack[0] == needle[0] || needle.length() == 0) return 0;
            else return -1;
        }
        if (haystack.length()==0 && needle.length()==0) return 0;
        int left=0;
        while (left<haystack.size()){
            if (haystack.substr(left, needle.length())==needle)
                return left;
            else {
                left += 1;
            }
        }
        return -1;
    }
};