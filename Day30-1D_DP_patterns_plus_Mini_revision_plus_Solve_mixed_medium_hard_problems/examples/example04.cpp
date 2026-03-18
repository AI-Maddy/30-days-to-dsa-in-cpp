/*
 * Example 4: 0-1 Knapsack
 */
#include <bits/stdc++.h>
using namespace std;
// Example 4: 0/1 Knapsack
// dp[i][w] = max value using first i items with capacity w
int knapsack(vector<int>& wt, vector<int>& val, int W) {
    int n = wt.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    for (int i = 1; i <= n; i++)
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i-1][w];
            if (wt[i-1] <= w) dp[i][w] = max(dp[i][w], dp[i-1][w-wt[i-1]] + val[i-1]);
        }
    return dp[n][W];
}
// Space-optimized O(W)
int knapsack1D(vector<int>& wt, vector<int>& val, int W) {
    int n = wt.size();
    vector<int> dp(W+1, 0);
    for (int i = 0; i < n; i++)
        for (int w = W; w >= wt[i]; w--)
            dp[w] = max(dp[w], dp[w-wt[i]] + val[i]);
    return dp[W];
}
int main() {
    vector<int> wt={1,3,4,5}, val={1,4,5,7}; int W=7;
    cout << knapsack(wt, val, W) << "\n";   // 9
    cout << knapsack1D(wt, val, W) << "\n"; // 9
}
