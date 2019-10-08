#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "human.h"
#define MAX_CHAR 100

int compareHumanBySize(Human a, Human b){
    return a.size - b.size;
}
int compareHumanById(Human a, Human b){
    return a.id - b.id;
}

void readHuman(Human *human, FILE *in){
    human->animalsID = NULL;
    human->animals = NULL;

    char *buf = (char*) malloc(sizeof(char) * MAX_CHAR);

    fscanf(in, "%d %s %d %d", &(human->id), buf, &(human->size), &(human->amountAnimals));
    strncpy(human->name, buf, MAX_CHAR);

    free(buf);

    if(human->amountAnimals == 0) return;
    human->animalsID = (int*) malloc(sizeof(int) * human->amountAnimals);

    int i;
    for(i = 0; i < human->amountAnimals; i++){
        fscanf(in, "%d", &(human->animalsID[i]));
    }
}
void outputHuman(Human human, FILE *out){
    fprintf(out, "id = %d\nname = %s\nsize = %d\namountAnimals = %d\n", human.id, human.name, human.size, human.amountAnimals);
    fprintf(out, "His animals: ");
    int i;
    for(i = 0; i<human.amountAnimals; i++)
        fprintf(out, "%d ", human.animalsID[i]);
    fprintf(out, "\n");
}

void outputHumans(Human *humans, int length, FILE* out){
    fprintf(out, "+--------------------+------+------+\n");
    fprintf(out, "|NAME                |ID    |SIZE  |\n");
    fprintf(out, "+--------------------+------+------+\n");
    int i;
    for(i = 0; i < length; i++){
        fprintf(out, "|%-20s|%-6d|%-6d|\n", humans[i].name, humans[i].id, humans[i].size);
    }
    fprintf(out, "+--------------------+------+------+\n");
}
void freeHumans(Human *humans, int length){
    int i;
    for(i = 0; i<length; i++){
        free(humans[i].animalsID);
        free(humans[i].animals);
    }
    free(humans);
}

static void swap(Human *a, Human *b){
    Human temp = *a;
    *a = *b;
    *b = temp;
}

void sortHumans(Human *humans, int length, int (*comp)(Human, Human)){
    int i, j;
    for(i = 0; i < length - 1; i++){
        for(j = i + 1; j < length; j++){
            if((*comp)(humans[i], humans[j]) > 0){
                swap(&humans[i], &humans[j]);
            }
        }
    }
}
