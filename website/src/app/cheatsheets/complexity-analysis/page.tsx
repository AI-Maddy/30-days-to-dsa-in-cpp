import React from "react";
import { FaChartLine } from "react-icons/fa";

export default function ComplexityAnalysisCheatsheet() {
  return (
    <div className="prose max-w-2xl mx-auto p-6 bg-white/90 rounded-xl shadow-lg mt-8">
      <h1 className="flex items-center gap-2 text-red-600"><FaChartLine /> Complexity Analysis Cheatsheet</h1>
      <div className="bg-indigo-100 border-l-4 border-indigo-500 text-indigo-900 p-4 mb-4 rounded">
        <strong>🧠 Memory Aid:</strong> O(1) &lt; O(log n) &lt; O(n) &lt; O(n log n) &lt; O(n²) &lt; O(2ⁿ) &lt; O(n!). <span className="text-emerald-700">Ask: what is n? What loop structure drives the complexity?</span>
      </div>
      <h2>📖 Big-O Notation</h2>
      <pre className="bg-zinc-100 p-2 rounded text-xs overflow-x-auto"><code>{`// O(1): Hash lookup, array index
// O(log n): Binary search, BST ops
// O(n): Single loop, linear scan
// O(n log n): Merge sort, heap sort
// O(n²): Nested loops, bubble sort`}</code></pre>
      {/* ...more content can be added here... */}
    </div>
  );
}
