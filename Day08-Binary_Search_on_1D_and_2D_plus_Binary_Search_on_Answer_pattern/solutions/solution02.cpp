/*
 * Solution 2: Lower and Upper Bound
 */
#include <bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int&x:a)cin>>x;int l=0,r=n-1;while(l<r){int m=l+(r-l)/2;if(a[m]>a[r])l=m+1;else r=m;}cout<<a[l]<<"\n";return 0;}
