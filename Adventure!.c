#include <stdio.h>

int main() {
    enum {NORTH, EAST, SOUTH, WEST};
    typedef struct room {
        char *message;
        struct room *exits[4];
    } room;
    char *sign = "Dare you enter the Maze of Doom?";
    char *giveup = "You shrug your shoulders, heave a sigh, and turn around "
                   "and walk back home.\n\nIt probably wouldn't have been very "
                   "fun anyway.";
    char *cavein = "With a sickening crunch, the door slides down behind you.\n"
                   "You are trapped.";
    char *wrongway = "You scrabble desperately at the cave wall, but all you "
                     "get out of the deal is a chipped fingernail.";
    char *exitsign = "A faint glow alerts you that the end is near at hand.";
    char *falsealarm = "Curses! It was only a cave sprite.";
    char *escape = "You blink the light from your eyes.\nHow many centuries "
                   "has it been since you've seen the sun?\n\nTo your south "
                   "there is a sign, reassuring in its solid, manmade "
                   "construction.\nYou turn to read it: ";
    char *angus = "You hear the faint skirl of a bagpipe.";
    char *stalactite = "A drop of water from a stalactite brushes your cheek. "
                       "It stings a little.";
    char *normal = "Your footsteps resound from the cave walls.";
    room *rooms[6];
    room *exit = &(room) {escape, {0, 0, 0, 0} };
    // create initial rooms
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
    scanf(" %c", &response); // get the first non-whitespace character
    while (1) {
        if (response == 'Y' || response == 'y') {
            room *here = rooms[0];
            room *there = 0;
            printf("%s\n", cavein);
            while (here != exit) {
                printf("> ");
                scanf("%*[^\n]"); // consume the rest of the previous line
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
        // the user gave an invalid response or escaped, so ask again
        printf("%s ", sign);
        scanf("%*[^\n]");
        scanf(" %c", &response);
    }
}
