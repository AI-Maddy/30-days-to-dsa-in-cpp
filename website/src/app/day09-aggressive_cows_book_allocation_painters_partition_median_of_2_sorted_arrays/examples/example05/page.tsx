
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

export default function Day09AggressiveCowsBookAllocationPaintersPartitionMedianOf2SortedArraysExamples5Page() {
  const code = "/*\n * Example 5: Last Occurrence (BS Answer)\n */\n#include <bits/stdc++.h>\nusing namespace std;\n// Minimize max distance to gas station: add k stations\n// Binary search on answer (double)\nbool check(vector<int>&s,int k,double d){int cnt=0;for(int i=1;i<(int)s.size();i++)cnt+=(int)ceil((s[i]-s[i-1])/d)-1;return cnt<=k;}\ndouble minGasStation(vector<int>&s,int k){double lo=0,hi=1e8;for(int i=0;i<100;i++){double mid=(lo+hi)/2;if(check(s,k,mid))hi=mid;else lo=mid;}return hi;}\nint main(){\n    vector<int> s={1,2,3,4,5,6,7,8,9,10};int k=9;\n    cout<<fixed<<setprecision(6)<<minGasStation(s,k)<<\"\\n\"; // 0.5\n    return 0;\n}\n";
  return (
    <div className="min-h-screen bg-slate-950 text-slate-100">
      <header className="sticky top-0 z-10 bg-slate-900/95 backdrop-blur border-b border-slate-800">
        <div className="max-w-6xl mx-auto px-4 py-2 flex items-center gap-2 overflow-x-auto scrollbar-hide">
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays" className={`${styles.navLink} ${styles.navHome}`}>Day 09</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/README" className={`${styles.navLink} ${current === "README" ? styles.navActive + " " + styles.navReadme : styles.navReadme}`}>README</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/theory" className={`${styles.navLink} ${current === "theory" ? styles.navActive + " " + styles.navTheory : styles.navTheory}`}>Theory</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/examples/example01" className={`${styles.navLink} ${current === "example01" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 1</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/examples/example02" className={`${styles.navLink} ${current === "example02" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 2</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/examples/example03" className={`${styles.navLink} ${current === "example03" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 3</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/examples/example04" className={`${styles.navLink} ${current === "example04" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 4</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/examples/example05" className={`${styles.navLink} ${current === "example05" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 5</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/exercises/exercise01" className={`${styles.navLink} ${current === "exercise01" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 1</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/exercises/exercise02" className={`${styles.navLink} ${current === "exercise02" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 2</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/exercises/exercise03" className={`${styles.navLink} ${current === "exercise03" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 3</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/exercises/exercise04" className={`${styles.navLink} ${current === "exercise04" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 4</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/exercises/exercise05" className={`${styles.navLink} ${current === "exercise05" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 5</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/solutions/solution01" className={`${styles.navLink} ${current === "solution01" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 1</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/solutions/solution02" className={`${styles.navLink} ${current === "solution02" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 2</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/solutions/solution03" className={`${styles.navLink} ${current === "solution03" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 3</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/solutions/solution04" className={`${styles.navLink} ${current === "solution04" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 4</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/solutions/solution05" className={`${styles.navLink} ${current === "solution05" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 5</a>
        </div>
      </header>
      <div className="max-w-6xl mx-auto px-6 pt-8 pb-16">
        <a href="/" className="text-xs text-slate-500 hover:text-slate-300 transition-colors">← Home</a>
        <div className="flex items-center gap-3 mt-3 mb-8">
          <span className="text-3xl">💡</span>
          <div>
            <div className="text-xs text-slate-500 uppercase tracking-widest">Day 09 — Example 5</div>
            <h1 className="text-xl font-bold text-slate-100 mt-0.5">Aggressive Cows, Book Allocation, Painters Partition, Median of 2 sorted arrays</h1>
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
