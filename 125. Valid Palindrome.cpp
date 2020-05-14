#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left=0, right=s.length()-1;
        while (left<right){
            while (! isalpha(s[left]) && ! isdigit(s[left])){
                left ++;
                if (left>=right) return true; // for cases like ".,"
            }
            while (! isalpha(s[right]) && ! isdigit(s[right])){
                right --;
            }
            if (tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }
};

int main125(){
    Solution solution;
    //string s=".,";
    string s="0P";
    bool result=solution.isPalindrome(s);
    return 0;
}