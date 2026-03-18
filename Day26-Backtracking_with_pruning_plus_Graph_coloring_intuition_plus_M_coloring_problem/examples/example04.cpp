/*
 * Example 4: Unique Permutations
 */
#include <bits/stdc++.h>
using namespace std;
// Example 4: Unique Permutations (with duplicates, backtracking)
void permuteUnique(vector<int>& nums, vector<bool>& used, vector<int>& cur, vector<vector<int>>& res) {
    if (cur.size() == nums.size()) { res.push_back(cur); return; }
    for (int i = 0; i < (int)nums.size(); i++) {
        if (used[i]) continue;
        // Skip duplicate: same value, previous one not used (would produce duplicate)
        if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
        used[i] = true;
        cur.push_back(nums[i]);
        permuteUnique(nums, used, cur, res);
        cur.pop_back();
        used[i] = false;
    }
}
int main() {
    vector<int> nums = {1, 1, 2}; sort(nums.begin(), nums.end());
    vector<bool> used(nums.size(), false);
    vector<vector<int>> res; vector<int> cur;
    permuteUnique(nums, used, cur, res);
    for (auto& p : res) { for (int x : p) cout << x << " "; cout << "\n"; }
}
