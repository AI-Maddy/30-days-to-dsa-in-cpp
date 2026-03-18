/*
 * Example 3: Permutations
 */
#include <bits/stdc++.h>
using namespace std;
// Example 3: All Permutations of distinct integers
void permute(vector<int>& nums, int start, vector<vector<int>>& res) {
    if (start == (int)nums.size()) { res.push_back(nums); return; }
    for (int i = start; i < (int)nums.size(); i++) {
        swap(nums[start], nums[i]);
        permute(nums, start + 1, res);
        swap(nums[start], nums[i]); // backtrack
    }
}
int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res;
    permute(nums, 0, res);
    for (auto& p : res) { for (int x : p) cout << x << " "; cout << "\n"; }
}
