/*
 * Solution 2: N-Queens Bitmask
 */
#include <bits/stdc++.h>
using namespace std;
int cnt=0;
void nq(int row,int n,int cols,int d1,int d2){
    if(row==n){cnt++;return;}
    int avail=((1<<n)-1)&~(cols|d1|d2);
    while(avail){int bit=avail&(-avail);avail&=avail-1;nq(row+1,n,cols|bit,(d1|bit)<<1,(d2|bit)>>1);}
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    nq(0,8,0,0,0);cout<<cnt<<"\n";}
