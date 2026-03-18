/*
 * Solution 1: Search in Rotated Array
 */
#include <bits/stdc++.h>
using namespace std;
int searchRotated(vector<int>&a,int t){
    int l=0,r=a.size()-1;
    while(l<=r){int m=l+(r-l)/2;if(a[m]==t)return m;
        if(a[l]<=a[m]){if(a[l]<=t&&t<a[m])r=m-1;else l=m+1;}
        else{if(a[m]<t&&t<=a[r])l=m+1;else r=m-1;}}
    return -1;
}
int main(){
    vector<int> a={4,5,6,7,0,1,2};
    cout<<searchRotated(a,0)<<"\n"; // 4
    cout<<searchRotated(a,3)<<"\n"; // -1
    return 0;
}
