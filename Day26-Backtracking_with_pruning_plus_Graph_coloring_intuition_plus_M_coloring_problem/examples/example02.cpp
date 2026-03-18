/*
 * Example 2: Palindrome Partition
 */
#include <bits/stdc++.h>
using namespace std;
// Example 2: Palindrome Partitioning with pruning
bool isPalin(const string& s, int l, int r) {
    while (l < r) if (s[l++] != s[r--]) return false;
    return true;
}
void partition(const string& s, int start, vector<string>& cur, vector<vector<string>>& res) {
    if (start == (int)s.size()) { res.push_back(cur); return; }
    for (int end = start; end < (int)s.size(); end++) {
        if (isPalin(s, start, end)) { // prune: only recurse on palindromes
            cur.push_back(s.substr(start, end - start + 1));
            partition(s, end + 1, cur, res);
            cur.pop_back();
        }
    }
}
int main() {
    string s = "aab";
    vector<vector<string>> res; vector<string> cur;
    partition(s, 0, cur, res);
    for (auto& v : res) { for (auto& w : v) cout << w << " "; cout << "\n"; }
}
