/*
 * Solution 5: Search Rotated with Duplicates
 */
#include <bits/stdc++.h>
using namespace std;
// With duplicates: worst case O(n)
bool searchWithDups(vector<int>&a,int t){
    int l=0,r=a.size()-1;
    while(l<=r){int m=l+(r-l)/2;if(a[m]==t)return true;
        if(a[l]==a[m]&&a[m]==a[r]){l++;r--;}
        else if(a[l]<=a[m]){if(a[l]<=t&&t<a[m])r=m-1;else l=m+1;}
        else{if(a[m]<t&&t<=a[r])l=m+1;else r=m-1;}}
    return false;
}
int main(){
    vector<int> a={2,5,6,0,0,1,2};
    cout<<searchWithDups(a,0)<<"\n"; // 1
    cout<<searchWithDups(a,3)<<"\n"; // 0
    return 0;
}
