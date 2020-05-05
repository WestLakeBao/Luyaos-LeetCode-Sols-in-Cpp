#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.size()==0) return result;

        int up = 0, down = matrix.size()-1, left = 0, right = matrix[0].size()-1;

        while (up<down && left <right){
            for (int i=left; i<right; i++) result.push_back(matrix[up][i]);
            for (int j=up; j<down; j++) result.push_back(matrix[j][right]);
            for (int i=right; i>left; i--) result.push_back(matrix[down][i]);
            for (int j=down; j>up; j--) result.push_back(matrix[j][left]);
            up++;
            down--;
            left++;
            right--;
        }
        if (up==down) {
            for (int i=left;i<right+1;i++) result.push_back(matrix[up][i]);
        }
        else if (left==right){
            for (int j=up;j<down+1;j++) result.push_back(matrix[j][left]);
        }
        return result;
    }
};