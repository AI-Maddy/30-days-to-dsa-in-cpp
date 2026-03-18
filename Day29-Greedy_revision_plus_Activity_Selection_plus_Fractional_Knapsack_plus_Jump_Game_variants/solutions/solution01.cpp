/*
 * Solution 1: Activity Selection
 */
#include <bits/stdc++.h>
using namespace std;
int activitySelection(vector<pair<int,int>>&acts){
    sort(acts.begin(),acts.end(),[](auto&a,auto&b){return a.second<b.second;});
    int cnt=1,last=acts[0].second;
    for(int i=1;i<(int)acts.size();i++)if(acts[i].first>=last){cnt++;last=acts[i].second;}
    return cnt;
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<pair<int,int>>acts={{1,2},{3,4},{0,6},{5,7},{8,9},{5,9}};
    cout<<activitySelection(acts)<<"\n";}
