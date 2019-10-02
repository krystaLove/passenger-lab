#include <stdio.h>
#include <stdlib.h>
#include "animal.h"
#define MAX_CHAR 1000

int compareAnimal(const Animal *an1, const Animal *an2){
    return an1->size - an2->size;
}

void readAnimal(Animal *animal, FILE *in){
    animal->name = (char*) malloc(sizeof(char) * MAX_CHAR);
    fscanf(in, "%d %s %d", &(animal->id), animal->name, &(animal->size));
}
void outputAnimal(Animal animal, FILE* out){
    fprintf(out, "id = %d\nname = %s\nsize = %d\n", animal.id, animal.name, animal.size);
}
