/*
 * Example 4: Deque Operations (Cplusplus STL Mastery)
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // deque supports O(1) push/pop at both ends
    deque<int> dq;
    dq.push_back(3);  dq.push_back(4);  dq.push_back(5);
    dq.push_front(2); dq.push_front(1);
    cout << "deque (front to back): ";
    for (int x : dq) cout << x << " "; cout << "\n";

    cout << "front=" << dq.front() << "  back=" << dq.back() << "\n";
    dq.pop_front(); dq.pop_back();
    cout << "After pop_front + pop_back: ";
    for (int x : dq) cout << x << " "; cout << "\n";

    // Classic use: Sliding Window Maximum using monotonic deque
    // Window of size k — deque stores indices, front = index of max
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    deque<int> mono;  // stores indices
    vector<int> result;

    for (int i = 0; i < (int)nums.size(); i++) {
        // Remove indices outside window
        while (!mono.empty() && mono.front() < i - k + 1)
            mono.pop_front();
        // Maintain decreasing order: remove smaller elements from back
        while (!mono.empty() && nums[mono.back()] <= nums[i])
            mono.pop_back();
        mono.push_back(i);
        // Window has k elements starting from index k-1
        if (i >= k - 1)
            result.push_back(nums[mono.front()]);
    }

    cout << "\nSliding Window Max (k=" << k << "):\n";
    cout << "Input:  "; for (int x : nums)   cout << x << " "; cout << "\n";
    cout << "Output: "; for (int x : result) cout << x << " "; cout << "\n";

    return 0;
}
