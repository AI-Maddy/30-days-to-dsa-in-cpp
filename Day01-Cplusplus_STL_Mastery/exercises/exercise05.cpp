/*
 * Exercise 5: Priority Queue Top-K (Cplusplus STL Mastery)
 */
// Problem: Given n integers, find the kth largest element.
// Input: n, k, then n integers.
// Output: kth largest value.
//
// Hint: Maintain a min-heap of size k.
//   - Push each element; if heap size > k, pop the minimum.
//   - After processing all, heap.top() is the kth largest.
// Complexity: O(n log k) time, O(k) space.
#include <bits/stdc++.h>
using namespace std;

int kthLargest(vector<int>& nums, int k) {
    // TODO: implement using min-heap of size k
    return -1;
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (int& x : nums) cin >> x;
    cout << kthLargest(nums, k) << "\n";
    return 0;
}
