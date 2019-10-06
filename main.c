#include <stdio.h>
#include <stdlib.h>
#include "carriage.h"

#define DEBUG

int main(int argc, char** argv){

    FILE *animal_in = fopen("files/animals.txt", "r");
    FILE *human_in = fopen("files/humans.txt", "r");
    FILE *carriages_in = fopen("files/carriages.txt", "r");
    FILE *out = fopen("files/output.txt", "w++");
    FILE *log = fopen("files/log.txt", "w++");

    int animals_len, human_len, carriages_len;
    fscanf(animal_in, "%d", &animals_len);
    fscanf(human_in, "%d", &human_len);
    fscanf(carriages_in, "%d %d", &carriages_len, &sizeOfCarriages);

    Animal *animals = (Animal*) malloc (sizeof(Animal) * animals_len);
    Human *humans = (Human*) malloc(sizeof(Human) * human_len);
    Carriage *carriages = (Carriage*) malloc(sizeof(Carriage) * carriages_len);


    int i;
    for(i = 0; i<animals_len; i++) readAnimal(&(animals[i]), animal_in);
    for(i = 0; i<human_len; i++) readHuman(&(humans[i]), human_in);
    for(i = 0; i<carriages_len; i++) readCarriage(&(carriages[i]), carriages_in);

    sortAnimals(animals, animals_len, &compareAnimalBySize);

#ifdef DEBUG
    fprintf(log, "[animals = %d]\n", animals_len);
    for(i = 0; i<animals_len; i++) outputAnimal(animals[i], log);
    fprintf(log, "[humans = %d]\n", human_len);
    for(i = 0; i<human_len; i++) outputHuman(humans[i], log);
    fprintf(log, "[carriages = %d]\n", carriages_len);
    for(i = 0; i<carriages_len; i++) outputCarriage(carriages[i], log);
#endif

    free(animals);
    free(humans);

    fclose(animal_in);
    fclose(human_in);
    fclose(carriages_in);
    fclose(out);
    fclose(log);

    return 0;
}