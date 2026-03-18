/*
 * Solution 4: Find Rotation Count
 */
#include <bits/stdc++.h>
using namespace std;
// Number of rotations = index of minimum element
int rotationCount(vector<int>&a){
    int l=0,r=a.size()-1;
    while(l<r){int m=l+(r-l)/2;if(a[m]>a[r])l=m+1;else r=m;}
    return l;
}
int main(){
    vector<int> a={15,18,2,3,6,12}; cout<<rotationCount(a)<<"\n"; // 2
    vector<int> b={7,9,11,12,5}; cout<<rotationCount(b)<<"\n"; // 4
    return 0;
}
