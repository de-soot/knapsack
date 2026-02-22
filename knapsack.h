#ifndef KNAPSACK_H
#define KNAPSACK_H

void sortAsc(int *set, int length);
void sortDesc(int *set, int length);
void printSet(int *set, int length, int isSubset);
void parseSet(int *set, char **argv, int length);
int *findSubset(int *set, int *subset, int length, int target, int sum, int index, int takeCount);

#endif
