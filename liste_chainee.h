#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

///@brief structure du chainon
typedef struct Node{
    struct Node *next; ///@brief pointeur sur le chainon d'après
    char *pokemon; ///@brief nom du pokemon
    int lvl; ///@brief niveau du pokemon
}Node;

int HashCode (char *ligne);
Node* CreatefirstNode(char* pokemon,int *lvl);
Node* newNode(Node* first,char* pokemon,int *lvl);
