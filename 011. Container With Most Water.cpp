#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> height) {
        int maxArea = 0;
        int left = 0, right = height.size()-1;
        while (left<right){
            int pivot = min(height[left], height[right]);
            maxArea = max(maxArea, pivot*(right-left));
            while (height[left] <= pivot && left < right) left += 1;
            while (height[right] <= pivot && left < right) right -= 1;
            }
        return maxArea;
    }
};

int main11(){
    Solution solution;
    int result;
    result = solution.maxArea({1,8,6,2,5,4,8,3,7});
    cout << result;
    return 0;
}