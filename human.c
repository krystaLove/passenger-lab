#include <stdio.h>
#include <stdlib.h>
#include "human.h"
#define MAX_CHAR 1000

int compareHumanBySize(Human a, Human b){
    return a.size - b.size;
}
int compareHumanById(Human a, Human b){
    return a.id - b.id;
}

void readHuman(Human *human, FILE *in){
    human->name = (char*) malloc(sizeof(char) * MAX_CHAR);

    fscanf(in, "%d %s %d %d", &(human->id), human->name, &(human->size), &(human->amountAnimals));

    if(human->amountAnimals == 0) return;

    human->animals = (int*) malloc(sizeof(int) * human->amountAnimals);

    int i;
    for(i = 0; i < human->amountAnimals; i++){
        fscanf(in, "%d", human->animals + i);
    }
}
void outputHuman(Human human, FILE *out){
    fprintf(out, "id = %d\nname = %s\nsize = %d\n", human.id, human.name, human.size);
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
