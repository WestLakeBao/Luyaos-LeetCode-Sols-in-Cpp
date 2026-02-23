#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int right = s.size()-1;
        while (right >=0 and s[right] == ' '){
            right -= 1;
        }
        int left = right;
        while (left >= 0 and s[left] != ' '){
            left -= 1;
        }
        return right-left;
    }
};