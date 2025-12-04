# Knapsack
Implementation of the recursive depth-first search algorithm for the subset sum problem in C.

## What is Knapsack
This program implements a solver for a knapsack variant where there is a multiset of integers to select a valid subset from, where a valid subset's sum is exactly equal to the target value.

In the case of multiple valid subsets, find a subset with the least number of elements out of all valid subsets.

## Why Was This Made
For fun, to practice C programming, and to solve problems using recursion.

## How It Works
1. The program checks if the set is sorted, and sorts it in ascending order (using iterative selection sort) if it is not. This is to ensure the valid subset that is found first will have the lowest possbile amount of elements out of all valid subsets.
2. The recursive function is called and combs through all the possible subsets recursively, choosing either to take or skip each element in the set. Each function call creates 2 new branches (therefore the algorithm has a general time complexity of `O(2^n)`, where `n` is the number of elements in the original set).
3. The recursive tree first branches all the way down to the subset with 0 elements (skipping all elements), goes back 1 branch to take the largest element in the sorted set, and if that is not a valid subset, it goes back up another branch to repeat. This is repeated until it reaches the root, in which it starts the same process all over again but with the smallest element in the subset.
4. In each function call, the sum of the elements in the subset are first compared to the target value. If the sum of the subset is equal to the target, a valid subset is found. When a valid subset is found or the function calls reach a 'leaf' of the tree (done going through a full path of selecting elements from the original set), the subset is returned back up the tree until it reaches the root.
5. Due to arrays having fixed size, a zero is used to denote the end of the subset (for non-zero target values, an optimal subset should have no zeros as zeros contribute nothing to the sum) if the subset is not the same as the original sorted set so that garbage from the unused allocated array memory is not displayed when looping through the array to print out the numbers in the subset.
6. The root function then returns the subset for the main program to print out on the terminal using a for-loop in another function.

## Usage

Download the binary files [here](https://github.com/de-soot/knapsack/releases/latest).

Then follow the examples below to run the program.

### Linux Terminal
```sh
./[i686/x86_64]-redhat-linux [target] [set[0] set[1] ...]
```

#### Example
```sh
./x86_64-redhat-linux 42 1 -13 0 3 0 -1 4 2 8 9 10 24 36
```

Subset of the above command should be `{8, 10, 24}`.

### Windows Command Line
```bat
.\[i686/x86_64]-windows.exe [target] [set[0] set[1] ...]
```

#### Example
```bat
.\x86_64-windows.exe 42 1 -13 0 3 0 -1 4 2 8 9 10 24 36
```

Subset of the above commands should be `{8, 10, 24}`.

### Legend
- `[i686/x86_64]` - CPU architecture (32-bit / 64-bit)

- `[target]` - Value of subset's sum

- `[set[0] set[1] ...]` - Set of numbers seperated by spaces; `set[0]` is the first number in the set, `set[1]` is the second, etc.

## Limitations
- For ease-of-use, this program is designed to only handle integer values, but it can be easily modified to allow more (such as floating-point and even characters).
- Since the recursive search function skips all elements first, one call is effectively always wasted for every run with a non-zero target value.
