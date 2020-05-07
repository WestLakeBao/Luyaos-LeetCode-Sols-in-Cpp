#include <string>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    // solution 1: 19% & 100%
    int firstUniqChar1(string s) {
        map<char, int> dict;
        for (int i=0; i<s.length(); i++) dict[s[i]]++;
        int min_index = s.length();
        for (auto element: dict){
            if (element.second == 1) {
                size_t found = s.find(element.first);
                if (found < min_index) min_index = found;
            }
        }
        return min_index==s.length() ? -1:min_index;
    }

    // solution 2: 78% & 100%
    int firstUniqChar2(string s) {
        if (s.empty()) return -1;
        int freq[26]={0};
        for (int i=0; i<s.length(); i++){
            if (freq[s[i]-'a'] == 0) freq[s[i]-'a'] = i+1;
            else freq[s[i]-'a']=-1;
        }
        int min_index = s.length();
        for (int i=0; i<26; i++){
            if (freq[i] > 0) min_index = min(min_index, freq[i]-1);
        }
        return min_index < s.length() ? min_index : -1;
    }

    // solution 3: 78% & 100%
    int firstUniqChar(string s) {
        if (s.empty()) return -1;
        int min_index = s.length();
        for (char i='a'; i<='z'; i++){
            int first = s.find(i);
            int last = s.find_last_of(i);
            if (first!=-1 && first==last) min_index = min(min_index, first);
        }
        return min_index < s.length() ? min_index : -1;
    }
};

int main387(){
    Solution solution;
    string s="loveleetcode";
    int result;
    result = solution.firstUniqChar(s);
    return 0;
}