/*
 * Solution 3: Valid Parentheses
 */
#include <bits/stdc++.h>
using namespace std;
void genParens(int n,int op,int cl,string cur,vector<string>&res){
    if((int)cur.size()==2*n){res.push_back(cur);return;}
    if(op<n)genParens(n,op+1,cl,cur+"(",res);
    if(cl<op)genParens(n,op,cl+1,cur+")",res);
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<string>res;genParens(3,0,0,"",res);for(auto&s:res)cout<<s<<"\n";}
