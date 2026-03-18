/*
 * Example 4: First and Last Occurrence
 */
#include <bits/stdc++.h>
using namespace std;
pair<int,int> firstLast(vector<int>&a,int t){
    int l=0,r=a.size()-1,first=-1,last=-1;
    while(l<=r){int m=l+(r-l)/2;if(a[m]==t){first=m;r=m-1;}else if(a[m]<t)l=m+1;else r=m-1;}
    l=0;r=a.size()-1;
    while(l<=r){int m=l+(r-l)/2;if(a[m]==t){last=m;l=m+1;}else if(a[m]<t)l=m+1;else r=m-1;}
    return{first,last};
}
int main(){
    vector<int> a={5,7,7,8,8,10}; auto[f,l]=firstLast(a,8);
    cout<<f<<" "<<l<<"\n"; // 3 4
    return 0;
}
