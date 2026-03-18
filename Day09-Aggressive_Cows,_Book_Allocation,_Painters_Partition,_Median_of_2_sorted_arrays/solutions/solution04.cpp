/*
 * Solution 4: First Occurrence (BS Answer)
 */
#include <bits/stdc++.h>
using namespace std;
// Median of two sorted arrays — O(log(min(m,n)))
double findMedian(vector<int>&a,vector<int>&b){
    if(a.size()>b.size()) return findMedian(b,a);
    int m=a.size(),n=b.size(),lo=0,hi=m;
    while(lo<=hi){
        int pa=lo+(hi-lo)/2,pb=(m+n+1)/2-pa;
        int aleft=pa?a[pa-1]:INT_MIN, aright=pa<m?a[pa]:INT_MAX;
        int bleft=pb?b[pb-1]:INT_MIN, bright=pb<n?b[pb]:INT_MAX;
        if(aleft<=bright&&bleft<=aright){
            if((m+n)%2) return max(aleft,bleft);
            return(max(aleft,bleft)+min(aright,bright))/2.0;
        }else if(aleft>bright) hi=pa-1;
        else lo=pa+1;
    }
    return -1;
}
int main(){
    vector<int> a={1,3},b={2};cout<<findMedian(a,b)<<"\n"; // 2.0
    vector<int> c={1,2},d={3,4};cout<<findMedian(c,d)<<"\n"; // 2.5
    return 0;
}
