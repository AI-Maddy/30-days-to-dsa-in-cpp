/*
 * Example 1: Fibonacci Climbing Stairs House Robber
 */
#include <bits/stdc++.h>
using namespace std;
// Example 1: Classic 1D DP — Fibonacci, Climbing Stairs, House Robber
// Fibonacci with DP (bottom-up, O(1) space)
long long fib(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1;
    for (int i = 2; i <= n; i++) { long long c = a + b; a = b; b = c; }
    return b;
}
// Climbing stairs — number of ways to reach step n (1 or 2 steps at a time)
int climbStairs(int n) {
    if (n <= 2) return n;
    int a = 1, b = 2;
    for (int i = 3; i <= n; i++) { int c = a + b; a = b; b = c; }
    return b;
}
// House Robber — max rob without adjacent houses
int rob(vector<int>& nums) {
    int prev2 = 0, prev1 = 0;
    for (int x : nums) { int cur = max(prev1, prev2 + x); prev2 = prev1; prev1 = cur; }
    return prev1;
}
int main() {
    cout << fib(10) << "\n"; // 55
    cout << climbStairs(5) << "\n"; // 8
    vector<int> houses = {2,7,9,3,1};
    cout << rob(houses) << "\n"; // 12
}
