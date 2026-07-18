# Stack

## Overview
Implementation of a stack (LIFO - Last In First Out) data structure.

## Files
- `stack.c` - Stack implementation using array

## Key Concepts
- **LIFO**: Last In First Out principle
- **push**: Insert element at the top
- **pop**: Remove element from the top
- **peek**: View top element without removing
- **Top**: Index pointing to the topmost element

## Operations Implemented
1. Initialize Stack
2. Push (Insert)
3. Pop (Remove)
4. Peek (View top)
5. isEmpty/isFull checks
6. Size calculation
7. Memory management

## Compilation
```bash
gcc -o stack stack.c
./stack
```

## Time Complexity
- Push: O(1)
- Pop: O(1)
- Peek: O(1)
