
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

export default function Day14FastAndSlowPointersPalindromeLinkedListExamples4Page() {
  const code = "/*\n * Example 4: Reorder List\n */\n#include <bits/stdc++.h>\nusing namespace std;\nstruct ListNode{int val;ListNode*next;ListNode(int x):val(x),next(nullptr){}};\nListNode* build(vector<int>v){ListNode d(0);ListNode*c=&d;for(int x:v){c->next=new ListNode(x);c=c->next;}return d.next;}\nvoid print(ListNode*h){while(h){cout<<h->val;if(h->next)cout<<\"->\";h=h->next;}cout<<\"\\n\";}\n// Reorder: L0->Ln->L1->Ln-1->...\nvoid reorder(ListNode*h){\n    if(!h||!h->next)return;\n    ListNode*s=h,*f=h;while(f->next&&f->next->next){s=s->next;f=f->next->next;}\n    ListNode*second=s->next; s->next=nullptr;\n    ListNode*p=nullptr,*c=second;while(c){ListNode*n=c->next;c->next=p;p=c;c=n;} second=p;\n    ListNode*p1=h,*p2=second;\n    while(p2){ListNode*n1=p1->next,*n2=p2->next;p1->next=p2;p2->next=n1;p1=n1;p2=n2;}\n}\nint main(){\n    ListNode*h=build({1,2,3,4,5});reorder(h);print(h); // 1->5->2->4->3\n    return 0;\n}\n";
  return (
    <div className="min-h-screen bg-slate-950 text-slate-100">
      <header className="sticky top-0 z-10 bg-slate-900/95 backdrop-blur border-b border-slate-800">
        <div className="max-w-6xl mx-auto px-4 py-2 flex items-center gap-2 overflow-x-auto scrollbar-hide">
          <a href="/day14-fast_and_slow_pointers_palindrome_linked_list" className={`${styles.navLink} ${styles.navHome}`}>Day 14</a>
          <a href="/day14-fast_and_slow_pointers_palindrome_linked_list/README" className={`${styles.navLink} ${current === "README" ? styles.navActive + " " + styles.navReadme : styles.navReadme}`}>README</a>
          <a href="/day14-fast_and_slow_pointers_palindrome_linked_list/theory" className={`${styles.navLink} ${current === "theory" ? styles.navActive + " " + styles.navTheory : styles.navTheory}`}>Theory</a>
          <a href="/day14-fast_and_slow_pointers_palindrome_linked_list/examples/example01" className={`${styles.navLink} ${current === "example01" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 1</a>
          <a href="/day14-fast_and_slow_pointers_palindrome_linked_list/examples/example02" className={`${styles.navLink} ${current === "example02" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 2</a>
          <a href="/day14-fast_and_slow_pointers_palindrome_linked_list/examples/example03" className={`${styles.navLink} ${current === "example03" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 3</a>
          <a href="/day14-fast_and_slow_pointers_palindrome_linked_list/examples/example04" className={`${styles.navLink} ${current === "example04" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 4</a>
          <a href="/day14-fast_and_slow_pointers_palindrome_linked_list/examples/example05" className={`${styles.navLink} ${current === "example05" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 5</a>
          <a href="/day14-fast_and_slow_pointers_palindrome_linked_list/exercises/exercise01" className={`${styles.navLink} ${current === "exercise01" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 1</a>
          <a href="/day14-fast_and_slow_pointers_palindrome_linked_list/exercises/exercise02" className={`${styles.navLink} ${current === "exercise02" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 2</a>
          <a href="/day14-fast_and_slow_pointers_palindrome_linked_list/exercises/exercise03" className={`${styles.navLink} ${current === "exercise03" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 3</a>
          <a href="/day14-fast_and_slow_pointers_palindrome_linked_list/exercises/exercise04" className={`${styles.navLink} ${current === "exercise04" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 4</a>
          <a href="/day14-fast_and_slow_pointers_palindrome_linked_list/exercises/exercise05" className={`${styles.navLink} ${current === "exercise05" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 5</a>
          <a href="/day14-fast_and_slow_pointers_palindrome_linked_list/solutions/solution01" className={`${styles.navLink} ${current === "solution01" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 1</a>
          <a href="/day14-fast_and_slow_pointers_palindrome_linked_list/solutions/solution02" className={`${styles.navLink} ${current === "solution02" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 2</a>
          <a href="/day14-fast_and_slow_pointers_palindrome_linked_list/solutions/solution03" className={`${styles.navLink} ${current === "solution03" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 3</a>
          <a href="/day14-fast_and_slow_pointers_palindrome_linked_list/solutions/solution04" className={`${styles.navLink} ${current === "solution04" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 4</a>
          <a href="/day14-fast_and_slow_pointers_palindrome_linked_list/solutions/solution05" className={`${styles.navLink} ${current === "solution05" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 5</a>
        </div>
      </header>
      <div className="max-w-6xl mx-auto px-6 pt-8 pb-16">
        <a href="/" className="text-xs text-slate-500 hover:text-slate-300 transition-colors">← Home</a>
        <div className="flex items-center gap-3 mt-3 mb-8">
          <span className="text-3xl">💡</span>
          <div>
            <div className="text-xs text-slate-500 uppercase tracking-widest">Day 14 — Example 4</div>
            <h1 className="text-xl font-bold text-slate-100 mt-0.5">Fast and Slow pointers deep dive plus Palindrome Linked List variants</h1>
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
