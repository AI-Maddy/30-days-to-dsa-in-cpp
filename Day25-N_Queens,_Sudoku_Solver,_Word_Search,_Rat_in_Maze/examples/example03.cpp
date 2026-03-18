/*
 * Example 3: Sudoku Solver
 */
#include <bits/stdc++.h>
using namespace std;
// Example 3: Sudoku Solver
bool isValid(vector<vector<char>>& board, int r, int c, char ch) {
    for (int i = 0; i < 9; i++) {
        if (board[r][i] == ch) return false;
        if (board[i][c] == ch) return false;
        if (board[3*(r/3)+i/3][3*(c/3)+i%3] == ch) return false;
    }
    return true;
}
bool solveSudoku(vector<vector<char>>& board) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.') {
                for (char ch = '1'; ch <= '9'; ch++) {
                    if (isValid(board, r, c, ch)) {
                        board[r][c] = ch;
                        if (solveSudoku(board)) return true;
                        board[r][c] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},{'.','.','.','.','.','.','.','.','.'},
        {'8','.','.','.','6','.','.','.','3'},{'.','.','.','.','2','.','.','.','.'},
        {'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    // Note: last two rows would need valid values for a real puzzle
    // Using partial board for demo
    cout << "Sudoku solving...\n";
}
