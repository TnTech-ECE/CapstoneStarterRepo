# Kyle Plant
# This script is used to clean and organize the output of the
# "log_serial_to_csv.py" file, so it is easier to work with.

import csv
import re


# Function to clean the value part of the entry
def clean_value(value):
    # Remove any '[' characters from the value
    cleaned_value = value.replace("[", "")
    # Extract the numeric part from the value
    cleaned_value = re.findall(r'\d+', cleaned_value)
    # Join the numeric parts to form a single cleaned value
    cleaned_value = ' '.join(cleaned_value)
    return cleaned_value


# Open the input CSV file
with open('logged_data_output.csv', 'r') as csvfile:  # Select the file you want to organize
    reader = csv.reader(csvfile)
    next(reader)  # Skip the header row

    # Open the output CSV file
    with open('logged_data_output_organized.csv', 'w', newline='') as outfile:  # Name the output file as you wish
        writer = csv.writer(outfile)

        # Initialize current_loop variable
        current_loop = None

        # Iterate through each row in the CSV file
        for row in reader:
            if len(row) >= 2:
                timestamp = row[0].strip()
                content = row[1].strip().lstrip("['")  # Remove leading "['" characters
                print(f"Debug: Processing content: {content}")  # Debugging statement

                # Check if the row contains loop information
                if 'Loop' in content:
                    print(f"Debug: Found loop content: {content}")  # Debugging statement
                    current_loop = re.findall(r'Loop (\w)', content)[0]  # Extract loop ID
                    print(f"Debug: Current loop: {current_loop}")  # Debugging statement
                    continue

                # Append loop ID to subsequent entries
                if current_loop:
                    if ':' in content:
                        tag_value = content.split(':')
                        if len(tag_value) == 2:
                            tag = tag_value[0].strip()
                            value = clean_value(tag_value[1])
                            writer.writerow([timestamp, current_loop, tag, value])
                        else:
                            writer.writerow([timestamp, current_loop, content.strip(), ''])
                    else:
                        writer.writerow([timestamp, current_loop, content.strip(), ''])
                else:
                    print("Warning: Loop ID not found. Skipping entry.")
            else:
                print("Warning: Row does not have enough elements to process")
