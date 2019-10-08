typedef struct {
    int id;
    char name[100];
    int size;
} Animal;
int compareAnimalById(Animal, Animal);
int compareAnimalBySize(Animal, Animal);
void readAnimal(Animal*, FILE*);
void outputAnimal(Animal, FILE*);
void sortAnimals(Animal*, int, int (*comp)(Animal, Animal));
void outputAnimals(Animal*, int length, FILE*);
void freeAnimals(Animal*, int);