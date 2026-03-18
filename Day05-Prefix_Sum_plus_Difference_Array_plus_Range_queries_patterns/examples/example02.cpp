/*
 * Example 2: Kadane Maximum Subarray (Prefix Sum plus Difference Array plus Range queries patterns)
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> a = {-2,1,-3,4,-1,2,1,-5,4};
    int maxSum=INT_MIN, curSum=0, start=0, end=0, tempStart=0;
    for(int i=0;i<(int)a.size();i++){
        curSum+=a[i];
        if(curSum>maxSum){ maxSum=curSum; start=tempStart; end=i; }
        if(curSum<0){ curSum=0; tempStart=i+1; }
    }
    cout << "Max subarray sum: " << maxSum << "\n";  // 6
    cout << "Subarray [" << start << "," << end << "]: ";
    for(int i=start;i<=end;i++) cout<<a[i]<<" "; cout<<"\n";
    return 0;
}
