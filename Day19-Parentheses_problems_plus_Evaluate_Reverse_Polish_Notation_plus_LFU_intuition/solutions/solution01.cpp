/*
 * Solution 1: Valid Parentheses
 */
#include <bits/stdc++.h>
using namespace std;
vector<string> generate(int n){
    vector<string>res;
    function<void(string,int,int)>bt=[&](string s,int o,int c){
        if((int)s.size()==2*n){res.push_back(s);return;}
        if(o<n)bt(s+'(',o+1,c);
        if(c<o)bt(s+')',o,c+1);
    };
    bt("",0,0); return res;
}
int main(){for(auto&s:generate(3))cout<<s<<"\n";return 0;}
