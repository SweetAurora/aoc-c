#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int valueTable[3] = {
        1,
        2,
        3
};

const int pointsTable[3][3] = {
        {3, 6, 0},
        {0, 3, 6},
        {6, 0, 3}
};

const int resultTable[3] = {
        0, 3, 6
};

int findIndex(int resultIndex, int opponentIndex) {
    int value = resultTable[resultIndex];

    for (int i = 0; i < sizeof pointsTable[opponentIndex]; i++) {
        if (pointsTable[opponentIndex][i] == value)
            return i;
    }
    return -1;
}

int main() {
    FILE *file = fopen("./day2/input.txt", "r");

    int points = 0;
    int pointsTwo = 0;
    char buffer[BUFSIZ] = {"\0"};

    while (fgets(buffer, sizeof(buffer), file)) {
        char *string = buffer;
        unsigned char opponent = string[0];
        unsigned char me = string[2];
        int opponentCharId = opponent - 'A';
        int myCharID = me - 'X';

        points += valueTable[myCharID];
        points += pointsTable[opponentCharId][myCharID];

        int newCharID = findIndex(myCharID, opponentCharId);
        pointsTwo += valueTable[newCharID];
        pointsTwo += resultTable[myCharID];
    }

    printf("Part one: %d\n", points);
    printf("Part two: %d", pointsTwo);
    pclose(file);
    return 0;
}