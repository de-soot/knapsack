// this file includes helper functions for the main program
// in addition to the main recursive function

#include <stdio.h>
#include <stdlib.h> // for atoi()

// checks if elements are sorted in ascending order
int unsorted(int *set, int length) {
	for(int i = 0; i < length - 1; i++) {
		if(set[i] > set[i+1]) { return 1; }
	}

	return 0;
}

// sort in ascending order
void sort(int *set, int length) {
	for(int i = 0; i < length; i++) {
		for(int j = i+1; j < length; j++) {
			if(set[i] > set[j]) { // swap elements
				int temp = set[i];
				set[i] = set[j];
				set[j] = temp;
			}
		}
	}
}

void printSet(int *set, int length, int isSubset) {
	// whether to print "subset" or "set"
	if(isSubset) { printf("subset = {"); }
	else { printf("set = {"); }
	
	for(int i = 0; i < length; i++) {
		int element = set[i];
		// stop when not subset or reach end of subset (denoted by 0)
		if(isSubset && element == 0) { break; }
		
		// formatting with comma and spaces
		if(i > 0) { printf(", "); }
		printf("%d", element);
	}

	printf("}\n"); // close bracket
}

// convert command-line args to int array (in-place)
void parseSet(int *set, char **argv, int length) {
	for(int i = 0; i < length; i++) {
		set[i] = atoi(argv[2+i]); // ascii to int; 2+i because first 2 args are not set elements
	}
}

// find the first valid subset in an array of numbers using recursion
// will return the subset with the lowest possbile number of elements if
// the original set is sorted in ascending order.
// will skip all first
int *findSubset(int *set, int *subset, int length, int target, int sum, int index, int takeCount) {
	if(sum == target) { // found a valid subset
		// denote end of subset (last non-zero element is indexed at takeCount - 1)
		// because optimal subset should not have zeros (which contribute nothing to the sum) if target is non-zero
		if(takeCount < length) { // do not denote if subset is full
			subset[takeCount] = 0;
		}
		
		return subset;
	} else if(index < length) {
		// skip current number in set
		int *skip = findSubset(set, subset, length, target, sum, index+1, takeCount);
		if(skip != 0) { return skip; }
		
		int num = set[index];

		// take current number in set
		if(num != 0) { // optimal subset should take no zeros
			subset[takeCount] = num; // latest previously added element is indexed at the current takeCount - 1
			int *take = findSubset(set, subset, length, target, sum + num, index+1, takeCount+1);
			if(take != 0) { return take; }
		}
	}

	return 0; // if reached the end of set and could not find a valid subset, end current traversal
}
