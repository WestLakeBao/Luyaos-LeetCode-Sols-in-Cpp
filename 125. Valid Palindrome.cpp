#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;
        int right=s.size()-1;
        while (left < right){
            while (left < right && !isalnum(s[left])) left += 1;
            while (left < right && !isalnum(s[right])) right -= 1;
            if (tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left += 1;
            right -= 1;
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