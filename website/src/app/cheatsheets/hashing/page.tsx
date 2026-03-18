import React from "react";
import { FaHashtag } from "react-icons/fa";

export default function HashingCheatsheet() {
  return (
    <div className="prose max-w-2xl mx-auto p-6 bg-white/90 rounded-xl shadow-lg mt-8">
      <h1 className="flex items-center gap-2 text-orange-500"><FaHashtag /> Hashing Cheatsheet</h1>
      <div className="bg-indigo-100 border-l-4 border-indigo-500 text-indigo-900 p-4 mb-4 rounded">
        <strong>🧠 Memory Aid:</strong> Hash maps turn O(n) lookups into O(1). Key patterns: frequency, complement lookup, prefix sum + map. <span className="text-emerald-700">When you need "have I seen X before?" → use hash map/set.</span>
      </div>
      <h2>#️⃣ unordered_map vs map</h2>
      <pre className="bg-zinc-100 p-2 rounded text-xs overflow-x-auto"><code>{`unordered_map<int,int> ump; // O(1) avg, no ordering
map<int,int> mp; // O(log n), sorted keys
ump[key]++; // insert or increment
ump.count(key); // 0 or 1 — existence check`}</code></pre>
      {/* ...more content can be added here... */}
    </div>
  );
}
