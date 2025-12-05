# Knapsack
Implementation of the recursive depth-first search algorithm for the subset sum problem in C.

## What is This
This program implements a solver for a knapsack variant where there is a multiset of integers to select a valid subset from, where a valid subset's sum is exactly equal to the target value.

In the case of multiple valid subsets, a subset with the least number of elements out of all valid subsets is found.

## Why Was This Made
For fun, to practice C programming, and to solve problems using recursion.

## How It Works
1. The program checks if the set is sorted, and sorts it in ascending order (using iterative selection sort) if it is not. This is to ensure the valid subset that is found first will have the lowest possbile amount of elements out of all valid subsets.
2. The recursive function combs through all the possible subsets, choosing either to take or skip each element in the sorted set until it finds a valid subset. Each function call creates 2 new branches like a binary tree, and all the elements have to summed in the case that the subset is the same as the original set, so the algorithm has a time complexity of `O(2^n * n)` (where `n` is the number of elements in the original set).
3. In every function call (except the first, when the subset would be empty at first), the sum of the elements in the subset are first compared to the target value. If the sum of the subset is equal to the target, a valid subset is found. When a valid subset is found or the function calls reach a 'leaf' of the tree (done going through a full path of selecting elements from the original set), the subset is returned back up the tree until it reaches the root.
4. The recursive tree first branches all the way down to the subset with 0 elements (skipping all elements), goes back 1 step to take the largest (last) element in the sorted set, and if that is not a valid subset, it goes back another step to repeat until it finds a valid subset. This repeats until it reaches the root (first call of the recursive function), and it starts the same process all over again but including the smallest element in the subset this time.
5. Due to arrays having fixed size, a zero is used to denote the end of the subset if the subset is not the same as the original sorted set. This is so that garbage from the unused allocated array memory is not displayed when looping through the array to print out the numbers in the subset. For non-zero target values, an optimal subset should have no zeros as zeros contribute nothing to the sum, so zero is used to denote the end of subsets.
6. The first function call then returns the subset for the main program to print out on the terminal using a for-loop in another helper function located in `knapsack.c`.

## Limitations
- For ease-of-use, this program is designed to only handle integer values, but it can be easily modified to allow more (such as floating-point and even characters).
- Since the recursive search function skips all elements first, one call is effectively always wasted for every run with a non-zero target value and non-empty-set solution.

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

## How to Compile
- There is a shell script `build.sh` included to automate the compiling process to produce binaries for both Linux and Windows platforms.

### Requirements
- Since it is a shell (`.sh`) script and not a batch (`.bat`) script, you need to be running Linux for this
- `glibc-devel.x86_64` has to be installed if you want to compile for 64-bit Linux
- `glibc-devel.i686` has to be installed if you want to compile for 32-bit Linux
- `mingw64-gcc` has to be installed if you want to compile for 64-bit Windows
- `mingw32-gcc` has to be installed if you want to compile for 32-bit Windows
