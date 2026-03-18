/*
 * Example 1: Insertion Sort Pass
 */
#include <bits/stdc++.h>
using namespace std;
void insertionSort(vector<int>&a){
    int n=a.size();
    for(int i=1;i<n;i++){int key=a[i],j=i-1;while(j>=0&&a[j]>key){a[j+1]=a[j];j--;}a[j+1]=key;}
}
int main(){
    vector<int> a={5,2,8,1,9,3}; insertionSort(a);
    for(int x:a) cout<<x<<" "; cout<<"\n"; // 1 2 3 5 8 9
    return 0;
}
