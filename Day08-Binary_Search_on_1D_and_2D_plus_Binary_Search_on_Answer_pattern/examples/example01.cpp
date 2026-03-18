/*
 * Example 1: Classic Binary Search
 */
#include <bits/stdc++.h>
using namespace std;
int bsearch(vector<int>& a, int t){ int l=0,r=a.size()-1; while(l<=r){int m=l+(r-l)/2;if(a[m]==t)return m;else if(a[m]<t)l=m+1;else r=m-1;} return -1;}
int main(){
    vector<int> a={1,3,5,7,9,11,13,15,17,19};
    cout<<bsearch(a,7)<<"\n";   // 3
    cout<<bsearch(a,10)<<"\n";  // -1
    return 0;
}
