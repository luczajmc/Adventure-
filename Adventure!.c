#include <stdio.h>

int main() {
    enum {NORTH, EAST, SOUTH, WEST};
    typedef struct room {
        char *message;
        struct room *exits;
    } room;
    char *sign = "Dare you enter the Maze of Doom?";
    char *giveup = "You shrug your shoulders, heave a sigh, and turn around "
                   "and walk back home.\nIt probably wouldn't have been very "
                   "fun anyway.";
    char *cavein = "With a sickening crunch, the door slides down behind you.\n"
                   "You are trapped.";
    char *wrongway = "You scrabble desperately at the cave wall, but all you "
                     "get out of the deal is a chipped fingernail.";
    char *exitsign = "A faint glow alerts you that the end is near at hand.";
    char *falsealarm = "Curses! It was only a cave sprite.";
    char *escape = "You blink the light from your eyes. How many centuries has "
                   "it been since you've seen the sun?\nTo your south there is "
                   "a sign, reassuring in its solid, manmade construction. "
                   "You read it:";
    char *normal = "Your footsteps resound from the cave walls.";
    room *rooms[6];
    room *exit = &(room) {escape, {0, 0, 0, 0} };
    rooms[0] = &(room) {cavein, {rooms[5], rooms[1], 0, rooms[2]} };
    rooms[1] = &(room) {normal, {rooms[3], 0, 0, rooms[0]} };
    rooms[2] = &(room) {normal, {0, rooms[0], rooms[4], 0} };
    rooms[3] = &(room) {normal, {exit, rooms[5], rooms[1], 0} };
    rooms[4] = &(room) {normal, {rooms[2], 0, 0, 0} };
    rooms[5] = &(room) {normal, {0, 0, rooms[0], rooms[3]} };

    printf("%s ", sign);
    char response = 0;
    scanf(" %c", &response); // get the first non-whitespace character
    while (1) {
        if (response == 'Y' || response == 'y') {
            printf("Oh, hey, that was really fun!\n");
            break;
            // enter
        }
        else if (response == 'N' || response == 'n') {
            printf("%s\n", giveup);
            return 0;
        }
        else {
            // the user gave an invalid response, so ask again
            printf("%s ", sign);
            scanf("%*[^\n]"); // consume the rest of the line
            scanf(" %c", &response);
        }
    }
}
