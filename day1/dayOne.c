#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void findTopX(const long *array, long output[], const int length, int outputLength) {
    for (int i = 0; i < length; i++) {
        long max = array[i];
        for (int j = 0; j < outputLength; j++) {
            if (output[j] < max) {
                output[j] = max;
                break;
            }
        }
    }
}

int main() {
    FILE *file = fopen_s("./day1/input.txt", "r");

    char buffer[BUFSIZ] = {"\0"};
    long memory[BUFSIZ] = {0};
    int topCount = 3;
    long topArray[topCount];
    memset(topArray, 0, topCount * sizeof(long));
    long topValue = 0;
    int index = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        long numeric = strtol(buffer, NULL, 10);
        if (numeric == 0) {
            index++;
        } else {
            memory[index] += numeric;
        }
    }

    fclose(file);
    findTopX(memory, topArray, index, topCount);
    for (int i = 0; i < topCount; i++) {
        topValue += topArray[i];
    }
    printf("Part One: %lu\n", topArray[0]);
    printf("Part Two: %lu\n", topValue);
    return 0;
}