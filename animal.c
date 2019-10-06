#include <stdio.h>
#include <stdlib.h>
#include "animal.h"
#define MAX_CHAR 1000

int compareAnimalBySize(Animal a, Animal b){
    return a.size - b.size;
}

int compareAnimalById(Animal a, Animal b){
    return a.id - b.id;
}

void readAnimal(Animal *animal, FILE *in){
    animal->name = (char*) malloc(sizeof(char) * MAX_CHAR);
    fscanf(in, "%d %s %d", &(animal->id), animal->name, &(animal->size));
}
void outputAnimal(Animal animal, FILE* out){
    fprintf(out, "id = %d\nname = %s\nsize = %d\n", animal.id, animal.name, animal.size);
}

static void swap(Animal *a, Animal *b){
    Animal temp = *a;
    *a = *b;
    *b = temp;
}

void sortAnimals(Animal *animals, int length, int (*comp)(Animal, Animal)){
    int i, j;
    for(i = 0; i < length - 1; i++){
        for(j = i + 1; j < length; j++){
            if((*comp)(animals[i], animals[j]) > 0){
                swap(&animals[i], &animals[j]);
            }
        }
    }
}
