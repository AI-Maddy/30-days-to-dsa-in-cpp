/*
 * Example 3: Sliding Window Sum (Prefix Sum plus Difference Array plus Range queries patterns)
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> a = {1,3,-1,-3,5,3,6,7};
    int k=3, maxSum=INT_MIN, windowSum=0;
    int bestStart=0;
    for(int i=0;i<(int)a.size();i++){
        windowSum+=a[i];
        if(i>=k) windowSum-=a[i-k];
        if(i>=k-1 && windowSum>maxSum){ maxSum=windowSum; bestStart=i-k+1; }
    }
    cout << "Max sum window of size " << k << ": " << maxSum << "\n";
    cout << "Window starts at index " << bestStart << ": ";
    for(int i=bestStart;i<bestStart+k;i++) cout<<a[i]<<" "; cout<<"\n";
    return 0;
}
