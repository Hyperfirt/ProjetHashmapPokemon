#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"FonctionABR.h"

///@brief Structure de la Hashmap
typedef struct Hashmap{
    struct Tree* head; ///@brief tête de la Hashmap
    int size; ///@brief taille de la Hashmap
}Hashmap;


Hashmap *createHM();
int addHM(Hashmap *map, char *pokemon, int *lvl);
int *getHM(Hashmap *map, char *pokemon);
int removeHM(Hashmap *map, char *pokemon); 
void display(Tree *head);
int sizeHM(Hashmap *map);
int updateHM(Hashmap *map, char *key, int *value);
