#include <iostream>
#include <vector>

using namespace  std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool first_row_contains_zero = false, first_col_contains_zero = false;
        for (int i=0; i<matrix.size(); i++){
            if (matrix[i][0]==0) first_col_contains_zero = true;
            break;
        }
        for (int j=0; j<matrix[0].size(); j++){
            if (matrix[0][j]==0) first_row_contains_zero = true;
            break;
        }
        for (int i=1; i<matrix.size(); i++){
            for (int j=1; j<matrix[i].size(); j++){
                if (matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i=1; i<matrix.size(); i++){
            if (matrix[i][0] == 0){
                for (int j=1; j<matrix[0].size(); j++) matrix[i][j] = 0;
            }
        }
        for (int j=1; j<matrix[0].size(); j++){
            if (matrix[0][j]==0){
                for (int i=1; i<matrix.size(); i++) matrix[i][j] = 0;
            }
        }
        if (first_row_contains_zero){
            for (int j=0; j<matrix[0].size(); j++) matrix[0][j] = 0;
        }
        if (first_col_contains_zero){
            for (int i=0; i<matrix.size(); i++) matrix[i][0] = 0;
        }
    }
};

int main73(){
    Solution solution;
    vector<vector<int>> matrix;

    vector<int> row1;
    row1.push_back(0);
    row1.push_back(1);
    row1.push_back(2);
    row1.push_back(0);

    vector<int> row2;
    row2.push_back(3);
    row2.push_back(4);
    row2.push_back(5);
    row2.push_back(2);

    vector<int> row3;
    row3.push_back(1);
    row3.push_back(3);
    row3.push_back(1);
    row3.push_back(5);

    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);

    solution.setZeroes(matrix);
    return 0;
}