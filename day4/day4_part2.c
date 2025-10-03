#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {
    char grid[MAX][MAX];
    int rows = 0, cols = 0;

    FILE *f = fopen("input1.txt", "r");
    if(!f) { printf("Cannot open file\n"); return 1; }

    while(fgets(grid[rows], MAX, f)) {
        int len = strlen(grid[rows]);
        if(grid[rows][len-1] == '\n') grid[rows][len-1] = '\0';
        len = strlen(grid[rows]);
        if(cols == 0) cols = len;
        rows++;
    }
    fclose(f);

    int count = 0;

    for(int i = 1; i < rows-1; i++) {
        for(int j = 1; j < cols-1; j++) {
            if(grid[i][j] == 'A') {
                // Diagonal 1: top-left & bottom-right
                char tl = grid[i-1][j-1];
                char br = grid[i+1][j+1];
                int diag1 = (tl=='M' && br=='S') || (tl=='S' && br=='M');

                // Diagonal 2: top-right & bottom-left
                char tr = grid[i-1][j+1];
                char bl = grid[i+1][j-1];
                int diag2 = (tr=='M' && bl=='S') || (tr=='S' && bl=='M');

                if(diag1 && diag2) count++;
            }
        }
    }

    printf("Total X-MAS patterns: %d\n", count);
    return 0;
}
