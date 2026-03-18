import React from "react";
import { FaSearch } from "react-icons/fa";

export default function BinarySearchCheatsheet() {
  return (
    <div className="prose max-w-2xl mx-auto p-6 bg-white/90 rounded-xl shadow-lg mt-8">
      <h1 className="flex items-center gap-2 text-blue-600"><FaSearch /> Binary Search Cheatsheet</h1>
      <div className="bg-indigo-100 border-l-4 border-indigo-500 text-indigo-900 p-4 mb-4 rounded">
        <strong>🧠 Memory Aid:</strong> Binary search works on any monotonic condition, not just sorted arrays. <span className="text-emerald-700">Template: lo=min, hi=max, check feasibility(mid), shrink range.</span>
      </div>
      <h2>📌 Standard Template</h2>
      <pre className="bg-zinc-100 p-2 rounded text-xs overflow-x-auto"><code>{`// Find exact target in sorted array — O(log n)
int binarySearch(vector<int>& a, int target) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;   // avoid overflow
        if (a[mid] == target) return mid;
        else if (a[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}`}</code></pre>
      {/* ...more content can be added here... */}
    </div>
  );
}
