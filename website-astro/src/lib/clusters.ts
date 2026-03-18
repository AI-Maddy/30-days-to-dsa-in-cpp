export type ClusterColor = "blue" | "green" | "violet" | "red" | "orange" | "yellow" | "pink" | "slate";

export interface ClusterStyle {
  border: string;
  bg: string;
  badge: string;
  text: string;
  glow: string;
  dot: string;
}

const styles: Record<ClusterColor, ClusterStyle> = {
  blue:   { border: "border-blue-500/40",   bg: "bg-blue-950/40",   badge: "bg-blue-500/20 text-blue-300",   text: "text-blue-400",   glow: "hover:border-blue-400/70",   dot: "bg-blue-400" },
  green:  { border: "border-green-500/40",  bg: "bg-green-950/40",  badge: "bg-green-500/20 text-green-300",  text: "text-green-400",  glow: "hover:border-green-400/70",  dot: "bg-green-400" },
  violet: { border: "border-violet-500/40", bg: "bg-violet-950/40", badge: "bg-violet-500/20 text-violet-300", text: "text-violet-400", glow: "hover:border-violet-400/70", dot: "bg-violet-400" },
  red:    { border: "border-red-500/40",    bg: "bg-red-950/40",    badge: "bg-red-500/20 text-red-300",    text: "text-red-400",    glow: "hover:border-red-400/70",    dot: "bg-red-400" },
  orange: { border: "border-orange-500/40", bg: "bg-orange-950/40", badge: "bg-orange-500/20 text-orange-300", text: "text-orange-400", glow: "hover:border-orange-400/70", dot: "bg-orange-400" },
  yellow: { border: "border-yellow-500/40", bg: "bg-yellow-950/40", badge: "bg-yellow-500/20 text-yellow-300", text: "text-yellow-400", glow: "hover:border-yellow-400/70", dot: "bg-yellow-400" },
  pink:   { border: "border-pink-500/40",   bg: "bg-pink-950/40",   badge: "bg-pink-500/20 text-pink-300",   text: "text-pink-400",   glow: "hover:border-pink-400/70",   dot: "bg-pink-400" },
  slate:  { border: "border-slate-500/40",  bg: "bg-slate-800/40",  badge: "bg-slate-500/20 text-slate-300",  text: "text-slate-400",  glow: "hover:border-slate-400/70",  dot: "bg-slate-400" },
};

export function clusterStyle(color: string): ClusterStyle {
  return styles[color as ClusterColor] ?? styles.slate;
}
