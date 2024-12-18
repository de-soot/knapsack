# Knapsack
Recursive brute-force depth-first search (DFS) algorithm solution to the knapsack problem hand-written in C.

## Usage

Download the binary files [here](https://github.com/de-soot/knapsack/releases/latest).

Note: The numbers in the set can be negative and everything will still work as expected.

### Linux Terminal
```bash
./[i686/x86_64]-redhat-linux [target] [set[0] set[1] ...]
```

#### Example
```bash
./x86_64-redhat-linux 42 1 -13 0 3 0 -1 4 2 8 9 10 24 36
```
Subset of the above should be `{8, 36}`.

### Windows Command Line
```bat
[i686/x86_64]-windows.exe [target] [set[0] set[1] ...]
```

#### Example
```bat
x86_64-windows.exe 42 1 -13 3 0 4 0 8 2 -1 9 10 24 36
```
Subset of the above should also be `{8, 36}`.

### Legend
- `[i686/x86_64]` - cpu architecture

- `[target]` - value of subset's sum

- `[set[0] set[1] ...]` - set of numbers seperated by spaces; `set[0]` is the first number in the set, `set[1]` is the second, etc.


## What
There is a set of numbers that you need to fill a knapsack with, where the sum of the numbers in the subset is equal to the maximum the knapsack can hold.
To solve the knapsack problem, find the optimal (subset has to have the smallest number of elements possible) way to fill the knapsack.

## Why
For fun; to practice writing, debugging, and compiling programs in a low-level language; and to try solving algorithmic problems using recursion.

## How
Below is an explanation of how the program works.
- The program first checks if the set is sorted, and sorts it (using an iterative implemention of selection sort) if it is not. This is to ensure the subset that is found is one with the least amount of elements.
- Next, it calls the function that goes through and filters all the possible subsets recursively, choosing either to take or skip each element in the set. This creates 2 'branches' with each function call (therefore making the algorithm have a time complexity of `O(2^n)`).
To be more precise, it technically branches all the way down to a subset with 0 elements (hence why the algorithm is classified as DFS) because the function skips first before taking so that the sum does not have to change back after taking.
- The sum of the elements in the subset are compared to the target sum (maximum knapsack capacity) until the branches reach a dead end (aptly named the 'leaves' of the algorithmic 'tree'), and returned back up the tree until it reaches the root of the function tree.
- Due to how arrays in C work (having a fixed size, references decaying to pointers, etc.), if the subset is not full (the same size as the original set), a zero is used to denote the end of the subset (an optimal subset should have no zeros, as zeros contribute nothing to the sum) so that random numbers are not displayed when we later loop through the array to print out the numbers in the subset.
- The root function then returns the subset for the main program to print out on the command-line terminal / console using a for-loop in another function.

## Limitations
Below are some of the limitations of this program:
- Regardless of the number of optimal solutions, the program will only give one and it will always be the same result
- This program only handles values of type `int` (integer), but it can be easily modified to allow more, such as `float` (single-precision floating-point), `double` (double-precision floating-point), and even `char` (character).
