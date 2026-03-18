/*
 * Example 5: Priority Queue Top-K (Cplusplus STL Mastery)
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Max-heap (default) — largest element at top
    priority_queue<int> maxpq;
    for (int x : {3, 1, 4, 1, 5, 9, 2, 6}) maxpq.push(x);
    cout << "Max-heap top-3: ";
    for (int i = 0; i < 3; i++) {
        cout << maxpq.top() << " ";
        maxpq.pop();
    }
    cout << "\n";

    // Min-heap — smallest element at top
    priority_queue<int, vector<int>, greater<int>> minpq;
    for (int x : {3, 1, 4, 1, 5, 9, 2, 6}) minpq.push(x);
    cout << "Min-heap top-3: ";
    for (int i = 0; i < 3; i++) {
        cout << minpq.top() << " ";
        minpq.pop();
    }
    cout << "\n";

    // Find top-K largest elements using min-heap of size K
    // Space O(k), Time O(n log k)
    vector<int> nums = {7, 10, 4, 3, 20, 15, 8, 1};
    int K = 4;
    priority_queue<int, vector<int>, greater<int>> heap;  // min-heap
    for (int x : nums) {
        heap.push(x);
        if ((int)heap.size() > K) heap.pop();  // evict smallest
    }
    // heap now contains K largest; top = Kth largest
    cout << "\nTop-" << K << " largest: ";
    vector<int> topK;
    while (!heap.empty()) { topK.push_back(heap.top()); heap.pop(); }
    sort(topK.rbegin(), topK.rend());
    for (int x : topK) cout << x << " "; cout << "\n";
    cout << K << "th largest element: " << topK.back() << "\n";

    // Priority queue with pairs (custom ordering)
    // Task scheduling: {priority, task_name}
    priority_queue<pair<int,string>> tasks;
    tasks.push({3, "low"});
    tasks.push({10, "high"});
    tasks.push({7, "medium"});
    cout << "\nTask order by priority:\n";
    while (!tasks.empty()) {
        auto [pri, name] = tasks.top(); tasks.pop();
        cout << "  priority=" << pri << " task=" << name << "\n";
    }

    return 0;
}
