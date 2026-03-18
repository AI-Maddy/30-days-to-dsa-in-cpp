import React from "react";
import { FaBolt } from "react-icons/fa";

export default function BitManipulationCheatsheet() {
  return (
    <div className="prose max-w-2xl mx-auto p-6 bg-white/90 rounded-xl shadow-lg mt-8">
      <h1 className="flex items-center gap-2 text-yellow-600"><FaBolt /> Bit Manipulation Cheatsheet</h1>
      <div className="bg-indigo-100 border-l-4 border-indigo-500 text-indigo-900 p-4 mb-4 rounded">
        <strong>🧠 Memory Aid:</strong> AND clears, OR sets, XOR toggles. <span className="text-emerald-700">n & (n-1) clears rightmost set bit — used for popcount and power-of-2 checks.</span>
      </div>
      <h2>🔧 Bitwise Operators</h2>
      <pre className="bg-zinc-100 p-2 rounded text-xs overflow-x-auto"><code>{`// AND, OR, XOR, NOT, SHL, SHR
// 1010 & 1100 = 1000
// 1010 | 1100 = 1110
// 1010 ^ 1100 = 0110
// ~1010 = ...0101
// 1 << 3 = 8
// 16 >> 2 = 4`}</code></pre>
      {/* ...more content can be added here... */}
    </div>
  );
}
