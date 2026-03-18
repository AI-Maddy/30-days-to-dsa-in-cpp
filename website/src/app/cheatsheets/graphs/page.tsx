import React from "react";
import { FaProjectDiagram } from "react-icons/fa";

export default function GraphsCheatsheet() {
  return (
    <div className="prose max-w-2xl mx-auto p-6 bg-white/90 rounded-xl shadow-lg mt-8">
      <h1 className="flex items-center gap-2 text-blue-500"><FaProjectDiagram /> Graphs Cheatsheet</h1>
      <div className="bg-indigo-100 border-l-4 border-indigo-500 text-indigo-900 p-4 mb-4 rounded">
        <strong>🧠 Memory Aid:</strong> BFS = shortest path in unweighted. DFS = connectivity, cycles. Dijkstra = weighted shortest. <span className="text-emerald-700">Topo sort exists only on DAGs. Cycle in directed graph → no topo sort.</span>
      </div>
      <h2>🏕️ Graph Representation</h2>
      <pre className="bg-zinc-100 p-2 rounded text-xs overflow-x-auto"><code>{`// Adjacency list
vector<vector<int>> adj(n);
adj[u].push_back(v); // directed
adj[u].push_back(v); adj[v].push_back(u); // undirected`}</code></pre>
      {/* ...more content can be added here... */}
    </div>
  );
}
