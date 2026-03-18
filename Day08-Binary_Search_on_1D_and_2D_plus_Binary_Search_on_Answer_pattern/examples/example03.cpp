/*
 * Example 3: Peak Element
 */
#include <bits/stdc++.h>
using namespace std;
int findPeak(vector<int>&a){int l=0,r=a.size()-1;while(l<r){int m=l+(r-l)/2;if(a[m]<a[m+1])l=m+1;else r=m;}return l;}
int main(){
    vector<int> a={1,2,3,1}; cout<<findPeak(a)<<"\n"; // 2
    vector<int> b={1,2,1,3,5,6,4}; cout<<findPeak(b)<<"\n"; // 5
    return 0;
}
