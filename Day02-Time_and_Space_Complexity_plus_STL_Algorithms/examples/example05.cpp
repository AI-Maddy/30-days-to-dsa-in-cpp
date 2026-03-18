/*
 * Example 5: Priority Queue Top-K (Time and Space Complexity plus STL Algorithms)
 */
// Demonstrates make_heap, push_heap, pop_heap, sort_heap, nth_element.
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {3,1,4,1,5,9,2,6,5,3};

    // make_heap — O(n), turns vector into max-heap in-place
    make_heap(v.begin(), v.end());
    cout << "After make_heap, front (max): " << v.front() << "\n";

    // push_heap — O(log n), adds element (push to vector first)
    v.push_back(10);
    push_heap(v.begin(), v.end());
    cout << "After push 10, max: " << v.front() << "\n";

    // pop_heap — O(log n), moves max to back, then pop_back to remove
    pop_heap(v.begin(), v.end());
    int maxVal = v.back(); v.pop_back();
    cout << "Popped: " << maxVal << "  new max: " << v.front() << "\n";

    // sort_heap — O(n log n), sorts a heap in ascending order
    sort_heap(v.begin(), v.end());
    cout << "sort_heap: "; for(int x:v) cout<<x<<" "; cout<<"\n";

    // nth_element — O(n) average, kth smallest in any order
    vector<int> u = {7,3,1,9,2,5,8,4,6};
    int k = 3;  // 0-indexed: 4th smallest
    nth_element(u.begin(), u.begin()+k, u.end());
    cout << "\nnth_element(" << k << "): " << u[k] << " (4th smallest)\n";
    cout << "Elements <= u[k]: ";
    for(int i=0;i<k;i++) cout<<u[i]<<" "; cout<<"\n";

    return 0;
}
