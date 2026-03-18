/*
 * Example 4: Jump Game II
 */
#include <bits/stdc++.h>
using namespace std;
// Example 4: Jump Game II — minimum jumps to reach last index
int jump(vector<int>& nums) {
    int jumps = 0, curEnd = 0, farthest = 0, n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        farthest = max(farthest, i + nums[i]);
        if (i == curEnd) { // must jump
            jumps++;
            curEnd = farthest;
            if (curEnd >= n - 1) break;
        }
    }
    return jumps;
}
int main() {
    vector<int> nums = {2,3,1,1,4}; cout << jump(nums) << "\n"; // 2
    vector<int> nums2 = {2,3,0,1,4}; cout << jump(nums2) << "\n"; // 2
}
