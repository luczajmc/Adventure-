#include <stdio.h>
#include "Adventure!.h"

void scantonextline() {
    scanf("%*[^\n]");
    scanf("%*1[\n]");
}
void scanpastindent() {
    scanf("%*[ \t]");
}
int main() {
    // create initial rooms
    room *exit = &(room) {escape, {0, 0, 0, 0} };
    rooms[0] = &(room) {normal, {0, 0, 0, 0} };
    rooms[1] = &(room) {normal, {0, 0, 0, 0} };
    rooms[2] = &(room) {normal, {0, 0, 0, 0} };
    rooms[3] = &(room) {exitsign, {0, 0, 0, 0} };
    rooms[4] = &(room) {normal, {0, 0, 0, 0} };
    rooms[5] = &(room) {falsealarm, {0, 0, 0, 0} };
    // redefine rooms to connect to eachother
    *rooms[0] = (room) {stalactite, {rooms[4], rooms[1], 0, rooms[2]} };
    *rooms[1] = (room) {normal, {rooms[3], rooms[4], 0, rooms[0]} };
    *rooms[2] = (room) {angus, {0, rooms[0], rooms[4], 0} };
    *rooms[3] = (room) {exitsign, {exit, rooms[5], rooms[1], 0} };
    *rooms[4] = (room) {normal, {rooms[2], 0, rooms[0], rooms[1]} };
    *rooms[5] = (room) {falsealarm, {0, 0, 0, rooms[3]} };

    printf("%s ", sign);
    char response = 0;
    scanpastindent();
    scanf("%c", &response);
    while (1) {
        if (response == 'Y' || response == 'y') {
            room *here = rooms[0];
            room *there = 0;
            printf("%s\n", cavein);
            while (here != exit) {
                printf("Which direction do you try? [n,s,e,w] ");
                scantonextline();
                scanpastindent();
                scanf(" %c", &response);
                switch(response) {
                    case 'N':
                    case 'n':
                        there = here->exits[NORTH];
                        break;
                    case 'S':
                    case 's':
                        there = here->exits[SOUTH];
                        break;
                    case 'E':
                    case 'e':
                        there = here->exits[EAST];
                        break;
                    case 'W':
                    case 'w':
                        there = here->exits[WEST];
                        break;
                    case 'P':
                    case 'p':
                        if (here == rooms[0]) {
                            printf("You pull the cord.\n");
                        }
                        else {
                            break;
                        }
                    case 'H':
                    case 'h':
                        printf("%s ", ikea);
                        scantonextline();
                        scanpastindent();
                        scanf("%c", &response);
                        if (response == 'N' || response == 'n') {
                            printf("%s\n", shortcut);
                            there = exit;
                        }
                        else {
                            printf("%s\n", nohelp);
                            there = here;
                        }
                        break;
                }
                if (there == 0) {
                    printf("%s\n", wrongway);
                }
                else {
                    here = there;
                    printf("%s\n", here->message);
                }
            }
        }
        else if (response == 'N' || response == 'n') {
            printf("%s\n", giveup);
            return 0;
        }
        else {
            // Come on, who _doesn't_ want to enter the Maze of Doom?
            response = 'y';
            continue;
        }
        // the user escaped, but there's that sign again in nice bold letters
        printf("%s ", sign);
        scantonextline();
        scanpastindent();
        scanf("%c", &response);
    }
}
