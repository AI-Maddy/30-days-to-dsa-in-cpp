
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

const current = "example04";

export default function Day02TimeAndSpaceComplexityPlusStlAlgorithmsExamples4Page() {
  const code = "/*\n * Example 4: Deque Operations (Time and Space Complexity plus STL Algorithms)\n */\n// Demonstrates fill, iota, generate, rotate, copy.\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    // iota \u2014 fills with increasing values\n    vector<int> v(10);\n    iota(v.begin(), v.end(), 1);\n    cout << \"iota(1..10): \"; for(int x:v) cout<<x<<\" \"; cout<<\"\\n\";\n\n    // fill \u2014 sets all elements to a value\n    vector<int> zeros(5);\n    fill(zeros.begin(), zeros.end(), 42);\n    cout << \"fill(42): \"; for(int x:zeros) cout<<x<<\" \"; cout<<\"\\n\";\n\n    // generate \u2014 fill with function results\n    int counter = 0;\n    vector<int> gen(5);\n    generate(gen.begin(), gen.end(), [&](){ return counter += 3; });\n    cout << \"generate(multiples of 3): \"; for(int x:gen) cout<<x<<\" \"; cout<<\"\\n\";\n\n    // rotate \u2014 O(n), left rotate by k positions\n    vector<int> r = {1,2,3,4,5,6,7};\n    rotate(r.begin(), r.begin()+3, r.end());  // left rotate by 3\n    cout << \"rotate left by 3: \"; for(int x:r) cout<<x<<\" \"; cout<<\"\\n\";\n\n    // copy, copy_if\n    vector<int> src = {1,2,3,4,5,6,7,8}, dst;\n    copy_if(src.begin(), src.end(), back_inserter(dst), [](int x){ return x%2==0; });\n    cout << \"copy_if (evens): \"; for(int x:dst) cout<<x<<\" \"; cout<<\"\\n\";\n\n    // replace, replace_if\n    vector<int> rep = {1,2,3,2,4,2,5};\n    replace(rep.begin(), rep.end(), 2, 99);\n    cout << \"replace 2->99: \"; for(int x:rep) cout<<x<<\" \"; cout<<\"\\n\";\n\n    return 0;\n}\n";
  return (
    <div className="min-h-screen bg-slate-950 text-slate-100">
      <header className="sticky top-0 z-10 bg-slate-900/95 backdrop-blur border-b border-slate-800">
        <div className="max-w-6xl mx-auto px-4 py-2 flex items-center gap-2 overflow-x-auto scrollbar-hide">
          <a href="/day02-time_and_space_complexity_plus_stl_algorithms" className={`${styles.navLink} ${styles.navHome}`}>Day 02</a>
          <a href="/day02-time_and_space_complexity_plus_stl_algorithms/README" className={`${styles.navLink} ${current === "README" ? styles.navActive + " " + styles.navReadme : styles.navReadme}`}>README</a>
          <a href="/day02-time_and_space_complexity_plus_stl_algorithms/theory" className={`${styles.navLink} ${current === "theory" ? styles.navActive + " " + styles.navTheory : styles.navTheory}`}>Theory</a>
          <a href="/day02-time_and_space_complexity_plus_stl_algorithms/examples/example01" className={`${styles.navLink} ${current === "example01" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 1</a>
          <a href="/day02-time_and_space_complexity_plus_stl_algorithms/examples/example02" className={`${styles.navLink} ${current === "example02" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 2</a>
          <a href="/day02-time_and_space_complexity_plus_stl_algorithms/examples/example03" className={`${styles.navLink} ${current === "example03" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 3</a>
          <a href="/day02-time_and_space_complexity_plus_stl_algorithms/examples/example04" className={`${styles.navLink} ${current === "example04" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 4</a>
          <a href="/day02-time_and_space_complexity_plus_stl_algorithms/examples/example05" className={`${styles.navLink} ${current === "example05" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 5</a>
          <a href="/day02-time_and_space_complexity_plus_stl_algorithms/exercises/exercise01" className={`${styles.navLink} ${current === "exercise01" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 1</a>
          <a href="/day02-time_and_space_complexity_plus_stl_algorithms/exercises/exercise02" className={`${styles.navLink} ${current === "exercise02" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 2</a>
          <a href="/day02-time_and_space_complexity_plus_stl_algorithms/exercises/exercise03" className={`${styles.navLink} ${current === "exercise03" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 3</a>
          <a href="/day02-time_and_space_complexity_plus_stl_algorithms/exercises/exercise04" className={`${styles.navLink} ${current === "exercise04" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 4</a>
          <a href="/day02-time_and_space_complexity_plus_stl_algorithms/exercises/exercise05" className={`${styles.navLink} ${current === "exercise05" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 5</a>
          <a href="/day02-time_and_space_complexity_plus_stl_algorithms/solutions/solution01" className={`${styles.navLink} ${current === "solution01" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 1</a>
          <a href="/day02-time_and_space_complexity_plus_stl_algorithms/solutions/solution02" className={`${styles.navLink} ${current === "solution02" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 2</a>
          <a href="/day02-time_and_space_complexity_plus_stl_algorithms/solutions/solution03" className={`${styles.navLink} ${current === "solution03" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 3</a>
          <a href="/day02-time_and_space_complexity_plus_stl_algorithms/solutions/solution04" className={`${styles.navLink} ${current === "solution04" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 4</a>
          <a href="/day02-time_and_space_complexity_plus_stl_algorithms/solutions/solution05" className={`${styles.navLink} ${current === "solution05" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 5</a>
        </div>
      </header>
      <div className="max-w-6xl mx-auto px-6 pt-8 pb-16">
        <a href="/" className="text-xs text-slate-500 hover:text-slate-300 transition-colors">← Home</a>
        <div className="flex items-center gap-3 mt-3 mb-8">
          <span className="text-3xl">💡</span>
          <div>
            <div className="text-xs text-slate-500 uppercase tracking-widest">Day 02 — Example 4</div>
            <h1 className="text-xl font-bold text-slate-100 mt-0.5">Time and Space Complexity plus STL Algorithms</h1>
          </div>
        </div>
        <div className="rounded-xl overflow-hidden border border-slate-700">
          <div className="flex items-center gap-2 px-4 py-2.5 bg-slate-800 border-b border-slate-700">
            <span className="w-3 h-3 rounded-full bg-red-500/70"></span>
            <span className="w-3 h-3 rounded-full bg-yellow-500/70"></span>
            <span className="w-3 h-3 rounded-full bg-green-500/70"></span>
            <span className="ml-3 text-xs text-slate-400 font-mono">example04.cpp</span>
          </div>
          <pre className="bg-slate-950 p-6 overflow-x-auto text-sm text-slate-200 font-mono leading-7"><code>{code}</code></pre>
        </div>
      </div>
    </div>
  );
}
