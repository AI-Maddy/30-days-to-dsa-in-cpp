import React from "react";
import { FaCubes } from "react-icons/fa";

export default function CppStlCheatsheet() {
  return (
    <div className="prose max-w-2xl mx-auto p-6 bg-white/90 rounded-xl shadow-lg mt-8">
      <h1 className="flex items-center gap-2 text-purple-600"><FaCubes /> C++ STL Cheatsheet</h1>
      <div className="bg-indigo-100 border-l-4 border-indigo-500 text-indigo-900 p-4 mb-4 rounded">
        <strong>🧠 Memory Aid:</strong> STL = Containers + Iterators + Algorithms. <span className="text-emerald-700">Every container has begin()/end(); every algorithm works on ranges.</span>
      </div>
      <h2>📦 Sequence Containers</h2>
      <pre className="bg-zinc-100 p-2 rounded text-xs overflow-x-auto"><code>{`vector<int> v;
v.push_back(x);   // O(1) amortized
v.pop_back();     // O(1)
v[i];             // O(1) random access
v.size();  v.empty();  v.front();  v.back();
sort(v.begin(), v.end()); // O(n log n)
reverse(v.begin(), v.end()); // O(n)`}</code></pre>
      {/* ...more content can be added here... */}
    </div>
  );
}
