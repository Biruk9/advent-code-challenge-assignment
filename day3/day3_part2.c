#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    // Read the input from a file
    FILE *fp = fopen("input3.txt", "r");
    if (!fp) {
        perror("Failed to open file");
        return 1;
    }

    // Determine file size
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *data = malloc(fsize + 1);
    if (!data) {
        perror("Failed to allocate memory");
        return 1;
    }

    fread(data, 1, fsize, fp);
    data[fsize] = '\0';
    fclose(fp);

    int mul_enabled = 1; // mul is initially enabled
    long long total = 0;

    char *p = data;
    while (*p) {
        // Check for "do()"
        if (strncmp(p, "do()", 4) == 0) {
            mul_enabled = 1;
            p += 4;
        }
        // Check for "don't()"
        else if (strncmp(p, "don't()", 7) == 0) {
            mul_enabled = 0;
            p += 7;
        }
        // Check for "mul(x,y)"
        else if (strncmp(p, "mul(", 4) == 0) {
            p += 4;
            int x = 0, y = 0;
            // Parse first number
            while (isdigit(*p)) {
                x = x * 10 + (*p - '0');
                p++;
            }
            if (*p != ',') continue;
            p++; // skip comma
            // Parse second number
            while (isdigit(*p)) {
                y = y * 10 + (*p - '0');
                p++;
            }
            if (*p != ')') continue;
            p++; // skip closing parenthesis
            if (mul_enabled) {
                total += (long long)x * y;
            }
        } else {
            p++;
        }
    }

    printf("%lld\n", total);

    free(data);
    return 0;
}
