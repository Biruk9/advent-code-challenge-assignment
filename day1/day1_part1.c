#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    FILE *fp = fopen("input1.txt", "r");
    if (!fp) {
        printf("Failed to open file\n");
        return 1;
    }

    int left[1000], right[1000]; // adjust size as needed
    int n = 0;

    // Read input file (two numbers per line)
    while (fscanf(fp, "%d %d", &left[n], &right[n]) == 2) {
        n++;
    }
    fclose(fp);

    // Sort both arrays
    qsort(left, n, sizeof(int), cmpfunc);
    qsort(right, n, sizeof(int), cmpfunc);

    // Compute total distance
    int total_distance = 0;
    for (int i = 0; i < n; i++) {
        int diff = left[i] - right[i];
        if (diff < 0) diff = -diff; // absolute value
        total_distance += diff;
    }

    printf("Total distance: %d\n", total_distance);

    return 0;
}
