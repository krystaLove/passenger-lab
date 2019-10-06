#include <stdio.h>
#include "carriage.h"

void outputCarriages(Carriage *carriages, int length, FILE* out){
    int i;
    for(i = 0; i < length; i++){
        fprintf(out, "The %d carriage include %d passengers:\n", i + 1, carriages[i].elements);
        if(carriages[i].elements == 0) return;
        if(carriages[i].type == HUMAN){
            outputHuman(*(carriages[i].human), out);
        } else {
            outputAnimal(*(carriages[i].animal), out);
        }
    }
}
void outputCarriage(Carriage carriage, FILE *out){
    fprintf(out, "%d ", carriage.type);
}

void readCarriage(Carriage *carriage, FILE* in){
    fscanf(in, "%d", &(carriage->type));
}