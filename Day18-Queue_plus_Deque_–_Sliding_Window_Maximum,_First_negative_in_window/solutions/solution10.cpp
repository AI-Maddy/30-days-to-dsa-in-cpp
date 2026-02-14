/*
 * Solution 10: Largest Rectangle in Histogram
 */
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            st.push(i);
        }
        
        while (!st.empty()) {
            int h = heights[st.top()];
            st.pop();
            int w = st.empty() ? (int)heights.size() : (int)heights.size() - st.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        
        return maxArea;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest rectangle area: " << sol.largestRectangleArea(heights) << endl;
    return 0;
}
