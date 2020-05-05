#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // solution 1: 45% & 100%
    bool isAnagram1(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> map;
        for (int i=0; i<s.length(); i++){
            map[s[i]] ++;
            map[t[i]] --;
        }
        for (unordered_map<char, int>::iterator it=map.begin(); it!=map.end();it++){
            if (it->second) return false;
        }
        return true;
    }

    // solution 2: 7% & 100%
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};