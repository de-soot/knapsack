#ifndef KNAPSACK_H
#define KNAPSACK_H

int len(int *set, int length);
int unsortedTest(int *set, int length);
int *selectionSort(int *set, int length);
void printSet(int *set, int length, int isSubset);
int *findSubset(int *set, int *subset, int length, int target, int sum, int index, int takeCount);

#endif
