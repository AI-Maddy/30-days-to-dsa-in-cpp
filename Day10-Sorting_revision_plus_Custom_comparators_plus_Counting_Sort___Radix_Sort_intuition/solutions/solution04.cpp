/*
 * Solution 4: Sort Pairs
 */
#include <bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int&x:a)cin>>x;int lo=0,mid=0,hi=n-1;while(mid<=hi){if(a[mid]==0)swap(a[lo++],a[mid++]);else if(a[mid]==1)mid++;else swap(a[mid],a[hi--]);}for(int x:a)cout<<x<<" ";cout<<"\n";return 0;}
