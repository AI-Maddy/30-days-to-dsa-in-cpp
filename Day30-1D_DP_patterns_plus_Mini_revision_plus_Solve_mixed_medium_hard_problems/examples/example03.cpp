/*
 * Example 3: LIS O(nlogn)
 */
#include <bits/stdc++.h>
using namespace std;
// Example 3: Longest Increasing Subsequence (LIS)
// O(n^2) DP
int lisDP(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
    return *max_element(dp.begin(), dp.end());
}
// O(n log n) patience sorting
int lisOptimal(vector<int>& nums) {
    vector<int> tails;
    for (int x : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return tails.size();
}
int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << lisDP(nums) << "\n";      // 4
    cout << lisOptimal(nums) << "\n"; // 4
}
