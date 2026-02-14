/*
 * Example 5: Dynamic Programming - Fibonacci Numbers
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 10;
    vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    cout << "First " << n + 1 << " Fibonacci numbers: ";
    for (int i = 0; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
    
    return 0;
}
