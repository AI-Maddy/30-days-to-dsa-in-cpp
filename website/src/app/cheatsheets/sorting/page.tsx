import React from "react";
import { FaSort } from "react-icons/fa";

export default function SortingCheatsheet() {
  return (
    <div className="prose max-w-2xl mx-auto p-6 bg-white/90 rounded-xl shadow-lg mt-8">
      <h1 className="flex items-center gap-2 text-yellow-700"><FaSort /> Sorting Cheatsheet</h1>
      <div className="bg-indigo-100 border-l-4 border-indigo-500 text-indigo-900 p-4 mb-4 rounded">
        <strong>🧠 Memory Aid:</strong> For interviews: know merge sort and quick sort inside out. Use std::sort in practice. <span className="text-emerald-700">Stability matters when sorting by one key while preserving another.</span>
      </div>
      <h2>⏱️ Complexity Summary</h2>
      <pre className="bg-zinc-100 p-2 rounded text-xs overflow-x-auto"><code>{`// Merge Sort: O(n log n) time, O(n) space
// Quick Sort: O(n log n) avg, O(n^2) worst
// Heap Sort: O(n log n) time, O(1) space`}</code></pre>
      {/* ...more content can be added here... */}
    </div>
  );
}
