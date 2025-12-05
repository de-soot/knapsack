#include <stdio.h>
#include <stdlib.h> // for atoi()
#include "knapsack.h" // for helper functions and recursive function

int main(int argc, char **argv) {
	if(argc < 3) { // check for arg count (needs at least the target and 1 element)
		fprintf(stderr, "Usage: %s [target] [elements ...]\n", argv[0]); // print error
		exit(1);
	}

	int target = atoi(argv[1]); // convert argv[1] to int
	int length = argc - 2; // length of set; argc - 2 because argc includes command to execute program and target value, which are not elements of the set
	int set[length] = {}; // init empty array

	parseSet(set, argv, length); // parse args to fill in empty set array
	printSet(set, length, 0); // printSet(set, length, isSubset)

	// print user-defined constraints
	printf("target = %d\nlength = %d\n", target, length);

	// check and sorts set
	if(unsorted(set, length)) {
		sort(set, length);
		printf("sorted ");
		printSet(set, length, 0); // printSet(set, length, isSubset)
	}

	int subsetInit[length]; // initialise subset

	// findSubset(set, subset, length, target, sum, index, takeCount);
	int *subset = findSubset(set, subsetInit, length, target, 0, 0, 0);

	if(subset == NULL) {
		if(target == 0) {
			printf("subset = {} (empty set)\n");
		} else {
			printf("No subset sums to target value");
		}
	}
	else { printSet(subset, length, 1); }

	return 0;
}
