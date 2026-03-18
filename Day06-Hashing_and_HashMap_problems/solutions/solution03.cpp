/*
 * Solution 3: Top K Frequent (Hashing)
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    map<char,int> freq; for(char c:s) freq[c]++;
    for(char c:s) if(freq[c]==1){cout<<c<<"\n";return 0;}
    cout<<"-1\n"; return 0;
}
