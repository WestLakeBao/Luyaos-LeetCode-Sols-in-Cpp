#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        int row_len = board.size(), col_len = board[0].size();
        vector<vector<int>> count_live(row_len, vector<int>(col_len,0));//attention!!!!!!!!!!!!!!!!!
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j]==1){
                    int k_low = max(0, i-1), k_high = min(row_len-1, i+1);
                    int l_low = max(0, j - 1), l_high = min(col_len - 1, j + 1);
                    for (int k = k_low; k <= k_high; k++) {
                        for (int l = l_low; l <= l_high; l++) {
                            count_live[k][l]++;
                        }
                    }
                    count_live[i][j] --;
                }
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 0 && count_live[i][j] == 3) board[i][j] = 1;
                if (board[i][j] == 1 && (count_live[i][j] < 2 || count_live[i][j] > 3)) board[i][j] = 0;
            }
        }
    }
};

int main289(){
    Solution solution;
    vector<vector<int>> board{
            {0,1,0},
            {0,0,1},
            {1,1,1},
            {0,0,0}
    };
    solution.gameOfLife(board);
    return 0;
}