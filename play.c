#include "play.h"

void play() {
    srand(time(NULL));

    int running = 1;
    int dice[NUM_DICE];

    int num_roll;
    int re_roll[NUM_DICE];

    printf("Welcome to Poker Dice!\n\n");

    while(running) {
        rollDice(dice);
        printDice(dice);

        printf("How many dice would you like to re-roll? ");
        scanf("%d", &num_roll);

        for(int i = 0; i < num_roll; i++) {
            printf("%d: Which one? ", (i + 1));
            scanf("%d", &re_roll[i]);
        }

        rollParticularDice(dice, re_roll, num_roll);
        printDice(dice);
        printEval(evalDice(dice));
        printf("\n");
    }
}
