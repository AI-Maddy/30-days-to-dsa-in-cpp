/*
 * Solution 5: Priority Queue Top-K (Cplusplus STL Mastery)
 */
#include <bits/stdc++.h>
using namespace std;

int kthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;  // min-heap
    for (int x : nums) {
        minHeap.push(x);
        if ((int)minHeap.size() > k) minHeap.pop();
    }
    return minHeap.top();  // kth largest
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (int& x : nums) cin >> x;
    cout << kthLargest(nums, k) << "\n";
    return 0;
}
