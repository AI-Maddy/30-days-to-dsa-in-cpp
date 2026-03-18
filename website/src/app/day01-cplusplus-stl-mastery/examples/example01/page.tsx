
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

const current = "example01";

export default function Day01CplusplusStlMasteryExamples1Page() {
  const code = "/*\n * Example 1: Vector Sort (Cplusplus STL Mastery)\n */\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    vector<int> v = {5, 2, 8, 1, 9, 3, 7, 4, 6};\n    cout << \"Original: \"; for (int x : v) cout << x << \" \"; cout << \"\\n\";\n\n    // sort() \u2014 O(n log n)\n    sort(v.begin(), v.end());\n    cout << \"Ascending: \"; for (int x : v) cout << x << \" \"; cout << \"\\n\";\n\n    // reverse() \u2014 O(n)\n    reverse(v.begin(), v.end());\n    cout << \"Descending: \"; for (int x : v) cout << x << \" \"; cout << \"\\n\";\n\n    sort(v.begin(), v.end());  // re-sort for search\n\n    // binary_search \u2014 requires sorted range, O(log n)\n    cout << \"\\nbinary_search(7): \" << binary_search(v.begin(), v.end(), 7) << \"\\n\";\n\n    // lower_bound \u2014 first element >= value\n    auto lb = lower_bound(v.begin(), v.end(), 5);\n    cout << \"lower_bound(5) index: \" << (lb - v.begin()) << \" value: \" << *lb << \"\\n\";\n\n    // upper_bound \u2014 first element > value\n    auto ub = upper_bound(v.begin(), v.end(), 5);\n    cout << \"upper_bound(5) index: \" << (ub - v.begin()) << \" value: \" << *ub << \"\\n\";\n\n    // Count occurrences in sorted array\n    vector<int> d = {1,2,2,2,3,4,4,5};\n    int cnt = upper_bound(d.begin(),d.end(),2) - lower_bound(d.begin(),d.end(),2);\n    cout << \"\\nCount of 2 in {1,2,2,2,3,4,4,5}: \" << cnt << \"\\n\";\n\n    // Custom comparator: sort by absolute value\n    vector<int> w = {-3, 1, -4, 2, -5};\n    sort(w.begin(), w.end(), [](int a, int b){ return abs(a) < abs(b); });\n    cout << \"Sorted by |val|: \"; for (int x : w) cout << x << \" \"; cout << \"\\n\";\n\n    return 0;\n}\n";
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
            <div className="text-xs text-slate-500 uppercase tracking-widest">Day 01 — Example 1</div>
            <h1 className="text-xl font-bold text-slate-100 mt-0.5">Cplusplus STL Mastery</h1>
          </div>
        </div>
        <div className="rounded-xl overflow-hidden border border-slate-700">
          <div className="flex items-center gap-2 px-4 py-2.5 bg-slate-800 border-b border-slate-700">
            <span className="w-3 h-3 rounded-full bg-red-500/70"></span>
            <span className="w-3 h-3 rounded-full bg-yellow-500/70"></span>
            <span className="w-3 h-3 rounded-full bg-green-500/70"></span>
            <span className="ml-3 text-xs text-slate-400 font-mono">example01.cpp</span>
          </div>
          <pre className="bg-slate-950 p-6 overflow-x-auto text-sm text-slate-200 font-mono leading-7"><code>{code}</code></pre>
        </div>
      </div>
    </div>
  );
}
