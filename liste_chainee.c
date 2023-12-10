#include"liste_chainee.h"

///@brief Fonction hashcode qui permet de code le nom du pokemon en une cle numerique
int HashCode (char *ligne){
    int Code=0;
    for (int i=0;i< strlen(ligne);i++)
        Code=ligne[i]+31*Code;
    return Code%101;
}
///@brief Fonction qui permet de creer le premier chainon de la liste chainee du noeud 
Node* CreatefirstNode(char* random,int *lvl){
    Node* first=malloc(sizeof(Node));
    first->pokemon=random;
    first->lvl = *lvl;
    first->next= NULL;
    return first;
}

///@brief créer un nouveau chainon dans une meme liste chainee d'un noeud de l'arbre
Node* newNode(Node* first,char* random,int *lvl){
    Node* new=CreatefirstNode(random,lvl);
    new->next=first;
    first=new;
    return first;
}
