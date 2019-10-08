#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "animal.h"
#define MAX_CHAR 100

int compareAnimalBySize(Animal a, Animal b){
    return a.size - b.size;
}

int compareAnimalById(Animal a, Animal b){
    return a.id - b.id;
}

void readAnimal(Animal *animal, FILE *in){
    char *buf = (char*) malloc(sizeof(char) * MAX_CHAR);
    fscanf(in, "%d %s %d", &(animal->id), buf, &(animal->size));
    strncpy(animal->name, buf, MAX_CHAR);
    free(buf);
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
void outputAnimals(Animal *animals, int length, FILE* out){
    fprintf(out, "+--------------------+------+------+\n");
    fprintf(out, "|NAME                |ID    |SIZE  |\n");
    fprintf(out, "+--------------------+------+------+\n");
    int i;
    for(i = 0; i < length; i++){
        fprintf(out, "|%-20s|%-6d|%-6d|\n", animals[i].name, animals[i].id, animals[i].size);
    }
    fprintf(out, "+--------------------+------+------+\n");
}
void freeAnimals(Animal *animals, int length){
    free(animals);
}
