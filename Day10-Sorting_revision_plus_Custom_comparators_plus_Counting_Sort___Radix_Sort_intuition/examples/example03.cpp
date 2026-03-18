/*
 * Example 3: Merge Sorted Arrays
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> mergeSorted(vector<int>&a,vector<int>&b){
    vector<int> res; int i=0,j=0;
    while(i<(int)a.size()&&j<(int)b.size()){if(a[i]<=b[j])res.push_back(a[i++]);else res.push_back(b[j++]);}
    while(i<(int)a.size()) res.push_back(a[i++]);
    while(j<(int)b.size()) res.push_back(b[j++]);
    return res;
}
int main(){
    vector<int> a={1,3,5,7},b={2,4,6,8};
    for(int x:mergeSorted(a,b)) cout<<x<<" "; cout<<"\n";
    return 0;
}
