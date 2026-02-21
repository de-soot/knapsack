// this file includes helper functions for the main program
// in addition to the main recursive function

#include <stdio.h>
#include <stdlib.h> // for atoi()

void sort(int *set, int length) { // sort in descending order
	for(int i = 0; i < length; i++) {
		for(int j = i+1; j < length; j++) {
			if(set[i] < set[j]) { // swap elements
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

	// subset only contains zero if target is zero and original set contains zero
	if(isSubset && set[0] == 0) {
		printf("%d}\n", 0); // print 0, close bracket, and newline
		return; // skip for loop below
	}

	// below code only runs if subset does not contain a zero
	for(int i = 0; i < length; i++) {
		int element = set[i];
		// subset containing zero is only valid for target = 0
		// stop when reach end of subset (denoted by 0 for non-zero target)
		if(isSubset && element == 0) { break; }

		// formatting with comma and spaces
		if(i > 0) { printf(", "); }
		printf("%d", element);
	}

	printf("}\n"); // close bracket and newline
}

// convert command-line args to int array (in-place)
void parseSet(int *set, char **argv, int length) {
	for(int i = 0; i < length; i++) {
		set[i] = atoi(argv[2+i]); // ascii to int; 2+i because first 2 args are not set elements
	}
}

// find the first valid subset matching the exact target value using recursion
// will return the subset with the lowest possbile number of elements if
// the original set is sorted in ascending order
int *findSubset(int *set, int *subset, int length, int target, int sum, int index, int takeCount) {
	if(takeCount > 0 && sum == target) { // found non-empty valid subset
		// denote end of subset (last element is indexed at takeCount - 1)
		// subset should not have zeros (which contribute nothing to the sum) if target is non-zero
		if(takeCount < length) { // do not denote if subset is full
			subset[takeCount] = 0;
		}

		return subset;
	}

	if(index < length) { // include/exclude next element in set into subset
		int num = set[index];

		if(target >= 0) {
			// take current number
			if((target == 0 && num == 0) || (target != 0 && num != 0)) { // subset should take no zeros unless target is zero
				subset[takeCount] = num; // append new element to subset
				int *take = findSubset(set, subset, length, target, sum + num, index+1, takeCount+1);
				if(take != NULL) { return take; }
			}

			// skip current number
			int *skip = findSubset(set, subset, length, target, sum, index+1, takeCount);
			if(skip != NULL) { return skip; }
		} else { // negative target
			// skip current number
			int *skip = findSubset(set, subset, length, target, sum, index+1, takeCount);
			if(skip != NULL) { return skip; }

			// take current number
			if(num != 0) { // subset should take no zeros unless target is zero
				subset[takeCount] = num; // append new element to subset
				int *take = findSubset(set, subset, length, target, sum + num, index+1, takeCount+1);
				if(take != NULL) { return take; }
			}
		}
	}

	return NULL; // backtrack if no non-empty valid subset found
}
