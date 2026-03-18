/*
 * Solution 2: Group Anagrams (Hashing)
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,t; cin>>s>>t;
    auto f=[](string x){sort(x.begin(),x.end());return x;};
    cout<<(f(s)==f(t)?"YES":"NO")<<"\n"; return 0;
}
