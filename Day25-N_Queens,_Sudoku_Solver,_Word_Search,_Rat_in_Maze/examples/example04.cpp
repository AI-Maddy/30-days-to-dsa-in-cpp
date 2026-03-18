/*
 * Example 4: Word Search
 */
#include <bits/stdc++.h>
using namespace std;
// Example 4: Word Search in Grid
bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int k) {
    if (k == (int)word.size()) return true;
    if (i < 0 || i >= (int)board.size() || j < 0 || j >= (int)board[0].size()) return false;
    if (board[i][j] != word[k]) return false;
    char tmp = board[i][j]; board[i][j] = '#'; // mark visited
    bool found = dfs(board, word, i+1, j, k+1) || dfs(board, word, i-1, j, k+1) ||
                 dfs(board, word, i, j+1, k+1) || dfs(board, word, i, j-1, k+1);
    board[i][j] = tmp; // restore
    return found;
}
bool wordSearch(vector<vector<char>>& board, const string& word) {
    for (int i = 0; i < (int)board.size(); i++)
        for (int j = 0; j < (int)board[0].size(); j++)
            if (dfs(board, word, i, j, 0)) return true;
    return false;
}
int main() {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout << wordSearch(board, "ABCCED") << "\n"; // 1
    cout << wordSearch(board, "SEE") << "\n";    // 1
    cout << wordSearch(board, "ABCB") << "\n";   // 0
}
