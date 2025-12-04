// this file includes helper functions for the main program
// in addition to the main recursive function

#include <stdio.h>
#include <stdlib.h> // for atoi()

// checks if elements are sorted from highest to lowest
int unsorted(int *set, int length) {
	for(int i = 0; i < length - 1; i++) {
		if(set[i] < set[i + 1]) { return 1; }
	}

	return 0;
}

// sort from highest to lowest
void sort(int *set, int length) {
	for(int i = 0; i < length; i++) {
		for(int j = i+1; j < length; j++) {
			if(set[j] < set[i]) { // swap elements
				int temp = set[i];
				set[i] = set[j];
				set[j] = temp;
			}
		}
	}
}

void printSet(int *set, int length, int isSubset) {
	// whether to print "subset" or "set"
	if(isSubset) { printf("subset = {%d", set[0]); }
	else { printf("set = {%d", set[0]); }
	
	for(int i = 1; i < length; i++) {
		int element = set[i];
		// stop when not subset or reach end of subset (denoted by 0)
		if(isSubset && element == 0) { break; }
		printf(", %d", element); // print element
	}
	printf("}\n"); // close bracket
}

// convert command-line args to int array (in-place)
void parseSet(int *set, char **argv, int length) {
	for(int i = 2; i < length; i++) {
		set[i] = atoi(argv[i]); // convert from ascii to int
	}
}

// find the first valid subset in an array of numbers using recursion
// will return the most optimal (having the lowest possbile number of elements) subset if
// the original set is sorted from highest to lowest
int *findSubset(int *set, int *subset, int length, int target, int sum, int index, int takeCount) {
	if(sum == target) { // cannot add more elements
		// denote end of subset (last non-zero element is indexed at takeCount - 1)
		if(takeCount < length) {
			subset[takeCount] = 0;
		}
		
		return subset;
	} else if(sum < target && index < length) {
		// skip current number in set
		int *skip = findSubset(set, subset, length, target, sum, index + 1, takeCount);
		if(skip != 0) { return skip; }
		
		// take current number in set
		int num = set[index];

		if(num != 0) { // valid subset should have no zeros
			subset[takeCount] = num; // latest previously added element is indexed at the current takeCount - 1
			int *take = findSubset(set, subset, length, target, sum + num, index + 1, takeCount + 1);
			if(take != 0) { return take; }
		}
	}

	return 0;
}
