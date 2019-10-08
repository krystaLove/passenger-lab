#include "animal.h"
typedef struct{
    int id;
    char name[100];
    int size;
    int amountAnimals;
    int validAmount;
    int carriage;
    int *animalsID;
    Animal *animals;
} Human;
int compareHumanBySize(Human, Human);
int compareHumanById(Human, Human);
void readHuman(Human*, FILE*);
void outputHuman(Human, FILE*);
void sortHumans(Human*, int, int (*comp)(Human, Human));
void outputHumans(Human*, int, FILE*);
void freeHumans(Human*, int);
void linkHumansWithSortedAnimals(Human*, int, Animal*, int);