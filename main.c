#include <stdio.h>
#include <stdlib.h> // for atoi()
#include "knapsack.h" // for helper functions and recursive function

int main(int argc, char **argv) {
	if(argc < 3) { // check for arg count (needs at least the target and 1 element)
		fprintf(stderr, "Usage: %s [target] [elements ...]\n", argv[0]); // print error
		return EXIT_FAILURE;
	}

	int target = atoi(argv[1]); // convert argv[1] to int
	int length = argc - 2; // length of set; argc - 2 because argc includes command to execute program and target value, which are not elements of the set
	int set[length] = {}; // init empty array

	parseSet(set, argv, length); // parse args to fill in empty set array
	printSet(set, length, 0); // printSet(set, length, isSubset)

	// print user-defined constraints
	printf("target = %d\nlength = %d\n", target, length);

	int subsetInit[length]; // initialise subset
	int *subset; // declare subset

	// sorts set
	if(target >= 0) {
		sortAsc(set, length);

		if ((target < 0 && set[0] >= 0) || (target > 0 && set[length - 1] <= 0)) {
			// if target is negative but lowest value is non-negative
			// or target is positive but highest value is non-positive
			subset = NULL; // obviously not possible to reach target
		} else { // might be possible to reach target
			// param list: set, subset, length, target, sum, index, takeCount
			subset = findSubset(set, subsetInit, length, target, 0, 0, 0);
		}
	} else { // negative target
		sortDesc(set, length);

		if ((target < 0 && set[length - 1] >= 0) || (target > 0 && set[0] <= 0)) {
			// if target is negative but lowest value is non-negative
			// or target is positive but highest value is non-positive
			subset = NULL; // obviously not possible to reach target
		} else { // might be possible to reach target
			// param list: set, subset, length, target, sum, index, takeCount
			subset = findSubset(set, subsetInit, length, target, 0, 0, 0);
		}
	}

	// print sorted set
	printf("sorted ");
	printSet(set, length, 0); // printSet(set, length, isSubset)

	if(subset == NULL) {
		if(target == 0) {
			printf("subset = {} (empty set)\n");
		} else {
			printf("No subset sums to target value\n");
		}
	} else {
		printSet(subset, length, 1);
	}

	return 0;
}
