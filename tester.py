import subprocess
import random
import argparse

def print_red(text):
    print(f'\033[91m{text}\033[0m', end='\n')

# Parse command-line arguments
parser = argparse.ArgumentParser(description="Run random number tests")
parser.add_argument('-t', '--tests', type=int, default=1000, help="Number of tests to run (default: 1000)")

args = parser.parse_args()
num_tests = args.tests

range_start = int(input("Enter the start of the range: "))
range_end = int(input("Enter the end of the range: "))
amount = int(input("Enter the amount of unique numbers to generate: "))
limit = int(input("Enter the limit to check against: "))

if (range_end - range_start + 1 < amount):
    print(f"Error: Cannot generate {amount} unique numbers in the range {range_start} to {range_end}")
    exit(1)

mid = 0
inc = 0
err_out = ""
m = 1111111111111111111
mx = 0
for i in range(num_tests):
    random_numbers = ' '.join(str(x) for x in random.sample(range(range_start, range_end + 1), amount))
    command = f'./push_swap {random_numbers} | wc -l'
    result = subprocess.run(command, shell=True, capture_output=True, text=True)
    output = result.stdout.strip()
    output_number = int(output)
    mid += output_number
    if (output_number > limit):
        err_out += command + '\n'
        err_out += f'\033[91m{output_number}\033[0m\n'
        inc += 1
    '''else:
        command = f'./push_swap {random_numbers} | ./checker {random_numbers}'
        result = subprocess.run(command, shell=True, capture_output=True, text=True)
        output = result.stdout.strip()
        if (output != 'OK'):
            err_out += command + '\n'
            err_out += f'\033[91m{output}\033[0m\n'''
    if m > output_number:
        m = output_number
    if mx < output_number:
        mx = output_number
    print(f"\r{i+1} out of {num_tests}", end='')

print("")
mid = mid / num_tests
print(err_out)
print(f"Avg: {mid}\nMin: {m}\nMax: {mx}")
print(f">{limit}: {inc}")

