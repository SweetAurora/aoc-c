#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 *
 *      PART ONE BELOW
 *
 */

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

void partOne() {
    printf("Part One.\n");
    FILE *file = fopen("./day1/input.txt", "r");
    char buffer[BUFSIZ] = {"\0"};
    long memory[BUFSIZ] = {0};
    int index = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        long numeric = strtol(buffer, NULL, 10);
        if (numeric == 0) {
            ++index;
        } else {
            memory[index] += numeric;
        }
    }

    long arr[1] = {0};
    findTopX(memory, arr, index, 1);
    fclose(file);
    printf("%lu\n", arr[0]);
}

/*
 *
 *      PART TWO BELOW
 *
 */

void partTwo() {
    printf("Part Two.\n");
    FILE *file = fopen("./day1/input.txt", "r");

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
    printf("%lu\n", topValue);
}

int main() {
    partOne();
    partTwo();
    return 0;
}