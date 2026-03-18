
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

export default function Day13DoublyCircularLinkedListLruCacheExamples1Page() {
  const code = "/*\n * Example 1: Doubly Linked List Ops\n */\n#include <bits/stdc++.h>\nusing namespace std;\nstruct DNode{int val;DNode*prev,*next;DNode(int x):val(x),prev(nullptr),next(nullptr){}};\nDNode* insertFront(DNode*head,int val){DNode*n=new DNode(val);if(head){n->next=head;head->prev=n;}return n;}\nDNode* deleteNode(DNode*head,int val){DNode*c=head;while(c&&c->val!=val)c=c->next;if(!c)return head;if(c->prev)c->prev->next=c->next;else head=c->next;if(c->next)c->next->prev=c->prev;return head;}\nDNode* reversDLL(DNode*head){DNode*c=head,*last=nullptr;while(c){DNode*n=c->next;c->next=c->prev;c->prev=n;last=c;c=n;}return last;}\nvoid print(DNode*h){while(h){cout<<h->val;if(h->next)cout<<\"<->\";h=h->next;}cout<<\"\\n\";}\nint main(){\n    DNode*h=nullptr; for(int x:{5,4,3,2,1}) h=insertFront(h,x); print(h);\n    h=deleteNode(h,3); print(h);\n    print(reversDLL(h));\n    return 0;\n}\n";
  return (
    <div className="min-h-screen bg-slate-950 text-slate-100">
      <header className="sticky top-0 z-10 bg-slate-900/95 backdrop-blur border-b border-slate-800">
        <div className="max-w-6xl mx-auto px-4 py-2 flex items-center gap-2 overflow-x-auto scrollbar-hide">
          <a href="/day13-doubly_circular_linked_list_lru_cache" className={`${styles.navLink} ${styles.navHome}`}>Day 13</a>
          <a href="/day13-doubly_circular_linked_list_lru_cache/README" className={`${styles.navLink} ${current === "README" ? styles.navActive + " " + styles.navReadme : styles.navReadme}`}>README</a>
          <a href="/day13-doubly_circular_linked_list_lru_cache/theory" className={`${styles.navLink} ${current === "theory" ? styles.navActive + " " + styles.navTheory : styles.navTheory}`}>Theory</a>
          <a href="/day13-doubly_circular_linked_list_lru_cache/examples/example01" className={`${styles.navLink} ${current === "example01" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 1</a>
          <a href="/day13-doubly_circular_linked_list_lru_cache/examples/example02" className={`${styles.navLink} ${current === "example02" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 2</a>
          <a href="/day13-doubly_circular_linked_list_lru_cache/examples/example03" className={`${styles.navLink} ${current === "example03" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 3</a>
          <a href="/day13-doubly_circular_linked_list_lru_cache/examples/example04" className={`${styles.navLink} ${current === "example04" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 4</a>
          <a href="/day13-doubly_circular_linked_list_lru_cache/examples/example05" className={`${styles.navLink} ${current === "example05" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 5</a>
          <a href="/day13-doubly_circular_linked_list_lru_cache/exercises/exercise01" className={`${styles.navLink} ${current === "exercise01" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 1</a>
          <a href="/day13-doubly_circular_linked_list_lru_cache/exercises/exercise02" className={`${styles.navLink} ${current === "exercise02" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 2</a>
          <a href="/day13-doubly_circular_linked_list_lru_cache/exercises/exercise03" className={`${styles.navLink} ${current === "exercise03" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 3</a>
          <a href="/day13-doubly_circular_linked_list_lru_cache/exercises/exercise04" className={`${styles.navLink} ${current === "exercise04" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 4</a>
          <a href="/day13-doubly_circular_linked_list_lru_cache/exercises/exercise05" className={`${styles.navLink} ${current === "exercise05" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 5</a>
          <a href="/day13-doubly_circular_linked_list_lru_cache/solutions/solution01" className={`${styles.navLink} ${current === "solution01" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 1</a>
          <a href="/day13-doubly_circular_linked_list_lru_cache/solutions/solution02" className={`${styles.navLink} ${current === "solution02" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 2</a>
          <a href="/day13-doubly_circular_linked_list_lru_cache/solutions/solution03" className={`${styles.navLink} ${current === "solution03" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 3</a>
          <a href="/day13-doubly_circular_linked_list_lru_cache/solutions/solution04" className={`${styles.navLink} ${current === "solution04" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 4</a>
          <a href="/day13-doubly_circular_linked_list_lru_cache/solutions/solution05" className={`${styles.navLink} ${current === "solution05" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 5</a>
        </div>
      </header>
      <div className="max-w-6xl mx-auto px-6 pt-8 pb-16">
        <a href="/" className="text-xs text-slate-500 hover:text-slate-300 transition-colors">← Home</a>
        <div className="flex items-center gap-3 mt-3 mb-8">
          <span className="text-3xl">💡</span>
          <div>
            <div className="text-xs text-slate-500 uppercase tracking-widest">Day 13 — Example 1</div>
            <h1 className="text-xl font-bold text-slate-100 mt-0.5">Doubly plus Circular Linked List plus LRU Cache intuition</h1>
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
