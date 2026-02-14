/*
 * Example 9: Next Greater Element using Stack
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    vector<int> nums = {1, 3, 2, 4};
    vector<int> result(nums.size(), -1);
    stack<int> st;
    
    for (int i = nums.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] = st.top();
        }
        st.push(nums[i]);
    }
    
    cout << "Next Greater Elements: ";
    for (int x : result) cout << x << " ";
    cout << endl;
    
    return 0;
}
