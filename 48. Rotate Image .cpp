#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // first, flip the matrix diagonally
        for (int i=0; i<matrix.size(); i++){
            for (int j=i+1; j<matrix[i].size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //next, we reverse the matrix (row by row)
        for (int i=0; i<matrix.size(); i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
