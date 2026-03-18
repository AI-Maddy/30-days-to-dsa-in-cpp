/*
 * Solution 2: Map Frequency (Cplusplus STL Mastery)
 */
#include <bits/stdc++.h>
using namespace std;

char mostFrequent(string& s) {
    map<char,int> freq;  // sorted by char: tie-break is free
    for (char c : s) freq[c]++;
    char best = s[0]; int maxCnt = 0;
    for (auto& [c, cnt] : freq) {
        if (cnt > maxCnt) { maxCnt = cnt; best = c; }
    }
    return best;
}

int main() {
    string s; cin >> s;
    cout << mostFrequent(s) << "\n";
    return 0;
}
