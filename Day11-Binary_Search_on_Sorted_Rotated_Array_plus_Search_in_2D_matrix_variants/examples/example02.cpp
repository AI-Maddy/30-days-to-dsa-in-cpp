/*
 * Example 2: Min in Rotated Array
 */
#include <bits/stdc++.h>
using namespace std;
int findMin(vector<int>&a){
    int l=0,r=a.size()-1;
    while(l<r){int m=l+(r-l)/2;if(a[m]>a[r])l=m+1;else r=m;}
    return a[l];
}
int main(){
    vector<int> a={3,4,5,1,2}; cout<<findMin(a)<<"\n"; // 1
    vector<int> b={4,5,6,7,0,1,2}; cout<<findMin(b)<<"\n"; // 0
    return 0;
}
