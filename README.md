# Knapsack
Recursive search algorithm for the knapsack problem in C.

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

Note: The original set can include negative integers and zeros in addition to positive integers.

### Legend
- `[i686/x86_64]` - CPU architecture (32-bit / 64-bit)

- `[target]` - Value of subset's sum

- `[set[0] set[1] ...]` - Set of numbers seperated by spaces; `set[0]` is the first number in the set, `set[1]` is the second, etc.

## What
There is a set of numbers that you need to select a subset of to fill a metaphorical knapsack with, where the sum of the numbers in the subset is equal to the maximum value the knapsack can hold.

To solve the knapsack problem, find a way (assuming there is only one) to fill the knapsack with the least number of elements out of all valid subsets.

## Why
For fun; to practice writing, debugging, and compiling programs in a "low-level" language like C; and to try solving problems using recursion.

## How
Below is an explanation of how the program works.
1. The program checks if the set is sorted, and sorts it from smallest to largest (using an iterative implemention of selection sort) if it is not. This is to ensure the valid subset that is found first will have the lowest possbile amount of elements out of all valid subsets.
2. The recursive function is called and combs through all the possible subsets recursively, choosing either to take or skip each element in the set. Each function call creates 2 new branches (therefore the algorithm has a general time complexity of `O(2^n)`, where `n` is the number of elements in the original set).
3. A more detailed explanation of (2.) would be that the recursive tree branches all the way down to the subset with 0 elements first (skip all), goes back 1 branch to take the largest element in the sorted set, and if that is not a valid subset, it goes back up another branch to repeat. This is repeated for every branch until it reaches the root, in which it starts the same process all over again but with the first element of the set being in the subset.
4. In each function call, the sum of the elements in the subset are compared to the target sum (maximum knapsack capacity). When the branches reach a 'leaf' of the tree, the subset is returned back up the tree until it reaches the root of the function tree.
5. Due to arrays having fixed size, a zero is used to denote the end of the subset (an optimal subset should have no zeros as zeros contribute nothing to the sum) if the subset is not the same as the original sorted set so that garbage from the unused allocated array memory is not displayed when looping through the array to print out the numbers in the subset.
6. The root function then returns the subset for the main program to print out on the command-line terminal / console using a for-loop in another function.

## Limitations
- For ease-of-use, this program is designed to only handle integer values, but it can be easily modified to allow more (such as floating-point and even characters).
- Since the recursive search function skips all elements first, one call is effectively always wasted for every run with a non-zero target value.
