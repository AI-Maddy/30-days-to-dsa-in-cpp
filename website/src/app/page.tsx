"use client";
import { useState } from "react";

const CHEATSHEETS = [
  { label: "Arrays", href: "/cheatsheets/arrays", color: "bg-rose-50 hover:bg-rose-100 text-rose-700 border-rose-200" },
  { label: "Linked Lists", href: "/cheatsheets/linked-lists", color: "bg-emerald-50 hover:bg-emerald-100 text-emerald-700 border-emerald-200" },
  { label: "Binary Search", href: "/cheatsheets/binary-search", color: "bg-amber-50 hover:bg-amber-100 text-amber-700 border-amber-200" },
  { label: "Bit Manipulation", href: "/cheatsheets/bit-manipulation", color: "bg-yellow-50 hover:bg-yellow-100 text-yellow-700 border-yellow-200" },
  { label: "C++ STL", href: "/cheatsheets/cpp-stl", color: "bg-violet-50 hover:bg-violet-100 text-violet-700 border-violet-200" },
  { label: "Complexity", href: "/cheatsheets/complexity-analysis", color: "bg-red-50 hover:bg-red-100 text-red-700 border-red-200" },
  { label: "Dynamic Programming", href: "/cheatsheets/dynamic-programming", color: "bg-orange-50 hover:bg-orange-100 text-orange-700 border-orange-200" },
  { label: "Graphs", href: "/cheatsheets/graphs", color: "bg-sky-50 hover:bg-sky-100 text-sky-700 border-sky-200" },
  { label: "Hashing", href: "/cheatsheets/hashing", color: "bg-teal-50 hover:bg-teal-100 text-teal-700 border-teal-200" },
  { label: "Recursion & Backtracking", href: "/cheatsheets/recursion-backtracking", color: "bg-pink-50 hover:bg-pink-100 text-pink-700 border-pink-200" },
  { label: "Sorting", href: "/cheatsheets/sorting", color: "bg-lime-50 hover:bg-lime-100 text-lime-700 border-lime-200" },
  { label: "Stacks & Queues", href: "/cheatsheets/stacks-queues", color: "bg-indigo-50 hover:bg-indigo-100 text-indigo-700 border-indigo-200" },
  { label: "Trees", href: "/cheatsheets/trees", color: "bg-green-50 hover:bg-green-100 text-green-700 border-green-200" },
];

type Day = { n: number; label: string; href: string; tag?: string };

const GROUPS: { title: string; color: string; accent: string; days: Day[] }[] = [
  {
    title: "Foundations",
    color: "border-blue-200 bg-blue-50/60",
    accent: "text-blue-700",
    days: [
      { n: 1,  label: "C++ STL Mastery",                         href: "/day01-cplusplus-stl-mastery/README",                                                                                       tag: "STL" },
      { n: 2,  label: "Time & Space Complexity",                  href: "/day02-time_and_space_complexity_plus_stl_algorithms/README",                                                                tag: "Complexity" },
      { n: 3,  label: "Bit Manipulation",                         href: "/day03-bit_manipulation_in_cplusplus/README",                                                                                tag: "Bits" },
      { n: 4,  label: "1D Arrays — Two Pointers & Sliding Window",href: "/day04-1d_arrays_–_two_pointers_and_sliding_window_basics/README",                                                           tag: "Arrays" },
      { n: 5,  label: "Prefix Sum & Difference Array",            href: "/day05-prefix_sum_plus_difference_array_plus_range_queries_patterns",                                                        tag: "Arrays" },
    ],
  },
  {
    title: "Hashing, Matrices & Search",
    color: "border-violet-200 bg-violet-50/60",
    accent: "text-violet-700",
    days: [
      { n: 6,  label: "Hashing & HashMap Problems",               href: "/day06-hashing_and_hashmap_problems",                                                                                       tag: "Hash" },
      { n: 7,  label: "2D Arrays — Matrix Traversal & Rotation",  href: "/day07-2d_arrays_matrix_–_traversal,_rotation,_spiral,_search",                                                             tag: "Matrix" },
      { n: 8,  label: "Binary Search on 1D / 2D",                 href: "/day08-binary_search_on_1d_and_2d_plus_binary_search_on_answer_pattern",                                                     tag: "Search" },
    ],
  },
  {
    title: "Sorting & Advanced Search",
    color: "border-amber-200 bg-amber-50/60",
    accent: "text-amber-700",
    days: [
      { n: 9,  label: "Aggressive Cows, Book Allocation & Median", href: "/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/README",                               tag: "Search" },
      { n: 10, label: "Sorting, Custom Comparators & Radix Sort",  href: "/day10-sorting_revision_custom_comparators_counting_sort_radix_sort_intuition/README",                                      tag: "Sort" },
      { n: 11, label: "Binary Search on Rotated Arrays & 2D Matrix",href: "/day11-binary_search_on_sorted_rotated_array_search_in_2d_matrix_variants",                                               tag: "Search" },
    ],
  },
  {
    title: "Linked Lists",
    color: "border-emerald-200 bg-emerald-50/60",
    accent: "text-emerald-700",
    days: [
      { n: 12, label: "Singly Linked List — Reverse, Cycle, Remove Nth", href: "/day12-singly_linked_list_reverse_middle_cycle_remove_nth_node",                                                     tag: "LL" },
      { n: 13, label: "Doubly / Circular LL & LRU Cache",          href: "/day13-doubly_circular_linked_list_lru_cache",                                                                             tag: "LL" },
      { n: 14, label: "Fast & Slow Pointers, Palindrome LL",        href: "/day14-fast_and_slow_pointers_palindrome_linked_list",                                                                    tag: "LL" },
      { n: 15, label: "Merge k Sorted Lists, Flatten Multilevel",  href: "/day15-merge_k_sorted_lists_sort_flatten_multilevel",                                                                      tag: "LL" },
    ],
  },
  {
    title: "Stacks & Queues",
    color: "border-rose-200 bg-rose-50/60",
    accent: "text-rose-700",
    days: [
      { n: 16, label: "Stack — NGE, NSE & Stock Span",             href: "/day16-stack_next_greater_smaller_stock_span",                                                                             tag: "Stack" },
      { n: 17, label: "Monotonic Stack / Queue, Largest Rectangle", href: "/day17-monotonic_stack_queue_largest_rectangle_histogram",                                                                 tag: "Stack" },
      { n: 18, label: "Queue & Deque — Sliding Window Max",        href: "/day18-queue_deque_sliding_window_max_first_negative",                                                                     tag: "Queue" },
      { n: 19, label: "Parentheses, RPN & LFU Cache",              href: "/day19-parentheses_rpn_lfu",                                                                                               tag: "Stack" },
    ],
  },
  {
    title: "Binary Trees",
    color: "border-green-200 bg-green-50/60",
    accent: "text-green-700",
    days: [
      { n: 20, label: "Tree Traversals — Recursive, Iterative, Morris", href: "/day20-binary_tree_traversals_recursive_iterative_morris",                                                            tag: "Tree" },
      { n: 21, label: "Level Order, Zigzag, Boundary & Views",    href: "/day21-level_order_zigzag_boundary_vertical_top_bottom_view",                                                               tag: "Tree" },
      { n: 22, label: "BST — Validate, Floor/Ceil, Kth, LCA",     href: "/day22-binary_search_tree_validate_floor_ceil_kth_smallest_lca",                                                           tag: "BST" },
      { n: 23, label: "Construct Tree, Serialize / Deserialize",   href: "/day23-construct_tree_traversals_serialize_deserialize_morris",                                                             tag: "Tree" },
    ],
  },
  {
    title: "Recursion & Backtracking",
    color: "border-pink-200 bg-pink-50/60",
    accent: "text-pink-700",
    days: [
      { n: 24, label: "Subsets, Combination Sum & Permutations",   href: "/day24-recursion_subsets_combination_sum_permutations",                                                                    tag: "Recursion" },
      { n: 25, label: "N-Queens, Sudoku, Word Search & Rat in Maze",href: "/day25-n_queens_sudoku_solver_word_search_rat_in_maze",                                                                   tag: "Backtrack" },
      { n: 26, label: "Backtracking with Pruning & Graph Coloring", href: "/day26-backtracking_pruning_graph_coloring_m_coloring",                                                                   tag: "Backtrack" },
    ],
  },
  {
    title: "Graphs, Greedy & DP",
    color: "border-sky-200 bg-sky-50/60",
    accent: "text-sky-700",
    days: [
      { n: 27, label: "Graph BFS / DFS, Flood Fill & Islands",     href: "/day27-graph_traversals_bfs_dfs_flood_fill_rotten_oranges_islands",                                                        tag: "Graph" },
      { n: 28, label: "Dijkstra, Topological Sort & Course Schedule",href: "/day28-shortest_path_dijkstra_topological_sort_course_schedule",                                                          tag: "Graph" },
      { n: 29, label: "Greedy — Activity Selection & Knapsack",    href: "/day29-greedy_activity_selection_fractional_knapsack_jump_game",                                                           tag: "Greedy" },
      { n: 30, label: "1D DP Patterns & Mixed Problems",           href: "/day30-1d_dp_patterns_mini_revision_mixed_medium_hard",                                                                    tag: "DP" },
    ],
  },
];

export default function Home() {
  const [openGroup, setOpenGroup] = useState<string | null>(null);

  return (
    <div className="min-h-screen bg-gradient-to-br from-slate-50 via-blue-50 to-indigo-50">
      {/* Hero */}
      <header className="max-w-5xl mx-auto px-6 pt-14 pb-8 text-center">
        <div className="inline-flex items-center gap-2 bg-blue-100 text-blue-700 text-sm font-semibold px-3 py-1 rounded-full mb-4">
          30-Day Curriculum
        </div>
        <h1 className="text-5xl font-extrabold text-slate-800 tracking-tight mb-3">
          30 Days to DSA in C++
        </h1>
        <p className="text-lg text-slate-500 max-w-xl mx-auto">
          A structured, code-first journey through data structures and algorithms — with theory, examples, exercises and solutions for every day.
        </p>
      </header>

      <main className="max-w-5xl mx-auto px-6 pb-16 space-y-10">

        {/* Cheatsheets */}
        <section>
          <h2 className="text-xs font-bold uppercase tracking-widest text-slate-400 mb-3">Quick Reference — Cheatsheets</h2>
          <div className="flex flex-wrap gap-2">
            {CHEATSHEETS.map(cs => (
              <a key={cs.href} href={cs.href}
                className={`px-3 py-1.5 rounded-lg border text-sm font-medium transition-colors ${cs.color}`}>
                {cs.label}
              </a>
            ))}
          </div>
        </section>

        {/* Day Groups */}
        <section>
          <h2 className="text-xs font-bold uppercase tracking-widest text-slate-400 mb-4">30-Day Course</h2>
          <div className="space-y-4">
            {GROUPS.map(g => (
              <div key={g.title} className={`rounded-xl border ${g.color} overflow-hidden`}>
                {/* Group header — toggle on mobile, always open on md+ */}
                <button
                  className="w-full flex items-center justify-between px-5 py-3 text-left"
                  onClick={() => setOpenGroup(openGroup === g.title ? null : g.title)}
                >
                  <span className={`font-bold text-base ${g.accent}`}>{g.title}</span>
                  <span className="text-slate-400 text-sm">{g.days.length} days</span>
                </button>
                {/* Days grid — visible when open or md+ */}
                <div className={`${openGroup === g.title ? "block" : "hidden"} md:block border-t border-inherit`}>
                  <div className="grid grid-cols-1 sm:grid-cols-2 md:grid-cols-3 gap-px bg-inherit">
                    {g.days.map(d => (
                      <a key={d.n} href={d.href}
                        className="flex items-start gap-3 px-5 py-4 bg-white/70 hover:bg-white transition-colors group">
                        <span className={`mt-0.5 text-xs font-bold w-8 shrink-0 ${g.accent} opacity-60`}>
                          D{String(d.n).padStart(2, "0")}
                        </span>
                        <div className="min-w-0">
                          <div className="text-sm font-semibold text-slate-700 group-hover:text-slate-900 leading-snug">
                            {d.label}
                          </div>
                          {d.tag && (
                            <span className="inline-block mt-1 text-xs text-slate-400">{d.tag}</span>
                          )}
                        </div>
                      </a>
                    ))}
                  </div>
                </div>
              </div>
            ))}
          </div>
        </section>
      </main>

      <footer className="text-center text-sm text-slate-400 pb-8">
        &copy; {new Date().getFullYear()} 30 Days to DSA in C++
      </footer>
    </div>
  );
}
