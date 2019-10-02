typedef struct Animal{
    int id;
    char *name;
    int size;
} Animal;
int compareAnimal(const Animal*, const Animal*);
void readAnimal(Animal*, FILE*);
void outputAnimal(Animal, FILE*);