typedef struct {
    int id;
    char *name;
    int size;
} Animal;
int compareAnimal(Animal*, Animal*);
void readAnimal(Animal*, FILE*);
void outputAnimal(Animal, FILE*);
void sortAnimals(Animal*, int, int (*comp)(Animal*, Animal*));