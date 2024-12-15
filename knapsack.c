#include <stdio.h>

int len(int *set, int length) {
	int elementSize = sizeof(set[0]);
	if(elementSize == 0) { return 0; }
	return length / elementSize;
}

int unsortedTest(int *set, int length) {
	for(int i = 0; i < length - 1; i++) {
		if(set[i] > set[i + 1]) { return 1; }
	}

	return 0;
}

int *selectionSort(int *set, int length) {
	int min; // index to the leftmost (minimum) element in unsorted subset

	for(int i = 0; i < length; i++) {
		min = i; // denotes the start of unsorted subset

		for(int j = i; j < length; j++) {
			if(set[j] < set[min]) { // swap elements
				int temp = set[min];
				set[min] = set[j];
				set[j] = temp;
			}
		}
	}
}

void printSet(int *set, int length, int isSubset) {
	printf("{%d", set[0]);
	for(int i = 1; i < length; i++) {
		int element = set[i];
		if(isSubset && element == 0) { break; } // stop when reach end of subset (denoted by 0)
		printf(", %d", element);
	}
	printf("}\n");
}

int *findSubset(int *set, int *subset, int length, int target, int sum, int index, int takeCount) {
	if(sum == target) {
		if(takeCount < length) {
			// to denote end of subset
			subset[takeCount] = 0;
		}
		return subset;
	} else if(sum < target && index < length) {
		// skip current number in set
		int *skip = findSubset(set, subset, length, target, sum, index + 1, takeCount);

		if(skip != 0) { return skip; }
		
		// take current number in set
		int num = set[index];
		if(num != 0) { // subset should have no zeros
			subset[takeCount] = num;
			int *take = findSubset(set, subset, length, target, sum + num, index + 1, takeCount + 1);
			
			if(take != 0) { return take; }
		}
	}

	return 0;
}
