import React from "react";
import { FaListOl } from "react-icons/fa";

export default function ArraysCheatsheet() {
  return (
    <div className="prose max-w-2xl mx-auto p-6 bg-white/90 rounded-xl shadow-lg mt-8">
      <h1 className="flex items-center gap-2 text-pink-600"><FaListOl /> Arrays Cheatsheet</h1>
      <div className="bg-indigo-100 border-l-4 border-indigo-500 text-indigo-900 p-4 mb-4 rounded">
        <strong>🧠 Memory Aid:</strong> Two pointers: start both ends, move inward. Sliding window: expand right, shrink left. <span className="text-emerald-700">Prefix sum: precompute to answer range queries in O(1).</span>
      </div>
      <h2>👉 Two Pointers Pattern</h2>
      <pre className="bg-zinc-100 p-2 rounded text-xs overflow-x-auto"><code>{`// Two Sum in sorted array
int l = 0, r = n - 1;
while (l < r) {
    int sum = a[l] + a[r];
    if (sum == target) { /* found */ break; }
    else if (sum < target) l++;
    else r--;
}`}</code></pre>
      <pre className="bg-zinc-100 p-2 rounded text-xs overflow-x-auto"><code>{`// Trapping Rain Water
int l = 0, r = n-1, lMax = 0, rMax = 0, water = 0;
while (l < r) {
    if (a[l] < a[r]) {
        lMax = max(lMax, a[l]);
        water += lMax - a[l]; l++;
    } else {
        rMax = max(rMax, a[r]);`}</code></pre>
      {/* ...more content can be added here... */}
    </div>
  );
}
