/*
 * Example 2: Lower and Upper Bound
 */
#include <bits/stdc++.h>
using namespace std;
int lowerB(vector<int>&a,int t){int l=0,r=a.size();while(l<r){int m=l+(r-l)/2;if(a[m]<t)l=m+1;else r=m;}return l;}
int upperB(vector<int>&a,int t){int l=0,r=a.size();while(l<r){int m=l+(r-l)/2;if(a[m]<=t)l=m+1;else r=m;}return l;}
int main(){
    vector<int> a={1,2,2,3,3,3,4,5};
    cout<<"lower_bound(3): "<<lowerB(a,3)<<"\n"; // 3
    cout<<"upper_bound(3): "<<upperB(a,3)<<"\n"; // 6
    cout<<"count(3): "<<upperB(a,3)-lowerB(a,3)<<"\n"; // 3
    return 0;
}
