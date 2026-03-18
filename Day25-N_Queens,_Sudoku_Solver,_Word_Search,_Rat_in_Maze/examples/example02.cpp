/*
 * Example 2: N-Queens Bitmask
 */
#include <bits/stdc++.h>
using namespace std;
// Example 2: N-Queens with bitmask (faster)
int n_queens_count = 0;
void solveNQueens(int row, int n, int cols, int diag1, int diag2) {
    if (row == n) { n_queens_count++; return; }
    int avail = ((1 << n) - 1) & ~(cols | diag1 | diag2);
    while (avail) {
        int bit = avail & (-avail); // lowest set bit
        avail &= avail - 1;
        solveNQueens(row + 1, n, cols | bit, (diag1 | bit) << 1, (diag2 | bit) >> 1);
    }
}
int main() {
    int n = 8;
    solveNQueens(0, n, 0, 0, 0);
    cout << "N=" << n << ": " << n_queens_count << " solutions\n"; // 92
}
