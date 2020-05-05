#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        while (i >= 0) {
            if (digits[i] < 9) {
                digits[i]++;
                break;
            }
            if (i == 0) {
                if (digits[0] == 9) {
                    digits[0] = 0;
                    digits.insert(digits.begin(), 1);
                    break;
                }
            }
            else {
                digits[i] = 0;
                i--;
                }
            }
        return digits;
        }
    };

int main66(){
    vector<int> digits;
    digits.push_back(1);
    digits.push_back(2);
    digits.push_back(3);

    Solution solution;
    vector<int> result;
    result = solution.plusOne(digits);
    return 0;
}