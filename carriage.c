#include <stdio.h>
#include <stdlib.h>
#include "carriage.h"
#define MAX_CAPACITY 20;
void outputCarriages(Carriage *carriages, int length, FILE* out){
    int i;
    for(i = 0; i < length; i++){
        printf("{%d %d} ", carriages[i].elements, carriages[i].capacity);
        if(carriages[i].elements == 0){
            fprintf(out, "There are no passengers in %d carriage\n", i + 1);
            continue;
        }
        fprintf(out, "The %d carriage include %d passengers:\n", i + 1, carriages[i].elements);
        if(carriages[i].type == HUMAN){
            outputHumans(carriages[i].humans, carriages[i].elements, out);
        } else {
            outputAnimals(carriages[i].animals, carriages[i].elements, out);
        }
    }
}
void outputCarriage(Carriage carriage, FILE *out){
    fprintf(out, "%d ", carriage.type);
}

void readCarriage(Carriage *carriage, FILE* in){
    carriage->elements = 0;
    carriage->capacity = MAX_CAPACITY;
    fscanf(in, "%d", &(carriage->type));
    carriage->humans = NULL;
    carriage->animals = NULL;
}
void freeCarriages(Carriage *carriages, int length){
    int i;
    for(i = 0; i < length; i++){
        if(carriages->elements == 0) continue;
        if(carriages[i].type == HUMAN){
            free(carriages[i].humans);
        } else {
            free(carriages[i].animals);
        }
    }
    free(carriages);
}