#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted lists
int* mergeSortedLists(int list1[], int size1, int list2[], int size2) {
    int* mergedList = (int*)malloc((size1 + size2) * sizeof(int));
    int i = 0, j = 0, k = 0;

    // Merge the two lists
    while (i < size1 && j < size2) {
        if (list1[i] < list2[j]) {
            mergedList[k++] = list1[i++];
        } else {
            mergedList[k++] = list2[j++];
        }
    }

    // Copy remaining elements from list1 (if any)
    while (i < size1) {
        mergedList[k++] = list1[i++];
    }

    // Copy remaining elements from list2 (if any)
    while (j < size2) {
        mergedList[k++] = list2[j++];
    }

    return mergedList;
}

int main() {
    int list1[] = {1, 3, 5, 7};
    int size1 = sizeof(list1) / sizeof(list1[0]);

    int list2[] = {2, 4, 6, 8};
    int size2 = sizeof(list2) / sizeof(list2[0]);

    // Merge the two sorted lists
    int* mergedList = mergeSortedLists(list1, size1, list2, size2);

    // Print the merged list
    printf("Merged List: ");
    int i; // Declare loop variable outside the for loop
    for (i = 0; i < size1 + size2; i++) {
        printf("%d ", mergedList[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(mergedList);

    return 0;
}
