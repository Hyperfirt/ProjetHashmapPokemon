#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"liste_chainee.h"

///@brief Structure de l'ABR
typedef struct Tree{
    int key; ///@brief valeur donner par fonction hash
    struct Tree *left; ///@brief pointeur sur fils gauche
    struct Tree *right; ///@brief pointeur sur fils droit
    struct Node *chaine; ///@brief pointeur vers la liste chainee
}Tree;

Tree* CreateT(Node* new,int key);
Tree* insertABR(Tree *head, char *pokemon, int *lvl);
Node *searchNode(Tree *head, char *pokemon);
int RexistThread(Tree* head);
int LexistThread(Tree* head);
Tree* suppMax(Tree* head, Node* elmt);
Tree* RemoveABR(Tree* head/*,int val*/);
Tree *deleteNode(Tree *head, char *pokemon);