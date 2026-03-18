/*
 * Example 1: N-Queens Board
 */
#include <bits/stdc++.h>
using namespace std;
// Example 1: N-Queens Problem
int n;
vector<string> board;
vector<vector<string>> solutions;
bool isSafe(int row, int col) {
    // Check column and diagonals above
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
        int dc = col - (row - i);
        if (dc >= 0 && board[i][dc] == 'Q') return false;
        dc = col + (row - i);
        if (dc < n && board[i][dc] == 'Q') return false;
    }
    return true;
}
void solve(int row) {
    if (row == n) { solutions.push_back(board); return; }
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 'Q';
            solve(row + 1);
            board[row][col] = '.';
        }
    }
}
int main() {
    n = 4;
    board.assign(n, string(n, '.'));
    solve(0);
    cout << solutions.size() << " solutions\n";
    for (auto& sol : solutions) { for (auto& row : sol) cout << row << "\n"; cout << "\n"; }
}
