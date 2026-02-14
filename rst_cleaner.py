import os
import argparse

def find_markers(lines):
    """Return index of first and last '---' lines."""
    marker_indices = [i for i, line in enumerate(lines) if line.strip() == "---"]
    if not marker_indices:
        return None, None
    return marker_indices[0], marker_indices[-1]


def process_file(path, mode):
    """Process a single .rst file based on the selected mode."""
    with open(path, "r", encoding="utf-8") as f:
        lines = f.readlines()

    first, last = find_markers(lines)

    if first is None or last is None:
        print(f"Skipping {path} (no markers found)")
        return

    if mode == "list":
        above = lines[:first]
        below = lines[last+1:]
        print(f"{path}  ->  {len(above)} lines above, {len(below)} lines below")
        if above:
            print("  Above first ---:")
            for l in above:
                print("    ", l.rstrip())
        if below:
            print("  Below last ---:")
            for l in below:
                print("    ", l.rstrip())
        return

    if mode == "delete_top":
        new_lines = lines[first:]
    elif mode == "delete_bottom":
        new_lines = lines[:last + 1]
    elif mode == "clean":
        new_lines = lines[first:last + 1]
    else:
        print(f"Unknown mode: {mode}")
        return

    with open(path, "w", encoding="utf-8") as f:
        f.writelines(new_lines)

    print(f"Processed: {path}")


def walk_and_process(root, mode):
    """Recursively walk through folders and process .rst files."""
    for dirpath, _, filenames in os.walk(root):
        for filename in filenames:
            if filename.endswith(".rst"):
                full_path = os.path.join(dirpath, filename)
                process_file(full_path, mode)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Clean .rst files based on markers (---).")

    parser.add_argument(
        "--mode",
        choices=["list", "delete_top", "delete_bottom", "clean"],
        required=True,
        help=(
            "list = show file names + line count\n"
            "delete_top = remove lines above first ---\n"
            "delete_bottom = remove lines below last ---\n"
            "clean = keep only content between first and last ---"
        )
    )

    args = parser.parse_args()

    ROOT = "."  # script runs at repo root
    walk_and_process(ROOT, args.mode)