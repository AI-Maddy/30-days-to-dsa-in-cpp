import os
import re

# Path to your combined master file
MASTER_FILE = "all_days_combined.rst"

# Base folder where DayXX folders exist
BASE_DIR = "."

# Regex to detect markers like === DAY01 ===
MARKER_PATTERN = re.compile(r"^===\s*DAY(\d{2})\s*===", re.IGNORECASE)

def load_master_content():
    with open(MASTER_FILE, "r", encoding="utf-8") as f:
        return f.readlines()

def split_by_day(lines):
    day_blocks = {}
    current_day = None
    buffer = []

    for line in lines:
        match = MARKER_PATTERN.match(line)
        if match:
            # Save previous block
            if current_day and buffer:
                day_blocks[current_day] = "".join(buffer)
                buffer = []

            current_day = match.group(1)  # "01", "02", ...
        else:
            if current_day:
                buffer.append(line)

    # Save last block
    if current_day and buffer:
        day_blocks[current_day] = "".join(buffer)

    return day_blocks

def write_to_readmes(day_blocks):
    for day, content in day_blocks.items():
        folder_name = f"Day{day}"
        readme_path = os.path.join(folder_name, "README.rst")

        if not os.path.exists(folder_name):
            print(f"Skipping {folder_name} (folder not found)")
            continue

        with open(readme_path, "w", encoding="utf-8") as f:
            f.write(content)

        print(f"Updated {readme_path}")

def main():
    print("Reading master file...")
    lines = load_master_content()

    print("Splitting content by markers...")
    day_blocks = split_by_day(lines)

    print("Writing content into README.rst files...")
    write_to_readmes(day_blocks)

    print("Done.")

if __name__ == "__main__":
    main()