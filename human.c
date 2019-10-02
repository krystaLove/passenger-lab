#include <stdio.h>
#include <stdlib.h>
#include "human.h"
#define MAX_CHAR 1000

int compareHuman(const Human *a, const Human *b){
    return a->size - b->size;
}

void readHuman(Human *human, FILE *in){
    fscanf(in, "%d", &(human->id));
    human->name = (char*) malloc(sizeof(char) * MAX_CHAR);
    fgets(human->name, MAX_CHAR, in);
    fscanf(in, "%d %d", &(human->size), &(human->m));

    if(human->m == 0) return;

    human->animals = (int*) malloc(sizeof(int) * human->m);

    int i;
    for(i = 0; i< human->m; i++){
        fscanf(in, "%d", human->animals + i);
    }
}
void outputHuman(Human human, FILE *out){
    fprintf(out, "id = %d\nname = %s\nsize = %d\n", human.id, human.name, human.size);
}