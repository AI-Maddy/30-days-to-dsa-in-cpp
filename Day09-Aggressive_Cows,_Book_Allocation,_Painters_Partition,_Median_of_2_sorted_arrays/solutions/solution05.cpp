/*
 * Solution 5: Last Occurrence (BS Answer)
 */
#include <bits/stdc++.h>
using namespace std;
// Minimize max distance to gas station: add k stations
// Binary search on answer (double)
bool check(vector<int>&s,int k,double d){int cnt=0;for(int i=1;i<(int)s.size();i++)cnt+=(int)ceil((s[i]-s[i-1])/d)-1;return cnt<=k;}
double minGasStation(vector<int>&s,int k){double lo=0,hi=1e8;for(int i=0;i<100;i++){double mid=(lo+hi)/2;if(check(s,k,mid))hi=mid;else lo=mid;}return hi;}
int main(){
    vector<int> s={1,2,3,4,5,6,7,8,9,10};int k=9;
    cout<<fixed<<setprecision(6)<<minGasStation(s,k)<<"\n"; // 0.5
    return 0;
}
