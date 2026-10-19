#ifndef DICE_H
#define DICE_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_DICE 5

struct DiceEval {
    int five;
    int four;
    int full;
    int straight;
    int three;
    int two;
    int pair;   
    int bust;
};

void rollDie(int * die);
void rollDice(int dice[NUM_DICE]);
void rollParticularDice(int dice[NUM_DICE], int * i, int n);
struct DiceEval evalDice(int dice[NUM_DICE]);
void printDice(int dice[NUM_DICE]);
void printEval(struct DiceEval evaluation);

#endif
