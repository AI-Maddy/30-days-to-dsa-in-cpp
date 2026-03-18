import React from "react";
import { FaLightbulb } from "react-icons/fa";

export default function DynamicProgrammingCheatsheet() {
  return (
    <div className="prose max-w-2xl mx-auto p-6 bg-white/90 rounded-xl shadow-lg mt-8">
      <h1 className="flex items-center gap-2 text-yellow-500"><FaLightbulb /> Dynamic Programming Cheatsheet</h1>
      <div className="bg-indigo-100 border-l-4 border-indigo-500 text-indigo-900 p-4 mb-4 rounded">
        <strong>🧠 Memory Aid:</strong> DP = overlapping subproblems + optimal substructure. State → Transition → Base Case. <span className="text-emerald-700">Write recurrence first, then code. Optimize space last.</span>
      </div>
      <h2>🧠 DP Mental Model</h2>
      <pre className="bg-zinc-100 p-2 rounded text-xs overflow-x-auto"><code>{`// 1. Define state: dp[i] = ?
// 2. Write transition: dp[i] = f(dp[i-1], dp[i-2], ...)
// 3. Set base cases: dp[0], dp[1], ...
// 4. Answer: usually dp[n] or max/min over dp`}</code></pre>
      {/* ...more content can be added here... */}
    </div>
  );
}
