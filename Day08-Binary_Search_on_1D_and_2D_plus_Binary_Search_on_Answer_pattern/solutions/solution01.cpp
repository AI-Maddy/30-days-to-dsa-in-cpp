/*
 * Solution 1: Classic Binary Search
 */
#include <bits/stdc++.h>
using namespace std;
int main(){long long n;cin>>n;long long l=0,r=n;while(l<r){long long m=l+(r-l)/2+1;if(m*m<=n)l=m;else r=m-1;}cout<<l<<"\n";return 0;}
