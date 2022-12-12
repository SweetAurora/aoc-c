#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file = fopen("./day2/input.txt", "r");

    int points = 0;
    char buffer[BUFSIZ] = {"\0"};

    while (fgets(buffer, sizeof(buffer), file)) {
        char *string = buffer;
        unsigned char opponent = string[0];
        unsigned char me = string[2];
        int myCharID = me - 21;
        int resulting = myCharID - opponent;

        switch (resulting) {
            case 0: //We win (c = 3||scissors vs x-21 = 3||rock)
                points += 6;
                break;
            case 1: //We lose (b = 2||paper vs x-21 = 3||rock & c = 3||scissors vs y-21 = 4||paper), do nothing
                break;
            case 2: //Equal, we get 3 points
                points += 3;
                break;
            case 3: //We win (a = 1||rock vs y-21 = 4||paper & b = 2||paper vs z-21 = 5||scissors)
                points += 6;
                break;
            case 4: //We lose (a = 1||rock vs z-21 = 5||scissors), do nothing
                break;
            default:
                printf("Unknown resulting value: %d", resulting);
                return 0;
        }

        switch (me) {
            case 'X':
                points += 1;
                break;
            case 'Y':
                points += 2;
                break;
            case 'Z':
                points += 3;
                break;
            default:
                printf("Invalid character found: %c", me);
                return 0;
        }
    }

    printf("Part one: %d", points);
    return 0;
}