#include <stdio.h>
#include <string.h>

#define MAX 1000
#define WORD "XMAS"

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

    int word_len = strlen(WORD);
    int count = 0;

    // Directions: right, left, down, up, diag dr, dl, ur, ul
    int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            for(int dir = 0; dir < 8; dir++) {
                int k;
                for(k = 0; k < word_len; k++) {
                    int ni = i + dx[dir]*k;
                    int nj = j + dy[dir]*k;
                    if(ni < 0 || nj < 0 || ni >= rows || nj >= cols) break;
                    if(grid[ni][nj] != WORD[k]) break;
                }
                if(k == word_len) count++;
            }
        }
    }

    printf("Total occurrences of '%s': %d\n", WORD, count);
    return 0;
}
