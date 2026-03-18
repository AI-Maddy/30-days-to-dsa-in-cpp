/*
 * Example 4: Subsets With Duplicates
 */
#include <bits/stdc++.h>
using namespace std;
// Example 4: Subsets with duplicates (nums may have repeated elements)
void subsetsWithDup(vector<int>& nums, int idx, vector<int>& cur, vector<vector<int>>& res) {
    res.push_back(cur);
    for (int i = idx; i < (int)nums.size(); i++) {
        if (i > idx && nums[i] == nums[i-1]) continue; // skip duplicates
        cur.push_back(nums[i]);
        subsetsWithDup(nums, i + 1, cur, res);
        cur.pop_back();
    }
}
int main() {
    vector<int> nums = {1, 2, 2}; sort(nums.begin(), nums.end());
    vector<vector<int>> res; vector<int> cur;
    subsetsWithDup(nums, 0, cur, res);
    for (auto& s : res) { cout << "["; for (int x : s) cout << x << " "; cout << "]\n"; }
}
