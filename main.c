#include <stdio.h>
#include <stdlib.h>
#include "carriage.h"

#define ANIMALS_PATH "files/animals.txt"
#define HUMANS_PATH "files/humans.txt"
#define CARRIAGES_PATH "files/carriages.txt"
#define LOG_PATH "files/log.txt"
#define OUT_PATH "files/output.txt"
#define DEBUG

int readAnimalsData(Animal **animals){
    FILE *animal_in = fopen(ANIMALS_PATH, "r");

    int animals_len = -1;
    fscanf(animal_in, "%d", &animals_len);
    *animals = (Animal*) malloc(sizeof(Animal) * animals_len);

    int i;
    for(i = 0; i<animals_len; i++) readAnimal(&(*animals)[i], animal_in);

    fclose(animal_in);

    return animals_len;
}
int readHumansData(Human **humans){
    FILE *human_in = fopen(HUMANS_PATH, "r");

    int humans_len = -1;
    fscanf(human_in, "%d", &humans_len);
    *humans = (Human*) malloc(sizeof(Human) * humans_len);

    int i;
    for(i = 0; i<humans_len; i++) readHuman(&(*humans)[i], human_in);

    fclose(human_in);

    return humans_len;
}
int readCarriagesData(Carriage **carriages, int *carriage_size){
    FILE *carriages_in = fopen(CARRIAGES_PATH, "r");

    int carriages_len = -1;
    fscanf(carriages_in, "%d %d", &carriages_len, carriage_size);
    *carriages = (Carriage*) malloc(sizeof(Carriage) * carriages_len);

    int i;
    for(i = 0; i<carriages_len; i++) readCarriage(&(*carriages)[i], carriages_in);

    fclose(carriages_in);

    return carriages_len;
}

void givePlaceForAnimals(Carriage **carriages, int carriages_len, Animal *animals, int animals_len, int carriage_size){
    int i;
    Carriage *carriage_arr = *carriages;
    int animal_p = 0;
    for(i = 0; i < carriages_len && animal_p < animals_len; i++){
        if(carriage_arr[i].type == HUMAN) continue;
        int cur_size = carriage_size;
        Carriage *cur_carriage = &carriage_arr[i];
        if(cur_size - animals[animal_p].size >= 0 && cur_carriage->animals == NULL){
            cur_carriage->animals = (Animal*) malloc(sizeof(Animal) * cur_carriage->capacity);
        }
        while(animal_p < animals_len && cur_size - animals[animal_p].size >= 0){
            animals[animal_p].carriage = i + 1;
            (cur_carriage->elements)++;
            if(cur_carriage->elements >= cur_carriage->capacity){
                (cur_carriage->capacity) *= 2;
                cur_carriage->animals = realloc(cur_carriage->animals, cur_carriage->capacity);
            }
            cur_carriage->animals[cur_carriage->elements - 1] = animals[animal_p];
            cur_size -= animals[animal_p].size;
            animal_p++;
        }
    }
}
void givePlaceForHumans(Carriage **carriages, int carriages_len, Human *humans, int humans_len, int carriage_size){
    int i;
    Carriage *carriage_arr = *carriages;
    int human_p = 0;
    for(i = 0; i < carriages_len && human_p < humans_len; i++){
        if(carriage_arr[i].type == ANIMAL) continue;
        int cur_size = carriage_size;
        Carriage *cur_carriage = &carriage_arr[i];
        if(cur_size - humans[human_p].size >= 0 && cur_carriage->humans == NULL){
            cur_carriage->humans = (Human*) malloc(sizeof(Human) * cur_carriage->capacity);
        }
        while(human_p < humans_len && cur_size - humans[human_p].size >= 0){
            humans[human_p].carriage = i + 1;
            (cur_carriage->elements)++;
            if(cur_carriage->elements >= cur_carriage->capacity){
                (cur_carriage->capacity) *= 2;
                cur_carriage->humans = realloc(cur_carriage->humans, cur_carriage->capacity);
            }
            cur_carriage->humans[cur_carriage->elements - 1] = humans[human_p];
            cur_size -= humans[human_p].size;
            human_p++;
        }
    }
}

int main(int argc, char** argv){
    FILE *out = fopen(OUT_PATH, "w++");
    FILE *log = fopen(LOG_PATH, "w++");

    Animal *animals;
    Human *humans;
    Carriage *carriages;

    int animals_len = readAnimalsData(&animals);
    int human_len = readHumansData(&humans);
    int carriage_size = -1;
    int carriages_len = readCarriagesData(&carriages, &carriage_size);

    sortAnimals(animals, animals_len, &compareAnimalBySize);
    sortHumans(humans, human_len, &compareHumanBySize);

    givePlaceForAnimals(&carriages, carriages_len, animals, animals_len, carriage_size);
    givePlaceForHumans(&carriages, carriages_len, humans, human_len, carriage_size);
    outputCarriages(carriages, carriages_len, out);

    fprintf(out, "\nHumans: \n");
    linkHumansWithSortedAnimals(humans, human_len, animals, animals_len);
    outputHumans(humans, human_len, out);

#ifdef DEBUG
    int log_i;
    fprintf(log, "[animals = %d]\n", animals_len);
    outputAnimals(animals, animals_len, log);
    fprintf(log, "[humans = %d]\n", human_len);
    outputHumans(humans, human_len, log);
    fprintf(log, "[carriages = %d]\n", carriages_len);
    for(log_i = 0; log_i<carriages_len; log_i++) outputCarriage(carriages[log_i], log);
#endif

    freeAnimals(animals, animals_len);
    freeHumans(humans, human_len);
    freeCarriages(carriages, carriages_len);

    fclose(out);
    fclose(log);

    return 0;
}