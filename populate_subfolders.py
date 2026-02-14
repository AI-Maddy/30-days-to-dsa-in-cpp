#!/usr/bin/env python3
"""
Script to automatically populate sub-folders in Day directories based on 
content from readme.rst and theory.rst files.
Creates example and exercise files for each key concept identified.
"""

import os
import re
from pathlib import Path
import json

def extract_topics_from_content(content):
    """
    Extract key topics and concepts from README and theory content.
    Looks for headers, bullet points, and key terms.
    """
    topics = []
    
    # Look for RST headers (underlined with ==, --, ~~, etc.)
    lines = content.split('\n')
    for i, line in enumerate(lines):
        if i > 0 and len(lines[i-1]) > 0:
            # Check if this line is a header underline
            prev_line = lines[i-1].strip()
            curr_line = line.strip()
            
            if prev_line and curr_line and len(curr_line) >= 3:
                if all(c == curr_line[0] for c in curr_line) and curr_line[0] in '=-~^_*+#':
                    topics.append(prev_line)
    
    # Look for bullet points with important terms
    bullet_pattern = r'[-•*]\s+([^\n]+)'
    for match in re.finditer(bullet_pattern, content):
        topic = match.group(1).strip()
        # Filter out generic lines
        if len(topic.split()) >= 2 and len(topic) < 100:
            topics.append(topic)
    
    # Look for backtick-enclosed terms (code/concepts)
    code_pattern = r'`([^`]+)`'
    for match in re.finditer(code_pattern, content):
        term = match.group(1).strip()
        if len(term) > 2 and not term.startswith('//'):
            topics.append(term)
    
    # Remove duplicates while preserving order
    seen = set()
    unique_topics = []
    for topic in topics:
        if topic.lower() not in seen:
            seen.add(topic.lower())
            unique_topics.append(topic)
    
    return unique_topics[:10]  # Return top 10 topics

def create_example_file(topic, index, folder_path):
    """Create an example C++ file for a given topic."""
    filename = f"example{index:02d}.cpp"
    filepath = os.path.join(folder_path, "examples", filename)
    
    content = f"""/*
 * Example {index}: {topic}
 * 
 * This example demonstrates the concept of: {topic}
 * 
 * Key Points:
 * - Understanding {topic}
 * - Best practices and usage patterns
 * - Common pitfalls to avoid
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {{
    // Example implementation of {topic}
    
    // TODO: Add implementation code here
    
    cout << "Example {index}: {topic}" << endl;
    
    return 0;
}}
"""
    
    # Only create if file doesn't exist
    if not os.path.exists(filepath):
        os.makedirs(os.path.dirname(filepath), exist_ok=True)
        with open(filepath, 'w') as f:
            f.write(content)
        print(f"✓ Created: {filepath}")
    else:
        print(f"- Skipped (exists): {filepath}")

def create_exercise_file(topic, index, folder_path):
    """Create an exercise C++ file for a given topic."""
    filename = f"exercise{index:02d}.cpp"
    filepath = os.path.join(folder_path, "exercises", filename)
    
    content = f"""/*
 * Exercise {index}: {topic}
 * 
 * Problem: Implement and practice {topic}
 * 
 * Requirements:
 * 1. Understand the concept of {topic}
 * 2. Implement a practical solution
 * 3. Handle edge cases
 * 4. Test with different inputs
 * 
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
using namespace std;

// TODO: Implement your solution here

int main() {{
    // TODO: Add test cases here
    
    cout << "Exercise {index}: {topic}" << endl;
    
    return 0;
}}
"""
    
    # Only create if file doesn't exist
    if not os.path.exists(filepath):
        os.makedirs(os.path.dirname(filepath), exist_ok=True)
        with open(filepath, 'w') as f:
            f.write(content)
        print(f"✓ Created: {filepath}")
    else:
        print(f"- Skipped (exists): {filepath}")

def create_solution_file(topic, index, folder_path):
    """Create a solution C++ file for a given topic."""
    filename = f"solution{index:02d}.cpp"
    filepath = os.path.join(folder_path, "solutions", filename)
    
    content = f"""/*
 * Solution {index}: {topic}
 * 
 * This file contains a sample solution for exercise {index}.
 * 
 * Approach:
 * - Analysis of {topic}
 * - Step-by-step implementation
 * - Time & Space Complexity Analysis
 * 
 * Time Complexity: O(?)  // TODO: Update
 * Space Complexity: O(?) // TODO: Update
 */

#include <iostream>
#include <vector>
using namespace std;

// Solution for exercise {index}: {topic}

// TODO: Add solution code here

int main() {{
    // Sample test case
    cout << "Solution {index}: {topic}" << endl;
    
    return 0;
}}
"""
    
    # Only create if file doesn't exist
    if not os.path.exists(filepath):
        os.makedirs(os.path.dirname(filepath), exist_ok=True)
        with open(filepath, 'w') as f:
            f.write(content)
        print(f"✓ Created: {filepath}")
    else:
        print(f"- Skipped (exists): {filepath}")

def process_day_folder(day_folder_path):
    """Process a single Day folder and populate its sub-folders."""
    
    day_name = os.path.basename(day_folder_path)
    readme_path = os.path.join(day_folder_path, "README.rst")
    theory_path = os.path.join(day_folder_path, "theory.rst")
    
    print(f"\n{'='*70}")
    print(f"Processing: {day_name}")
    print(f"{'='*70}")
    
    # Check if required files exist
    if not os.path.exists(readme_path):
        print(f"⚠ No README.rst found in {day_folder_path}")
        return
    
    if not os.path.exists(theory_path):
        print(f"⚠ No theory.rst found in {day_folder_path}")
        return
    
    # Read content
    try:
        with open(readme_path, 'r', encoding='utf-8') as f:
            readme_content = f.read()
    except Exception as e:
        print(f"✗ Error reading README.rst: {e}")
        return
    
    try:
        with open(theory_path, 'r', encoding='utf-8') as f:
            theory_content = f.read()
    except Exception as e:
        print(f"✗ Error reading theory.rst: {e}")
        return
    
    # Extract topics
    combined_content = readme_content + "\n" + theory_content
    topics = extract_topics_from_content(combined_content)
    
    if not topics:
        print(f"⚠ Could not extract topics from {day_name}")
        return
    
    print(f"\n📚 Extracted {len(topics)} topics:")
    for i, topic in enumerate(topics, 1):
        print(f"   {i}. {topic}")
    
    # Create files for each topic
    print(f"\n📝 Creating example, exercise, and solution files...")
    for index, topic in enumerate(topics, 1):
        try:
            create_example_file(topic, index, day_folder_path)
            create_exercise_file(topic, index, day_folder_path)
            create_solution_file(topic, index, day_folder_path)
        except Exception as e:
            print(f"✗ Error creating files for topic '{topic}': {e}")
    
    # Create metadata file
    metadata = {
        "day": day_name,
        "topics_extracted": len(topics),
        "topics": topics,
        "files_created": {
            "examples": len(topics),
            "exercises": len(topics),
            "solutions": len(topics)
        }
    }
    
    metadata_path = os.path.join(day_folder_path, "subfolder_population_metadata.json")
    try:
        with open(metadata_path, 'w') as f:
            json.dump(metadata, f, indent=2)
        print(f"\n✓ Created metadata file: {metadata_path}")
    except Exception as e:
        print(f"✗ Error creating metadata: {e}")

def main():
    """Main function to process all Day folders."""
    base_path = "/home/maddy/projects/30-days-to-dsa-in-cpp"
    
    # Find all Day folders
    day_folders = []
    for item in sorted(os.listdir(base_path)):
        full_path = os.path.join(base_path, item)
        if os.path.isdir(full_path) and item.startswith("Day"):
            day_folders.append(full_path)
    
    print(f"🔍 Found {len(day_folders)} Day folders")
    print(f"\nStarting population process...\n")
    
    # Process each Day folder
    for day_folder in day_folders:
        process_day_folder(day_folder)
    
    print(f"\n{'='*70}")
    print(f"✅ Population complete!")
    print(f"{'='*70}")

if __name__ == "__main__":
    main()
