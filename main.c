#include <stdio.h>
#include "knapsack.h"

int main(void) {
	// int set[] = {-1, 0, 1, 2, 5, 8, 9, 10}; (sorted)
	int set[] = {1, 0, -1, 5, 10, 8, 2, 9}; // test case (unsorted)
	int length = len(set, sizeof(set));
	int s[length]; // for use in *subset initialisation
	
	// printSet(set, length, isSorted?);
	printSet(set, length, 0); // to compare sorted

	if(unsortedTest(set, length)) { selectionSort(set, length); }

	printSet(set, length, 0); // check if sorted

	// int subset[] = findSubset(set, subset, length, target, sum, index, takeCount);
	int *subset = findSubset(set, s, length, 17, 0, 0, 0);

	if(subset == 0) { printf("no subset found\n"); }
	else { printSet(subset, length, 1); }

	return 0;
}
