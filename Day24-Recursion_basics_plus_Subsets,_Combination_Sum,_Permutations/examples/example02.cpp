/*
 * Example 2: Combination Sum
 */
#include <bits/stdc++.h>
using namespace std;
// Example 2: Combination Sum (reuse allowed, target sum)
void combinationSum(vector<int>& cands, int idx, int remain, vector<int>& cur, vector<vector<int>>& res) {
    if (remain == 0) { res.push_back(cur); return; }
    for (int i = idx; i < (int)cands.size(); i++) {
        if (cands[i] > remain) break; // pruning (requires sorted input)
        cur.push_back(cands[i]);
        combinationSum(cands, i, remain - cands[i], cur, res); // i not i+1 = reuse
        cur.pop_back();
    }
}
int main() {
    vector<int> cands = {2, 3, 6, 7}; sort(cands.begin(), cands.end());
    int target = 7;
    vector<vector<int>> res; vector<int> cur;
    combinationSum(cands, 0, target, cur, res);
    for (auto& v : res) { for (int x : v) cout << x << " "; cout << "\n"; }
}
