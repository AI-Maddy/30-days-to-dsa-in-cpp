import React from "react";
import { FaUndo } from "react-icons/fa";

export default function RecursionBacktrackingCheatsheet() {
  return (
    <div className="prose max-w-2xl mx-auto p-6 bg-white/90 rounded-xl shadow-lg mt-8">
      <h1 className="flex items-center gap-2 text-pink-700"><FaUndo /> Recursion & Backtracking Cheatsheet</h1>
      <div className="bg-indigo-100 border-l-4 border-indigo-500 text-indigo-900 p-4 mb-4 rounded">
        <strong>🧠 Memory Aid:</strong> Backtracking = choose, explore, unchoose. Always undo what you did. <span className="text-emerald-700">Prune: skip invalid choices early to avoid exploring dead branches.</span>
      </div>
      <h2>🔁 Recursion Mental Model</h2>
      <pre className="bg-zinc-100 p-2 rounded text-xs overflow-x-auto"><code>{`// 1. Base case: smallest valid input → return directly
// 2. Recursive case: reduce to smaller subproblem
// 3. Combine: use subproblem result to build answer`}</code></pre>
      {/* ...more content can be added here... */}
    </div>
  );
}
