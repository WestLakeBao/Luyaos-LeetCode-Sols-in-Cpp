#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        if (s.size()==1) return s;
        int max_length = 0;
        string result;
        for (int i=0; i<s.size()-1; i++){
            string sub1 = helper(s, i, i);
            string sub2 = helper(s, i, i+1);
            if (max_length < sub1.size()){
                max_length = sub1.size();
                result = sub1;
            }
            if (max_length < sub2.size()){
                max_length = sub2.size();
                result = sub2;
            }
        }
        return result;
    }

    string helper(string s, int left, int right){
        while (left>=0 && right<s.size()){
            if (s[left] != s[right]){
                break;
            }
            left --;
            right ++;
        }
        return s.substr(left+1, right-left-1);
    }
};

int main(){
    Solution solution;
    string s="cbbd";
    string result=solution.longestPalindrome(s);
    return 0;

}