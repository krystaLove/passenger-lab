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
    human->validAmount = 0;
    human->carriage = -1;

    char *buf = (char*) malloc(sizeof(char) * MAX_CHAR);

    fscanf(in, "%d %s %d %d", &(human->id), buf, &(human->size), &(human->amountAnimals));
    strncpy(human->name, buf, MAX_CHAR);

    free(buf);

    if(human->amountAnimals == 0) return;
    human->animalsID = (int*) malloc(sizeof(int) * human->amountAnimals);
    human->animals = (Animal*) malloc(sizeof(Animal) * human->amountAnimals);

    int i;
    for(i = 0; i < human->amountAnimals; i++){
        fscanf(in, "%d", &(human->animalsID[i]));
    }
}
void linkHumansWithSortedAnimals(Human *humans, int human_len, Animal *animals, int animals_len){
    sortAnimals(animals, animals_len, compareAnimalById);
    int i;
    for(i = 0; i < human_len; i++){
        Human *cur_human = &humans[i];
        int j = 0, k = 0;
        int animal_p = 0;
        while(j < cur_human->amountAnimals && k < animals_len){
            if(cur_human->animalsID[j] < animals[k].id){
                j++;
                continue;
            }
            if(cur_human->animalsID[j] > animals[k].id){
                k++;
            } else {
                cur_human->animals[animal_p++] = animals[k];
                j++;
                k++;
            }
        }
        cur_human->validAmount = animal_p;
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
    fprintf(out, "+--------------------+------+------+--------+\n");
    fprintf(out, "|HUMAN NAME          |ID    |SIZE  |CARRIAGE|\n");
    fprintf(out, "+--------------------+------+------+--------+\n");
    int i, j;
    for(i = 0; i < length; i++){
        fprintf(out, "|%-20s|%-6d|%-6d|%-8d|\n", humans[i].name, humans[i].id, humans[i].size, humans[i].carriage);
        if(humans[i].validAmount > 0){
            fprintf(out, "+--------------------+------+------+--------+\n");
            fprintf(out, "|HIS ANIMALS                                |\n");
            //fprintf(out, "+--------------------+------+------+--------+\n");
            outputAnimals(humans[i].animals, humans[i].validAmount, out);
            //fprintf(out, "+--------------------+------+------+--------+\n");
            fprintf(out, "|END OF ANIMALS                             |\n");
            fprintf(out, "+--------------------+------+------+--------+\n");
        }

    }
    fprintf(out, "+--------------------+------+------+--------+\n");
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
