#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *f = fopen("input3.txt", "r");
    if (f == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char buffer[100000]; // large enough buffer for your file
    int idx = 0;
    int total = 0;
    char c;

    // Read the entire file into buffer
    while ((c = fgetc(f)) != EOF) {
        buffer[idx++] = c;
    }
    buffer[idx] = '\0'; // null-terminate string
    fclose(f);

    // Scan the buffer for "mul(X,Y)"
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == 'm' && buffer[i+1] == 'u' && buffer[i+2] == 'l' && buffer[i+3] == '(') {
            i += 4; // skip "mul("

            int X = 0;
            while (isdigit(buffer[i])) {
                X = X * 10 + (buffer[i] - '0');
                i++;
            }

            // Skip any spaces before comma
            while (buffer[i] == ' ') i++;

            if (buffer[i] != ',') continue; // not a valid mul
            i++; // skip comma

            // Skip spaces after comma
            while (buffer[i] == ' ') i++;

            int Y = 0;
            if (!isdigit(buffer[i])) continue; // not a valid number
            while (isdigit(buffer[i])) {
                Y = Y * 10 + (buffer[i] - '0');
                i++;
            }

            // Skip spaces before closing parenthesis
            while (buffer[i] == ' ') i++;

            if (buffer[i] != ')') continue; // not valid
            total += X * Y;
        }
    }

    printf("Total sum of all mul(X,Y) instructions: %d\n", total);
    return 0;
}
