
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

export default function Day15MergeKSortedListsSortFlattenMultilevelExamples1Page() {
  const code = "/*\n * Example 1: Merge K Sorted Lists\n */\n#include <bits/stdc++.h>\nusing namespace std;\nstruct ListNode{int val;ListNode*next;ListNode(int x):val(x),next(nullptr){}};\nListNode* build(vector<int>v){ListNode d(0);ListNode*c=&d;for(int x:v){c->next=new ListNode(x);c=c->next;}return d.next;}\nvoid print(ListNode*h){while(h){cout<<h->val;if(h->next)cout<<\"->\";h=h->next;}cout<<\"\\n\";}\nListNode* mergeK(vector<ListNode*>&lists){\n    auto cmp=[](ListNode*a,ListNode*b){return a->val>b->val;};\n    priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> pq(cmp);\n    for(auto l:lists) if(l) pq.push(l);\n    ListNode d(0);ListNode*c=&d;\n    while(!pq.empty()){c->next=pq.top();pq.pop();c=c->next;if(c->next)pq.push(c->next);}\n    return d.next;\n}\nint main(){\n    vector<ListNode*> lists={build({1,4,5}),build({1,3,4}),build({2,6})};\n    print(mergeK(lists)); // 1->1->2->3->4->4->5->6\n    return 0;\n}\n";
  return (
    <div className="min-h-screen bg-slate-950 text-slate-100">
      <header className="sticky top-0 z-10 bg-slate-900/95 backdrop-blur border-b border-slate-800">
        <div className="max-w-6xl mx-auto px-4 py-2 flex items-center gap-2 overflow-x-auto scrollbar-hide">
          <a href="/day15-merge_k_sorted_lists_sort_flatten_multilevel" className={`${styles.navLink} ${styles.navHome}`}>Day 15</a>
          <a href="/day15-merge_k_sorted_lists_sort_flatten_multilevel/README" className={`${styles.navLink} ${current === "README" ? styles.navActive + " " + styles.navReadme : styles.navReadme}`}>README</a>
          <a href="/day15-merge_k_sorted_lists_sort_flatten_multilevel/theory" className={`${styles.navLink} ${current === "theory" ? styles.navActive + " " + styles.navTheory : styles.navTheory}`}>Theory</a>
          <a href="/day15-merge_k_sorted_lists_sort_flatten_multilevel/examples/example01" className={`${styles.navLink} ${current === "example01" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 1</a>
          <a href="/day15-merge_k_sorted_lists_sort_flatten_multilevel/examples/example02" className={`${styles.navLink} ${current === "example02" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 2</a>
          <a href="/day15-merge_k_sorted_lists_sort_flatten_multilevel/examples/example03" className={`${styles.navLink} ${current === "example03" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 3</a>
          <a href="/day15-merge_k_sorted_lists_sort_flatten_multilevel/examples/example04" className={`${styles.navLink} ${current === "example04" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 4</a>
          <a href="/day15-merge_k_sorted_lists_sort_flatten_multilevel/examples/example05" className={`${styles.navLink} ${current === "example05" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 5</a>
          <a href="/day15-merge_k_sorted_lists_sort_flatten_multilevel/exercises/exercise01" className={`${styles.navLink} ${current === "exercise01" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 1</a>
          <a href="/day15-merge_k_sorted_lists_sort_flatten_multilevel/exercises/exercise02" className={`${styles.navLink} ${current === "exercise02" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 2</a>
          <a href="/day15-merge_k_sorted_lists_sort_flatten_multilevel/exercises/exercise03" className={`${styles.navLink} ${current === "exercise03" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 3</a>
          <a href="/day15-merge_k_sorted_lists_sort_flatten_multilevel/exercises/exercise04" className={`${styles.navLink} ${current === "exercise04" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 4</a>
          <a href="/day15-merge_k_sorted_lists_sort_flatten_multilevel/exercises/exercise05" className={`${styles.navLink} ${current === "exercise05" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 5</a>
          <a href="/day15-merge_k_sorted_lists_sort_flatten_multilevel/solutions/solution01" className={`${styles.navLink} ${current === "solution01" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 1</a>
          <a href="/day15-merge_k_sorted_lists_sort_flatten_multilevel/solutions/solution02" className={`${styles.navLink} ${current === "solution02" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 2</a>
          <a href="/day15-merge_k_sorted_lists_sort_flatten_multilevel/solutions/solution03" className={`${styles.navLink} ${current === "solution03" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 3</a>
          <a href="/day15-merge_k_sorted_lists_sort_flatten_multilevel/solutions/solution04" className={`${styles.navLink} ${current === "solution04" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 4</a>
          <a href="/day15-merge_k_sorted_lists_sort_flatten_multilevel/solutions/solution05" className={`${styles.navLink} ${current === "solution05" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 5</a>
        </div>
      </header>
      <div className="max-w-6xl mx-auto px-6 pt-8 pb-16">
        <a href="/" className="text-xs text-slate-500 hover:text-slate-300 transition-colors">← Home</a>
        <div className="flex items-center gap-3 mt-3 mb-8">
          <span className="text-3xl">💡</span>
          <div>
            <div className="text-xs text-slate-500 uppercase tracking-widest">Day 15 — Example 1</div>
            <h1 className="text-xl font-bold text-slate-100 mt-0.5">Merge k Sorted Lists plus Sort Linked List plus Flatten multilevel list</h1>
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
