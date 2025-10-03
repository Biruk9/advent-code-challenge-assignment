#include <stdio.h>

#define N 1000

int main() {
    int left[N], right[N];
    int i, j, score = 0;

    FILE *f = fopen("input1.txt", "r");
    if (!f) {
        printf("Error opening input file.\n");
        return 1;
    }

    for(i = 0; i < N; i++) {
        fscanf(f, "%d %d", &left[i], &right[i]);
    }
    fclose(f);

    for(i = 0; i < N; i++) {
        int count = 0;
        for(j = 0; j < N; j++) {
            if(right[j] == left[i])
                count++;
        }
        score += left[i] * count;
    }

    printf("Similarity score: %d\n", score);
    return 0;
}
