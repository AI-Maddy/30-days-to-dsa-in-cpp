/*
 * Example 2: Coin Change
 */
#include <bits/stdc++.h>
using namespace std;
// Example 2: Coin Change (min coins to make amount)
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != INT_MAX)
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}
// Coin Change II (number of ways)
int coinChangeWays(vector<int>& coins, int amount) {
    vector<long long> dp(amount + 1, 0);
    dp[0] = 1;
    for (int coin : coins)
        for (int i = coin; i <= amount; i++)
            dp[i] += dp[i - coin];
    return dp[amount];
}
int main() {
    vector<int> coins = {1,5,6,9}; int amount = 11;
    cout << coinChange(coins, amount) << "\n"; // 2 (two 5s + one coin = no, best: 6+5=11 = 2 coins)
    cout << coinChangeWays(coins, amount) << "\n";
}
