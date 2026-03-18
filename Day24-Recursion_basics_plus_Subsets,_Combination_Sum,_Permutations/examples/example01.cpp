/*
 * Example 1: All Subsets
 */
#include <bits/stdc++.h>
using namespace std;
// Example 1: Generate All Subsets (Power Set)
void subsets(vector<int>& nums, int idx, vector<int>& cur, vector<vector<int>>& res) {
    res.push_back(cur);
    for (int i = idx; i < (int)nums.size(); i++) {
        cur.push_back(nums[i]);
        subsets(nums, i + 1, cur, res);
        cur.pop_back(); // backtrack
    }
}
int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res;
    vector<int> cur;
    subsets(nums, 0, cur, res);
    for (auto& s : res) { cout << "["; for (int x : s) cout << x << " "; cout << "]\n"; }
}
