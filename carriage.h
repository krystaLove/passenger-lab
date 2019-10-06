#include "animal.h"
#include "human.h"

enum CarriageType{HUMAN = 1, ANIMAL = 0};
int sizeOfCarriages;
typedef struct {
    int type;
    int elements;
    union{
        Animal* animal;
        Human* human;
    };
} Carriage;

void outputCarriages(Carriage*, int, FILE*);
void readCarriage(Carriage*, FILE*);
void outputCarriage(Carriage, FILE*);