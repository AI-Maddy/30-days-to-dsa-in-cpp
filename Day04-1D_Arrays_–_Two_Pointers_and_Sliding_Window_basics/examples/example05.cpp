/*
 * Example 5: Minimum Window Substring (1D Arrays – Two Pointers and Sliding Window basics)
 */
// Sliding window: expand right until valid, then shrink left as much as possible.
// O(|s| + |t|) time, O(|t|) space.
#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char,int> need, have;
    for (char c : t) need[c]++;
    int formed=0, required=(int)need.size();
    int l=0, minLen=INT_MAX, minStart=0;

    for (int r=0; r<(int)s.size(); r++) {
        char c = s[r];
        have[c]++;
        if (need.count(c) && have[c]==need[c]) formed++;

        // Shrink window from left while all required chars are present
        while (formed == required) {
            if (r-l+1 < minLen) { minLen=r-l+1; minStart=l; }
            char lc = s[l];
            have[lc]--;
            if (need.count(lc) && have[lc]<need[lc]) formed--;
            l++;
        }
    }
    return minLen==INT_MAX ? "" : s.substr(minStart, minLen);
}

int main() {
    cout << minWindow("ADOBECODEBANC","ABC") << "\n";  // "BANC"
    cout << minWindow("a","a") << "\n";                // "a"
    cout << minWindow("a","aa") << "\n";               // "" (impossible)
    return 0;
}
