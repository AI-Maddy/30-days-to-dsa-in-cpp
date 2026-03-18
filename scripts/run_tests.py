#!/usr/bin/env python3
"""Compile and run all C++ files to verify they build and execute without errors."""

from __future__ import annotations

import argparse
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
COMPILER = "g++"
STD_FLAGS = ["-std=c++17", "-O2", "-Wall", "-Wextra", "-Wshadow"]
TIMEOUT = 5  # seconds per file


def find_cpp_files(day_filter: str | None = None) -> list[Path]:
    """Return sorted list of .cpp files, optionally filtered by day."""
    pattern = "*.cpp"
    files = sorted(ROOT.rglob(pattern))
    if day_filter:
        day_str = f"Day{int(day_filter):02d}"
        files = [f for f in files if day_str in str(f)]
    return files


def compile_and_run(cpp_file: Path, tmp_dir: str) -> tuple[bool, bool, str]:
    """
    Compile and run a .cpp file.
    Returns (compiled, ran_ok, error_message).
    """
    binary = Path(tmp_dir) / "test_bin"

    # Compile
    compile_cmd = [COMPILER] + STD_FLAGS + [str(cpp_file), "-o", str(binary)]
    try:
        result = subprocess.run(
            compile_cmd,
            capture_output=True,
            text=True,
            timeout=30,
        )
        if result.returncode != 0:
            return False, False, result.stderr.strip()
    except subprocess.TimeoutExpired:
        return False, False, "Compilation timed out"
    except FileNotFoundError:
        return False, False, f"Compiler '{COMPILER}' not found. Install g++."

    # Run
    try:
        run_result = subprocess.run(
            [str(binary)],
            capture_output=True,
            text=True,
            timeout=TIMEOUT,
            input="",
        )
        if run_result.returncode != 0:
            return True, False, f"Exit code {run_result.returncode}: {run_result.stderr.strip()[:200]}"
        return True, True, ""
    except subprocess.TimeoutExpired:
        return True, False, f"Runtime exceeded {TIMEOUT}s"
    except Exception as e:
        return True, False, str(e)


def print_summary(results: list[tuple[Path, bool, bool, str]]) -> None:
    total = len(results)
    compiled = sum(1 for _, c, _, _ in results if c)
    ran_ok = sum(1 for _, _, r, _ in results if r)
    failed_compile = [(p, e) for p, c, _, e in results if not c]
    failed_run = [(p, e) for p, c, r, e in results if c and not r]

    print("\n" + "=" * 60)
    print("📊 TEST SUMMARY")
    print("=" * 60)
    print(f"  Total files    : {total}")
    print(f"  Compiled OK    : {compiled}/{total}  ({'✅' if compiled == total else '⚠️ '})")
    print(f"  Ran OK         : {ran_ok}/{total}  ({'✅' if ran_ok == total else '⚠️ '})")

    if failed_compile:
        print(f"\n❌ Compile failures ({len(failed_compile)}):")
        for path, err in failed_compile:
            rel = path.relative_to(ROOT)
            print(f"  {rel}")
            if err:
                for line in err.splitlines()[:3]:
                    print(f"    {line}")

    if failed_run:
        print(f"\n⚠️  Runtime failures ({len(failed_run)}):")
        for path, err in failed_run:
            rel = path.relative_to(ROOT)
            print(f"  {rel}: {err}")

    print("=" * 60)


def main() -> None:
    parser = argparse.ArgumentParser(description="Compile and run DSA C++ files.")
    parser.add_argument(
        "--day",
        metavar="DD",
        help="Test only a specific day (e.g. --day 01 or --day 15)",
    )
    parser.add_argument(
        "--verbose", "-v",
        action="store_true",
        help="Print each file result as it is processed",
    )
    args = parser.parse_args()

    cpp_files = find_cpp_files(args.day)
    if not cpp_files:
        print(f"No .cpp files found{' for day ' + args.day if args.day else ''}.")
        sys.exit(1)

    print(f"🔍 Found {len(cpp_files)} C++ file(s) to test...")
    if args.day:
        print(f"   (filtered to Day {int(args.day):02d})")

    results = []
    with tempfile.TemporaryDirectory() as tmp_dir:
        for i, cpp_file in enumerate(cpp_files, 1):
            rel = cpp_file.relative_to(ROOT)
            if args.verbose:
                print(f"[{i:3d}/{len(cpp_files)}] {rel} ... ", end="", flush=True)

            compiled, ran_ok, err = compile_and_run(cpp_file, tmp_dir)
            results.append((cpp_file, compiled, ran_ok, err))

            if args.verbose:
                if not compiled:
                    print(f"❌ COMPILE FAIL  {err[:60]}")
                elif not ran_ok:
                    print(f"⚠️  RUNTIME FAIL  {err[:60]}")
                else:
                    print("✅ OK")

    print_summary(results)
    # Exit 1 if any file failed to compile or run
    if any(not c or not r for _, c, r, _ in results):
        sys.exit(1)


if __name__ == "__main__":
    main()
