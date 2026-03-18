/*
 * Solution 2: Fractional Knapsack
 */
#include <bits/stdc++.h>
using namespace std;
struct Item{int w,v;};
double fractionalKnapsack(int cap,vector<Item>&items){
    sort(items.begin(),items.end(),[](const Item&a,const Item&b){return (double)a.v/a.w>(double)b.v/b.w;});
    double total=0;
    for(auto&it:items){if(cap>=it.w){total+=it.v;cap-=it.w;}else{total+=(double)it.v*cap/it.w;break;}}
    return total;
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<Item>items={{10,60},{20,100},{30,120}};
    cout<<fixed<<setprecision(2)<<fractionalKnapsack(50,items)<<"\n";}
