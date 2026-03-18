/*
 * Solution 2: Coin Change
 */
#include <bits/stdc++.h>
using namespace std;
int coinChange(vector<int>&coins,int amount){
    vector<int>dp(amount+1,INT_MAX);dp[0]=0;
    for(int i=1;i<=amount;i++)for(int c:coins)if(c<=i&&dp[i-c]!=INT_MAX)dp[i]=min(dp[i],dp[i-c]+1);
    return dp[amount]==INT_MAX?-1:dp[amount];
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<int>coins={1,5,6,9};cout<<coinChange(coins,11)<<"\n";}
