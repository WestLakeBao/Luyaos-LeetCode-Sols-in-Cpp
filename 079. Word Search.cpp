#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        if (board.empty()||board[0].empty()) return false;
        m = board.size(); //special attention
        n = board[0].size(); // special attention
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (dfs(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
private:
    int m; //special attention
    int n; //special attention
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int wordIndex){
        if (i<0 || i>=m|| j<0 || j>=n || board[i][j] != word[wordIndex]) return false; //check line 24 before line 25 makes the difference in speed
        if (wordIndex == word.size()-1) return true;
        board[i][j] = '#';
        bool found = dfs(board, i-1, j, word, wordIndex+1)
                || dfs(board, i+1, j, word, wordIndex+1)
                ||dfs(board, i, j-1, word, wordIndex+1)
                || dfs(board, i, j+1, word, wordIndex+1);
        board[i][j] = word[wordIndex];
        return found;
    }
};

//class Solution {
//public:
//    bool exist(vector<vector<char>>& board, string word) {
//        if (board.size()==0 || board[0].size() ==0) return word.size() == 0;
//        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
//        for (int i=0; i<board.size(); i++){
//            for (int j=0; j<board[0].size(); j++){
//                if (dfs(board, i, j, visited, word, 0)) return true;
//            }
//        }
//        return false;
//    }
//
//    bool dfs(vector<vector<char>> board, int i, int j, vector<vector<int>> visited, string word, int wordIndex){
//        if (board[i][j] != word[wordIndex]) return false;
//        if (visited[i][j]) return false;
//        if (wordIndex+1 == word.size()) return true;
//        visited[i][j] = 1;
//        if ((i-1>=0 && dfs(board, i-1, j, visited, word, wordIndex+1))) return true;
//        if (i+1<board.size() && dfs(board, i+1, j, visited, word, wordIndex+1)) return true;
//        if (j-1>=0 && dfs(board, i, j-1, visited, word, wordIndex+1)) return true;
//        if (j+1<board[0].size() && dfs(board, i, j+1, visited, word, wordIndex+1)) return true;
//        visited[i][j] = 0;
//        return false;
//    }
//};

int main79(){
    vector<vector<char>> board{
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
    };
    string word="ABCCED";
    Solution solution;
    bool result;
    result = solution.exist(board, word);
    return 0;
}