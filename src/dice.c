#include "dice.h"

// Assign a random number from 1 to 6 to a variable.
void rollDie(int * die) {
    *die = (rand() % 6) + 1;
}

// Assign random numbers, each from 1 to 6, to an array of variables.
void rollDice(int dice[NUM_DICE]) {
    for(int i = 0; i < NUM_DICE; i++) {
        rollDie(&dice[i]);
    }
}

// Roll certain dice in an array.
void rollParticularDice(int dice[NUM_DICE], int * which, int n) {
    for(int i = 0; i < n; i++) {
        rollDie(&dice[which[i] - 1]);
    }
}

// Determine hands achieved from an array of dice.
struct DiceEval evalDice(int dice[NUM_DICE]) {
    int count[6] = {0};

    struct DiceEval evaluation = {0, 0, 0, 0, 0, 0, 0, 0};

    // Makes a talley of the number of each number shown on the dice.
    for(int i = 0; i < NUM_DICE; i++) {
        if(dice[i] >= 1 && dice[i] <= 6) {
            count[dice[i] - 1]++;
        }
    }

    // Fundamental hand properties.
    for(int j = 0; j < 6; j++) {
        if(count[j] == 5) evaluation.five++;
        if(count[j] == 4) evaluation.four++;
        if(count[j] == 3) evaluation.three++;
        if(count[j] == 2) evaluation.pair++;
        if(count[j] == 1) evaluation.bust++;
    }

    // Higher-level hand properties:
    // Full houses
    if(evaluation.three && evaluation.pair) {
        evaluation.full++;
        evaluation.three--;
        evaluation.pair--;
    } 

    // Two pairs
    if(evaluation.pair == 2) {
        evaluation.two++;
        evaluation.pair -= 2;
    }

    // Busts
    if(evaluation.bust < NUM_DICE) {
        evaluation.bust = 0;
    } else {
        evaluation.bust = 1;
    }

    return evaluation;
}

// Print dice.
void printDice(int dice[NUM_DICE]) {
    for (int i = 0; i < NUM_DICE; i++) {
        printf("%d", dice[i]);
        if(i < NUM_DICE - 1) printf(", ");
    }

    printf("\n");
}

// Print evaluation.
void printEval(struct DiceEval evaluation) {
    if (evaluation.five) printf("Five of a kind");
    if (evaluation.four) printf("Four of a kind");
    if (evaluation.full) printf("Full house");
    if (evaluation.straight) printf("Straight");
    if (evaluation.three) printf("Three of a kind");
    if (evaluation.two) printf("Two pair");
    if (evaluation.pair) printf("Pair");
    if (evaluation.bust) printf("Bust");

    printf("\n");
}
