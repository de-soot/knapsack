#include <stdio.h>
#include <stdlib.h>
#include "knapsack.h" // for helper functions

int main(int argc, char **argv) {
	if(argc < 3) { // check for arg count
		fprintf(stderr, "Not enough arguments\n"); // print error
		return 1;
	}

	int target = atoi(argv[1]); // convert argv[1] to int
	int length = argc - 2; // minus 2 because argc includes command to execute program and target value, which are not elements of the set
	
	int set[length] = {};

	parseSet(set, argv, length);
	
	// printSet(set, length, isSubset?[0/1 (no/yes)])
	printSet(set, length, 0);
	printf("target = %d\nlength = %d\n", target, length);

	// check and sorts set
	if(unsorted(set, length)) { selectionSort(set, length); }

	int s[length]; // for *subset initialisation

	// findSubset(set, subset, length, target, sum, index, takeCount);
	int *subset = findSubset(set, s, length, target, 0, 0, 0);

	if(subset == 0) { printf("no subset found\n"); }
	else { printSet(subset, length, 1); }

	return 0;
}
