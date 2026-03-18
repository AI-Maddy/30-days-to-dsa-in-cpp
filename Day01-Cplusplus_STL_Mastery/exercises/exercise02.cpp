/*
 * Exercise 2: Map Frequency (Cplusplus STL Mastery)
 */
// Problem: Given a string, find the character with highest frequency.
// Tie-break: lexicographically smallest character wins.
// Input: one string on a line.
// Output: single character.
//
// Approach:
// 1) Build a frequency map (char -> count).
// 2) Find the char with max count. If tie, compare lexicographically.
// Complexity: O(n) time.
#include <bits/stdc++.h>
using namespace std;

char mostFrequent(string& s) {
    // TODO: build freq map, find max-freq char with lex tie-break
    return '?';
}

int main() {
    string s; cin >> s;
    cout << mostFrequent(s) << "\n";
    return 0;
}
