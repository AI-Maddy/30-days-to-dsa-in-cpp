/*
 * Solution 1: Fibonacci Climbing Stairs House Robber
 */
#include <bits/stdc++.h>
using namespace std;
int rob(vector<int>&nums){int p2=0,p1=0;for(int x:nums){int c=max(p1,p2+x);p2=p1;p1=c;}return p1;}
int climbStairs(int n){if(n<=2)return n;int a=1,b=2;for(int i=3;i<=n;i++){int c=a+b;a=b;b=c;}return b;}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<int>h={2,7,9,3,1};cout<<rob(h)<<"\n";cout<<climbStairs(5)<<"\n";}
