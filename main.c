#include <stdio.h>
#include <stdlib.h>
#include "animal.h"
#include "human.h"

#define DEBUG

int main(int argc, char** argv){

    FILE *animal_in = fopen("files/animals.txt", "r");
    FILE *human_in = fopen("files/humans.txt", "r");
    FILE *carriages_in = fopen("files/carriages.txt", "r");
    FILE *out = fopen("files/output.txt", "w++");

    int animals_len, human_len, carriages_len;
    fscanf(animal_in, "%d", &animals_len);
    fscanf(human_in, "%d", &human_len);
    fscanf(carriages_in, "%d", &carriages_len);

    Animal *animals = (Animal*) malloc (sizeof(Animal) * animals_len);
    Human *humans = (Human*) malloc(sizeof(Human) * human_len);

    int i;
    for(i = 0; i<animals_len; i++) readAnimal(&(animals[i]), animal_in);
    for(i = 0; i<human_len; i++) readHuman(&(humans[i]), human_in);

#ifdef DEBUG
    for(i = 0; i<animals_len; i++) outputAnimal(animals[i], out);
    for(i = 0; i<human_len; i++) outputHuman(humans[i], out);
#endif

    free(animals);
    free(humans);

    fclose(animal_in);
    fclose(human_in);
    fclose(carriages_in);
    fclose(out);

    return 0;
}