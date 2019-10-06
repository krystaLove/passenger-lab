typedef struct{
    int id;
    char *name;
    int size;
    int amountAnimals;
    int *animals;

} Human;
int compareHumanBySize(Human, Human);
int compareHumanById(Human, Human);
void readHuman(Human*, FILE*);
void outputHuman(Human, FILE*);
void sortHumans(Human*, int, int (*comp)(Human, Human));