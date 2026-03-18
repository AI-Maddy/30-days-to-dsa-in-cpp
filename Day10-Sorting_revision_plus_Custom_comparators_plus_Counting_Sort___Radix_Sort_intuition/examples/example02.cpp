/*
 * Example 2: Selection Sort Pass
 */
#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector<int>&a){
    int n=a.size();
    for(int i=0;i<n-1;i++){int mn=i;for(int j=i+1;j<n;j++)if(a[j]<a[mn])mn=j;swap(a[i],a[mn]);}
}
int main(){
    vector<int> a={64,25,12,22,11}; selectionSort(a);
    for(int x:a) cout<<x<<" "; cout<<"\n"; // 11 12 22 25 64
    return 0;
}
