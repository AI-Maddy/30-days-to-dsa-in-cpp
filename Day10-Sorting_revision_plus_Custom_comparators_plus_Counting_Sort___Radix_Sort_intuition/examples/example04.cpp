/*
 * Example 4: Sort Pairs
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    // Sort pairs by second element, then by first
    vector<pair<int,int>> v={{1,3},{2,1},{3,2},{4,1},{5,3}};
    sort(v.begin(),v.end(),[](auto&a,auto&b){return a.second!=b.second?a.second<b.second:a.first<b.first;});
    for(auto&[a,b]:v) cout<<"("<<a<<","<<b<<") "; cout<<"\n";
    return 0;
}
