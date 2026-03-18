/*
 * Example 3: Valid Parentheses
 */
#include <bits/stdc++.h>
using namespace std;
// Example 3: Generate Valid Parentheses (backtracking with constraints)
void genParens(int n, int open, int close, string cur, vector<string>& res) {
    if ((int)cur.size() == 2 * n) { res.push_back(cur); return; }
    if (open < n)   genParens(n, open + 1, close, cur + "(", res);
    if (close < open) genParens(n, open, close + 1, cur + ")", res);
}
int main() {
    int n = 3;
    vector<string> res;
    genParens(n, 0, 0, "", res);
    for (auto& s : res) cout << s << "\n";
}
