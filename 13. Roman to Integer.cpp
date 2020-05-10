#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // solution 1: brute force 89% & 100%
    int romanToInt1(string s) {
        int result=0;
        char previous;

        for (char letter:s){
            if (letter=='I') {
                result++;
            }
            else if (letter=='V'){
                if (previous=='I') result-=2;
                result += 5;
            }
            else if (letter=='X'){
                if (previous=='I') result-=2;
                result += 10;
            }
            else if (letter=='L') {
                if (previous=='X') result -= 20;
                result += 50;
            }
            else if (letter=='C'){
                if (previous=='X') result -= 20;
                result += 100;
            }
            else if (letter=='D'){
                if (previous=='C') result -= 200;
                result += 500;
            }
            else if (letter=='M'){
                if (previous=='C') result-=200;
                result += 1000;
            }
            previous=letter;
        }
        return result;
    }

    // solution 2: use hash map 6% & 5%
    int romanToInt(string s) {
        int result=0;
        char previous;
        unordered_map<string, int> map={{"I",1}, {"V", 5}, {"X", 10},
                                      {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000},
                                       {"IV", 4}, {"IX", 9},
                                       {"XL", 40}, {"XC", 90},
                                       {"CD", 400}, {"CM", 900}};

        for (int i=0; i<s.length(); i++){
            if (map.find(s.substr(i, 2)) != map.end()) {
                result+=map[s.substr(i, 2)];
                i++;
            }
            else {
                result += map[s.substr(i, 1)];
            }
        }
        return result;
    }
};

int main(){
    Solution solution;
    string s= "IV";
    int result=solution.romanToInt(s);
    return 0;
}