// below solution is very slow

#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> row(9);
        vector<set<int>> col(9);
        set<int> sub[3][3];

        for (int i=0; i<board.size(); i++){
            for (int j=0; j<board[0].size(); j++){
                if (board[i][j] != '.'){
                    if (row[i].find(board[i][j]) != row[i].end()) return false;
                    else row[i].insert(board[i][j]);
                    if (col[j].find(board[i][j]) != col[j].end()) return false;
                    else col[j].insert(board[i][j]);
                    int x=i/3;
                    int y=j/3;
                    if (sub[x][y].find(board[i][j]) != sub[x][y].end()) return false;
                    else sub[x][y].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};