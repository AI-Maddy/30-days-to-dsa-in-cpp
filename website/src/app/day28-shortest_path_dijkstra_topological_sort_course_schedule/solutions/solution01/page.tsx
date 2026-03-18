
const styles = {
  navLink: "px-2.5 py-1 rounded-md text-xs font-medium transition-colors whitespace-nowrap",
  navHome: "bg-slate-100 hover:bg-slate-200 text-slate-600",
  navActive: "ring-2 ring-current ring-offset-1",
  navReadme: "bg-blue-50 hover:bg-blue-100 text-blue-700",
  navTheory: "bg-violet-50 hover:bg-violet-100 text-violet-700",
  navExample: "bg-emerald-50 hover:bg-emerald-100 text-emerald-700",
  navExercise: "bg-amber-50 hover:bg-amber-100 text-amber-700",
  navSolution: "bg-orange-50 hover:bg-orange-100 text-orange-700",
};

const current = "solution01";

export default function Day28ShortestPathDijkstraTopologicalSortCourseScheduleSolutions1Page() {
  const code = "/*\n * Solution 1: Dijkstra SSSP\n */\n#include <bits/stdc++.h>\nusing namespace std;\nvector<int> dijkstra(int src,int n,vector<vector<pair<int,int>>>&adj){\n    vector<int>dist(n,INT_MAX);priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;\n    dist[src]=0;pq.push({0,src});\n    while(!pq.empty()){auto[d,u]=pq.top();pq.pop();if(d>dist[u])continue;\n        for(auto[v,w]:adj[u])if(dist[u]+w<dist[v]){dist[v]=dist[u]+w;pq.push({dist[v],v});}}\n    return dist;\n}\nint main(){ios::sync_with_stdio(false);cin.tie(nullptr);\n    int n=5;vector<vector<pair<int,int>>>adj(n);\n    adj[0]={{1,4},{2,1}};adj[2]={{1,2},{3,5}};adj[1]={{3,1}};adj[3]={{4,3}};\n    auto d=dijkstra(0,n,adj);for(int i=0;i<n;i++)cout<<\"dist[\"<<i<<\"]=\"<<d[i]<<\"\\n\";}\n";
  return (
    <div className="min-h-screen bg-slate-950 text-slate-100">
      <header className="sticky top-0 z-10 bg-slate-900/95 backdrop-blur border-b border-slate-800">
        <div className="max-w-6xl mx-auto px-4 py-2 flex items-center gap-2 overflow-x-auto scrollbar-hide">
          <a href="/day28-shortest_path_dijkstra_topological_sort_course_schedule" className={`${styles.navLink} ${styles.navHome}`}>Day 28</a>
          <a href="/day28-shortest_path_dijkstra_topological_sort_course_schedule/README" className={`${styles.navLink} ${current === "README" ? styles.navActive + " " + styles.navReadme : styles.navReadme}`}>README</a>
          <a href="/day28-shortest_path_dijkstra_topological_sort_course_schedule/theory" className={`${styles.navLink} ${current === "theory" ? styles.navActive + " " + styles.navTheory : styles.navTheory}`}>Theory</a>
          <a href="/day28-shortest_path_dijkstra_topological_sort_course_schedule/examples/example01" className={`${styles.navLink} ${current === "example01" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 1</a>
          <a href="/day28-shortest_path_dijkstra_topological_sort_course_schedule/examples/example02" className={`${styles.navLink} ${current === "example02" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 2</a>
          <a href="/day28-shortest_path_dijkstra_topological_sort_course_schedule/examples/example03" className={`${styles.navLink} ${current === "example03" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 3</a>
          <a href="/day28-shortest_path_dijkstra_topological_sort_course_schedule/examples/example04" className={`${styles.navLink} ${current === "example04" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 4</a>
          <a href="/day28-shortest_path_dijkstra_topological_sort_course_schedule/examples/example05" className={`${styles.navLink} ${current === "example05" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 5</a>
          <a href="/day28-shortest_path_dijkstra_topological_sort_course_schedule/exercises/exercise01" className={`${styles.navLink} ${current === "exercise01" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 1</a>
          <a href="/day28-shortest_path_dijkstra_topological_sort_course_schedule/exercises/exercise02" className={`${styles.navLink} ${current === "exercise02" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 2</a>
          <a href="/day28-shortest_path_dijkstra_topological_sort_course_schedule/exercises/exercise03" className={`${styles.navLink} ${current === "exercise03" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 3</a>
          <a href="/day28-shortest_path_dijkstra_topological_sort_course_schedule/exercises/exercise04" className={`${styles.navLink} ${current === "exercise04" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 4</a>
          <a href="/day28-shortest_path_dijkstra_topological_sort_course_schedule/exercises/exercise05" className={`${styles.navLink} ${current === "exercise05" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 5</a>
          <a href="/day28-shortest_path_dijkstra_topological_sort_course_schedule/solutions/solution01" className={`${styles.navLink} ${current === "solution01" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 1</a>
          <a href="/day28-shortest_path_dijkstra_topological_sort_course_schedule/solutions/solution02" className={`${styles.navLink} ${current === "solution02" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 2</a>
          <a href="/day28-shortest_path_dijkstra_topological_sort_course_schedule/solutions/solution03" className={`${styles.navLink} ${current === "solution03" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 3</a>
          <a href="/day28-shortest_path_dijkstra_topological_sort_course_schedule/solutions/solution04" className={`${styles.navLink} ${current === "solution04" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 4</a>
          <a href="/day28-shortest_path_dijkstra_topological_sort_course_schedule/solutions/solution05" className={`${styles.navLink} ${current === "solution05" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 5</a>
        </div>
      </header>
      <div className="max-w-6xl mx-auto px-6 pt-8 pb-16">
        <a href="/" className="text-xs text-slate-500 hover:text-slate-300 transition-colors">← Home</a>
        <div className="flex items-center gap-3 mt-3 mb-8">
          <span className="text-3xl">✅</span>
          <div>
            <div className="text-xs text-slate-500 uppercase tracking-widest">Day 28 — Solution 1</div>
            <h1 className="text-xl font-bold text-slate-100 mt-0.5">Shortest Path (Dijkstra intro) plus Topological Sort plus Course Schedule</h1>
          </div>
        </div>
        <div className="rounded-xl overflow-hidden border border-slate-700">
          <div className="flex items-center gap-2 px-4 py-2.5 bg-slate-800 border-b border-slate-700">
            <span className="w-3 h-3 rounded-full bg-red-500/70"></span>
            <span className="w-3 h-3 rounded-full bg-yellow-500/70"></span>
            <span className="w-3 h-3 rounded-full bg-green-500/70"></span>
            <span className="ml-3 text-xs text-slate-400 font-mono">solution01.cpp</span>
          </div>
          <pre className="bg-slate-950 p-6 overflow-x-auto text-sm text-slate-200 font-mono leading-7"><code>{code}</code></pre>
        </div>
      </div>
    </div>
  );
}
