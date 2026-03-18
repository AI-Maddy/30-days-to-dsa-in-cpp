/*
 * Solution 4: 0-1 Knapsack
 */
#include <bits/stdc++.h>
using namespace std;
int knapsack(vector<int>&wt,vector<int>&val,int W){
    int n=wt.size();vector<int>dp(W+1,0);
    for(int i=0;i<n;i++)for(int w=W;w>=wt[i];w--)dp[w]=max(dp[w],dp[w-wt[i]]+val[i]);
    return dp[W];
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<int>wt={1,3,4,5},val={1,4,5,7};cout<<knapsack(wt,val,7)<<"\n";}
