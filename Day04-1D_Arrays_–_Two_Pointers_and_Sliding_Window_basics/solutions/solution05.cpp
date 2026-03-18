/*
 * Solution 5: Minimum Window Substring (1D Arrays – Two Pointers and Sliding Window basics)
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s,t; cin>>s>>t;
    unordered_map<char,int> need,have;
    for(char c:t)need[c]++;
    int formed=0,req=need.size(),l=0,ml=INT_MAX,ms=0;
    for(int r=0;r<(int)s.size();r++){
        have[s[r]]++;
        if(need.count(s[r])&&have[s[r]]==need[s[r]])formed++;
        while(formed==req){if(r-l+1<ml){ml=r-l+1;ms=l;}
            if(need.count(s[l])&&--have[s[l]]<need[s[l]])formed--;
            else have[s[l]]--;l++;}
    }
    cout<<(ml==INT_MAX?"":s.substr(ms,ml))<<"\n"; return 0;
}
