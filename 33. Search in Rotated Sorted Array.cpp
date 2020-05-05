#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size()<1) return -1;
        int left = 0, right = nums.size()-1;
        int minIndex = this->getMinIndex(nums);
        if (target >= nums[minIndex] && target <= nums[right]) return this->binarySearch(nums, target, minIndex, nums.size());
        else if (target>=nums[minIndex] && target>=nums[left]) return this->binarySearch(nums, target, 0, minIndex);
        return -1;
    }

private:
    int getMinIndex(vector<int> &nums) // find the index of the minimum value
    {
        int left = 0, right = nums.size()-1;
        if (nums[right]>nums[left]) return 0;
        while (right-left > 1){
            int mid = (left+right)/2;
            if (nums[mid] > nums[left]) left = mid; //left part is sorted, the minimum is in the right part
            else if (nums[mid] < nums[right]) right = mid; // right part is sorted, the minimum is in the left
        }
        return max(left, right);//???
    }

    int binarySearch(vector<int> &nums, int target, int first, int last){
        int left = first;
        int right = last;
        while (left<=right)
        {
            int mid = (left+right)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        return -1;
    }
};

//class Solution {
//public:
//    int search(vector<int>& nums, int target) {
//        int left = 0, right = nums.size()-1;
//        while (left<=right){
//            int mid = (left+right)/2;
//            if (nums[mid] == target) return mid;
//            else if (nums[mid] < target){ //look for a larger subarrray
//                if (nums[mid] <= nums[right]) {
//                    if (target<=nums[right]) left = mid+1;
//                    else right = mid-1;
//                }//left = mid + 1;// right part contains our target
//                else left = mid+1; // nums[right] < nums[mid] < target
//            }
//            else { // look for a smaller subarry nums[mid] > target
//                if (nums[mid] >= nums[left]){
//                    if (nums[left] <= target) right = mid-1;
//                    else left = mid + 1;
//                } //right = mid-1;
//                else right = mid-1;
//            }
//        }
//        return -1;
//    }
//};

int main33(){
    Solution solution;

    int result4;
    vector<int> input4;
    input4.push_back(3);
    input4.push_back(1);
    int target4 = 1;
    result4 = solution.search(input4, target4);
    cout << result4;

    vector<int> input;
    input.push_back(4);
    input.push_back(5);
    input.push_back(6);
    input.push_back(7);
    input.push_back(0);
    input.push_back(1);
    input.push_back(2);
    int target1 = 0;
    int result1;
    result1 = solution.search(input, target1);
    cout << result1;
    int target2 = 3;
    int result2;
    result2 = solution.search(input, target2);
    cout << result2;

    int result3;
    vector<int> input3;
    input3.push_back(4);
    input3.push_back(5);
    input3.push_back(6);
    input3.push_back(7);
    input3.push_back(8);
    input3.push_back(1);
    input3.push_back(2);
    int target3 = 8;
    result3 = solution.search(input3, target3);
    cout << result3;



    return 0;
}