#include "human.h"

enum CarriageType{HUMAN = 1, ANIMAL = 0};
typedef struct {
    int type;
    int elements;
    int capacity;
    union{
        Animal *animals;
        Human *humans;
    };
} Carriage;

void outputCarriages(Carriage*, int, FILE*);
void readCarriage(Carriage*, FILE*);
void outputCarriage(Carriage, FILE*);
void freeCarriages(Carriage*, int);