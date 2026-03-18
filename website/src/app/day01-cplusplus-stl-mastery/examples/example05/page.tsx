
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

const current = "example05";

export default function Day01CplusplusStlMasteryExamples5Page() {
  const code = "/*\n * Example 5: Priority Queue Top-K (Cplusplus STL Mastery)\n */\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    // Max-heap (default) \u2014 largest element at top\n    priority_queue<int> maxpq;\n    for (int x : {3, 1, 4, 1, 5, 9, 2, 6}) maxpq.push(x);\n    cout << \"Max-heap top-3: \";\n    for (int i = 0; i < 3; i++) {\n        cout << maxpq.top() << \" \";\n        maxpq.pop();\n    }\n    cout << \"\\n\";\n\n    // Min-heap \u2014 smallest element at top\n    priority_queue<int, vector<int>, greater<int>> minpq;\n    for (int x : {3, 1, 4, 1, 5, 9, 2, 6}) minpq.push(x);\n    cout << \"Min-heap top-3: \";\n    for (int i = 0; i < 3; i++) {\n        cout << minpq.top() << \" \";\n        minpq.pop();\n    }\n    cout << \"\\n\";\n\n    // Find top-K largest elements using min-heap of size K\n    // Space O(k), Time O(n log k)\n    vector<int> nums = {7, 10, 4, 3, 20, 15, 8, 1};\n    int K = 4;\n    priority_queue<int, vector<int>, greater<int>> heap;  // min-heap\n    for (int x : nums) {\n        heap.push(x);\n        if ((int)heap.size() > K) heap.pop();  // evict smallest\n    }\n    // heap now contains K largest; top = Kth largest\n    cout << \"\\nTop-\" << K << \" largest: \";\n    vector<int> topK;\n    while (!heap.empty()) { topK.push_back(heap.top()); heap.pop(); }\n    sort(topK.rbegin(), topK.rend());\n    for (int x : topK) cout << x << \" \"; cout << \"\\n\";\n    cout << K << \"th largest element: \" << topK.back() << \"\\n\";\n\n    // Priority queue with pairs (custom ordering)\n    // Task scheduling: {priority, task_name}\n    priority_queue<pair<int,string>> tasks;\n    tasks.push({3, \"low\"});\n    tasks.push({10, \"high\"});\n    tasks.push({7, \"medium\"});\n    cout << \"\\nTask order by priority:\\n\";\n    while (!tasks.empty()) {\n        auto [pri, name] = tasks.top(); tasks.pop();\n        cout << \"  priority=\" << pri << \" task=\" << name << \"\\n\";\n    }\n\n    return 0;\n}\n";
  return (
    <div className="min-h-screen bg-slate-950 text-slate-100">
      <header className="sticky top-0 z-10 bg-slate-900/95 backdrop-blur border-b border-slate-800">
        <div className="max-w-6xl mx-auto px-4 py-2 flex items-center gap-2 overflow-x-auto scrollbar-hide">
          <a href="/day01-cplusplus-stl-mastery" className={`${styles.navLink} ${styles.navHome}`}>Day 01</a>
          <a href="/day01-cplusplus-stl-mastery/README" className={`${styles.navLink} ${current === "README" ? styles.navActive + " " + styles.navReadme : styles.navReadme}`}>README</a>
          <a href="/day01-cplusplus-stl-mastery/theory" className={`${styles.navLink} ${current === "theory" ? styles.navActive + " " + styles.navTheory : styles.navTheory}`}>Theory</a>
          <a href="/day01-cplusplus-stl-mastery/examples/example01" className={`${styles.navLink} ${current === "example01" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 1</a>
          <a href="/day01-cplusplus-stl-mastery/examples/example02" className={`${styles.navLink} ${current === "example02" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 2</a>
          <a href="/day01-cplusplus-stl-mastery/examples/example03" className={`${styles.navLink} ${current === "example03" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 3</a>
          <a href="/day01-cplusplus-stl-mastery/examples/example04" className={`${styles.navLink} ${current === "example04" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 4</a>
          <a href="/day01-cplusplus-stl-mastery/examples/example05" className={`${styles.navLink} ${current === "example05" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 5</a>
          <a href="/day01-cplusplus-stl-mastery/exercises/exercise01" className={`${styles.navLink} ${current === "exercise01" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 1</a>
          <a href="/day01-cplusplus-stl-mastery/exercises/exercise02" className={`${styles.navLink} ${current === "exercise02" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 2</a>
          <a href="/day01-cplusplus-stl-mastery/exercises/exercise03" className={`${styles.navLink} ${current === "exercise03" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 3</a>
          <a href="/day01-cplusplus-stl-mastery/exercises/exercise04" className={`${styles.navLink} ${current === "exercise04" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 4</a>
          <a href="/day01-cplusplus-stl-mastery/exercises/exercise05" className={`${styles.navLink} ${current === "exercise05" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 5</a>
          <a href="/day01-cplusplus-stl-mastery/solutions/solution01" className={`${styles.navLink} ${current === "solution01" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 1</a>
          <a href="/day01-cplusplus-stl-mastery/solutions/solution02" className={`${styles.navLink} ${current === "solution02" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 2</a>
          <a href="/day01-cplusplus-stl-mastery/solutions/solution03" className={`${styles.navLink} ${current === "solution03" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 3</a>
          <a href="/day01-cplusplus-stl-mastery/solutions/solution04" className={`${styles.navLink} ${current === "solution04" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 4</a>
          <a href="/day01-cplusplus-stl-mastery/solutions/solution05" className={`${styles.navLink} ${current === "solution05" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 5</a>
        </div>
      </header>
      <div className="max-w-6xl mx-auto px-6 pt-8 pb-16">
        <a href="/" className="text-xs text-slate-500 hover:text-slate-300 transition-colors">← Home</a>
        <div className="flex items-center gap-3 mt-3 mb-8">
          <span className="text-3xl">💡</span>
          <div>
            <div className="text-xs text-slate-500 uppercase tracking-widest">Day 01 — Example 5</div>
            <h1 className="text-xl font-bold text-slate-100 mt-0.5">Cplusplus STL Mastery</h1>
          </div>
        </div>
        <div className="rounded-xl overflow-hidden border border-slate-700">
          <div className="flex items-center gap-2 px-4 py-2.5 bg-slate-800 border-b border-slate-700">
            <span className="w-3 h-3 rounded-full bg-red-500/70"></span>
            <span className="w-3 h-3 rounded-full bg-yellow-500/70"></span>
            <span className="w-3 h-3 rounded-full bg-green-500/70"></span>
            <span className="ml-3 text-xs text-slate-400 font-mono">example05.cpp</span>
          </div>
          <pre className="bg-slate-950 p-6 overflow-x-auto text-sm text-slate-200 font-mono leading-7"><code>{code}</code></pre>
        </div>
      </div>
    </div>
  );
}
