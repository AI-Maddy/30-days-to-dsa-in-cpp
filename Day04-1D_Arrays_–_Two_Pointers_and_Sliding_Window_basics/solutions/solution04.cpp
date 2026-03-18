/*
 * Solution 4: Longest Substring Without Repeating (1D Arrays – Two Pointers and Sliding Window basics)
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin>>s;
    unordered_map<char,int> last; int l=0,ans=0;
    for(int r=0;r<(int)s.size();r++){
        if(last.count(s[r])&&last[s[r]]>=l) l=last[s[r]]+1;
        last[s[r]]=r; ans=max(ans,r-l+1);
    }
    cout<<ans<<"\n"; return 0;
}
