/*
 * Example 3: Jump Game I
 */
#include <bits/stdc++.h>
using namespace std;
// Example 3: Jump Game I — can you reach the last index?
bool canJump(vector<int>& nums) {
    int maxReach = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (i > maxReach) return false; // current index unreachable
        maxReach = max(maxReach, i + nums[i]);
    }
    return true;
}
int main() {
    vector<int> nums1 = {2,3,1,1,4}; cout << canJump(nums1) << "\n"; // 1
    vector<int> nums2 = {3,2,1,0,4}; cout << canJump(nums2) << "\n"; // 0
}
