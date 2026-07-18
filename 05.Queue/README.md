# Queue

## Overview
Implementation of queue data structures (Linear and Circular).

## Files
- `queue.c` - Linear queue implementation (FIFO - First In First Out)
- `circular_queue.c` - Circular queue implementation with wrap-around logic

## Key Concepts
- **FIFO**: First In First Out principle
- **enqueue**: Add element at rear
- **dequeue**: Remove element from front
- **peek**: View front element
- **Front & Rear**: Pointers to queue boundaries

## Linear Queue
- Simple array-based implementation
- Front pointer moves forward but never resets
- Space wastage issue after dequeue operations

## Circular Queue
- Uses modulo arithmetic for wrap-around
- Efficient space utilization
- Front and Rear wrap around using modulo
- Count variable tracks actual elements

## Operations Implemented
1. Initialize Queue
2. Enqueue (Insert)
3. Dequeue (Remove)
4. Peek (View front)
5. isEmpty/isFull checks
6. Size calculation

## Compilation
```bash
# Linear Queue
gcc -o queue queue.c
./queue

# Circular Queue
gcc -o circular_queue circular_queue.c
./circular_queue
```

## Time Complexity
- Enqueue: O(1)
- Dequeue: O(1)
- Peek: O(1)
