#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int containsArray(const char *array, char value, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return 1;
        }
    }

    return 0;
}

int partOne(char *string) {
    int localSum = 0;
    int length = strlen(string);
    int halfLength = length / 2;
    char *firstHalf = malloc(halfLength + 1);
    char *secondHalf = malloc(halfLength + 1);
    memcpy(firstHalf, string, halfLength);
    firstHalf[halfLength] = '\0';
    memcpy(secondHalf, string + halfLength, halfLength);
    secondHalf[halfLength] = '\0';
    char duplicate[halfLength];
    memset(duplicate, 0, halfLength * sizeof(char));
    for (int i = 0; i < halfLength; i++) {
        for (int j = 0; j < halfLength; j++) {
            if (firstHalf[i] == secondHalf[j] && !containsArray(duplicate, firstHalf[i], halfLength)) {
                char entry = firstHalf[i];
                duplicate[i] = entry;
                if (entry >= 'a') {
                    localSum += (entry - 'a') + 1;
                } else {
                    localSum += (entry - 'A') + 27;
                }
            }
        }
    }
    free(firstHalf);
    free(secondHalf);
    return localSum;
}

int partTwo(char *groups[3]) {
    for (int x = 0; x < strlen(groups[0]); x++) {
        for (int y = 0; y < strlen(groups[1]); y++) {
            for (int z = 0; z < strlen(groups[2]); z++) {
                if (groups[0][x] == groups[1][y] && groups[1][y] == groups[2][z]) {
                    char entry = groups[0][x];
                    if (entry >= 'a') {
                        return entry - 'a' + 1;
                    } else {
                        return entry - 'A' + 27;
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    FILE *file = fopen("./day3/input.txt", "r");
    int sumOne = 0;
    int sumTwo = 0;
    int groupsFound = 0;
    char *groups[3];

    char buffer[BUFSIZ] = {"\0"};

    while (fgets(buffer, sizeof buffer, file)) {
        char *string = buffer;
        sumOne += partOne(string);
        groups[groupsFound] = calloc(1, strlen(string)*sizeof (char));
        strcpy(groups[groupsFound++], string);

        if (groupsFound == 3) {
            groupsFound = 0;
            sumTwo += partTwo(groups);
        }
    }

    printf("Part One: %d\n", sumOne);
    printf("Part Two: %d\n", sumTwo);
}