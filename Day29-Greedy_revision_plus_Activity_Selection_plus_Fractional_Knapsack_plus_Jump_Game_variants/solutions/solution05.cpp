/*
 * Solution 5: Min Platforms
 */
#include <bits/stdc++.h>
using namespace std;
int minPlatforms(vector<int>&arr,vector<int>&dep){
    int n=arr.size();sort(arr.begin(),arr.end());sort(dep.begin(),dep.end());
    int plat=1,maxP=1,i=1,j=0;
    while(i<n&&j<n){if(arr[i]<=dep[j]){plat++;i++;}else{plat--;j++;}maxP=max(maxP,plat);}
    return maxP;
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<int>arr={900,940,950,1100,1500,1800},dep={910,1200,1120,1130,1900,2000};
    cout<<minPlatforms(arr,dep)<<"\n";}
