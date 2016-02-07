enum {NORTH, EAST, SOUTH, WEST};
typedef struct room {
    char *message;
    struct room *exits[4];
} room;

// :Initial Choice
char *sign = "Dare you enter the Maze of Doom?";
char *giveup = "You shrug your shoulders, heave a sigh, and turn around "
               "and walk back home.\n\nIt probably wouldn't have been "
               "very fun anyway.";
char *cavein = "With a sickening crunch, the door slides down behind "
               "you.\nYou are trapped.";
char *ikea = "With a flash and a shower of surprisingly sturdy blue "
             "bags, a mystical IKEA elf stands before you.\n\"Pardon me, "
             "friend, but I couldn't help noticing that you seemed a "
             "little lost. Would you mind terribly if I showed you to "
             "wherever you are going?\"";
char *nohelp = "\"I am sorry to have been a bother.\" It disappears, and "
               "a set of tasteful matched silverware clatters down into "
               "the shadows.";
char *shortcut = "The IKEA elf takes you by the hand and whirls you "
                 "through a tangle of vaguely flower-shaped light "
                 "fixtures and bumpy chocolate-filled cookies, and then "
                 "disappears in a final dazzle of cotton sheets and "
                 "laptop stands.";
char *wrongway = "You scrabble desperately at the cave wall, but all you "
                 "get out of the deal is a chipped fingernail.";
char *cavebats = "A troop of cave bats swoops down to claim you as their "
                 "own. As the wind ruffles your hair, all your wordly "
                 "cares melt away and you forget about being anything "
                 "other than a cave bat. You live out your days eating "
                 "insects on the wing and carrying on long chirping "
                 "conversations with your friends. You are happy.";

// :Room Descriptions
char *exitsign = "A faint glow alerts you that the end is near at hand.";
char *falsealarm = "Curses! It was only a cave sprite.";
char *escape = "You blink the light from your eyes.\nHow many centuries "
               "has it been since you've seen the sun?\n\nTo your south "
               "there is a sign, reassuring in its solid, manmade "
               "construction.\nYou turn to read it: ";
char *angus = "You hear the faint skirl of a bagpipe.";
char *stalactite = "A drop of water from a stalactite brushes your "
                   "cheek. It stings a little.\n\n"
                   "A red tasselled pull cord hangs unobtrusively off to "
                   "one side.";
char *normal = "Your footsteps resound from the cave walls.";

room *rooms[6];
