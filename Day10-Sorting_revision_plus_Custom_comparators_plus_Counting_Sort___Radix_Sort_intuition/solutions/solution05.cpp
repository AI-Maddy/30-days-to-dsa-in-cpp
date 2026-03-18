/*
 * Solution 5: Sort by Frequency
 */
#include <bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<string>v(n);for(auto&s:v)cin>>s;sort(v.begin(),v.end(),[](auto&a,auto&b){return a.size()!=b.size()?a.size()<b.size():a<b;});for(auto&s:v)cout<<s<<"\n";return 0;}
