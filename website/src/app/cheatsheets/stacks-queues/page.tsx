import React from "react";
import { FaLayerGroup } from "react-icons/fa";

export default function StacksQueuesCheatsheet() {
  return (
    <div className="prose max-w-2xl mx-auto p-6 bg-white/90 rounded-xl shadow-lg mt-8">
      <h1 className="flex items-center gap-2 text-indigo-700"><FaLayerGroup /> Stacks & Queues Cheatsheet</h1>
      <div className="bg-indigo-100 border-l-4 border-indigo-500 text-indigo-900 p-4 mb-4 rounded">
        <strong>🧠 Memory Aid:</strong> Monotonic stack: pop when invariant breaks, then push. Store indices, not just values. <span className="text-emerald-700">Deque for sliding window max: pop front (out of window), pop back (smaller than current).</span>
      </div>
      <h2>🛠️ STL Operations</h2>
      <pre className="bg-zinc-100 p-2 rounded text-xs overflow-x-auto"><code>{`stack<int> st;
st.push(x); st.pop(); st.top(); st.empty(); st.size();
queue<int> q;
q.push(x); q.pop(); q.front(); q.back(); q.empty();`}</code></pre>
      {/* ...more content can be added here... */}
    </div>
  );
}
