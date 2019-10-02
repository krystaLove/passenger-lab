typedef struct Human{
    int id;
    char *name;
    int size;
    int m;
    int *animals;

} Human;
int compareHuman(const Human*, const Human*);
void readHuman(Human*, FILE*);
void outputHuman(Human, FILE*);