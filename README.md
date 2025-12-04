# Knapsack
Recursive search algorithm for the knapsack problem in C.

## Usage

Download the binary files [here](https://github.com/de-soot/knapsack/releases/latest).

Note: The original set can include negative integers and zeros in addition to positive integers.

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

## What
There is a set of numbers that you need to select a subset of to fill a metaphorical knapsack with, where the sum of the numbers in the subset is equal to the maximum value the knapsack can hold.

To solve the knapsack problem, find a way (assuming there is only one) to fill the knapsack with the least number of elements out of all valid subsets.

## Why
For fun; to practice writing, debugging, and compiling programs in a "low-level" language like C; and to try solving problems using recursion.

## How
Below is an explanation of how the program works.
- The program first checks if the set is sorted, and sorts it from smallest to largest (using an iterative implemention of selection sort) if it is not. This is to ensure the valid subset that is found will have the lowest possbile amount of elements.
- Next, it calls the function that goes through and filters all the possible subsets recursively, choosing either to take or skip each element in the set. This creates 2 'branches' with each function call (therefore the algorithm has a time complexity of `O(2^n)`).
- A more detailed explanation of the previous bullet-point would be that it branches all the way down to the subset with 0 elements first (skip all), goes back 1 branch to take the largest element in the sorted set, and if that is not a valid subset, it goes back up another branch to repeat. This is repeated for every branch until it reaches the root, in which it starts the same process all over again but with the first element of the set being in the subset.
- In each function call, the sum of the elements in the subset are compared to the target sum (maximum knapsack capacity). When the branches reach a 'leaf' of the algorithmic 'tree', the subset is returned back up the tree until it reaches the root of the function tree.
- Due to arrays having fixed size, a zero is used to denote the end of the subset (an optimal subset should have no zeros as zeros contribute nothing to the sum) if the subset is not the same as the original sorted set so that garbage from the unused allocated array memory is not displayed when looping through the array to print out the numbers in the subset.
- The root function then returns the subset for the main program to print out on the command-line terminal / console using a for-loop in another function.

## Limitation
For ease-of-use, this program is designed to only handle integer values, but it can be easily modified to allow more (such as floating-point and even characters).
