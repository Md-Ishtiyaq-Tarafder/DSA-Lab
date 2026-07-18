# Recursion

## Overview
Recursive problem-solving techniques with practical examples.

## Files
- `fibonacci.c` - Generate Fibonacci sequence using recursion
- `sum.c` - Calculate sum from 1 to n using recursion

## Key Concepts
- **Base Case**: Condition to stop recursion
- **Recursive Case**: Function calling itself
- **Call Stack**: How recursive calls are stored

## Fibonacci Sequence
- Generates Fibonacci numbers recursively
- Each term is sum of previous two terms (0, 1, 1, 2, 3, 5, 8, ...)
- Formula: F(n) = F(n-1) + F(n-2)
- Time Complexity: O(2^n) - exponential

## Sum Calculation
- Calculates sum of series: 1 + 2 + 3 + ... + n
- Formula: sum(n) = n + sum(n-1)
- Base case: sum(0) = 0
- Time Complexity: O(n) - linear
- Space Complexity: O(n) - stack space

## Compilation
```bash
# Fibonacci
gcc -o fibonacci fibonacci.c
./fibonacci

# Sum
gcc -o sum sum.c
./sum
```

## Example Runs
### Fibonacci
```
Enter the number of terms: 10
Fibonacci Sequence: 0 1 1 2 3 5 8 13 21 34
```

### Sum
```
Enter a number (n): 5
Sum of series from 1 to 5 is: 15
```
