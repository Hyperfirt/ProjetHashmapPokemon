#include"hashmap.h"

///@brief Fonction pour créer la Hashmap et initialiser le pointeur et la taille de la Hashmap
Hashmap *createHM() {
    Hashmap *map = (Hashmap *)malloc(sizeof(Hashmap));
    if (map == NULL) {
        perror("Error creating hashmap");
        exit(EXIT_FAILURE);
    }

    map->head = NULL;
    map->size = 0;

    return map;
}

///@brief Fonction pour ajouter un Arbre dans la Hashmap et compte le nombre de noeud dans la Hashmap
int addHM(Hashmap *map, char *pokemon, int *lvl) {
    int success = 0; // 0 indicates failure, 1 indicates success

    map->head = insertABR(map->head, pokemon, lvl);
    map->size++;

    success = 1;

    return success;
}


///@brief Fonction qui permet de trouver et de renvoyer le niveau d'un pokemon dans la hashmap. retourne NULL si le pokemon n'est pas dans la Hashmap
int *getHM(Hashmap *map, char *pokemon) {
    Node *node = searchNode(map->head, pokemon);
    if (node == NULL)
        return NULL;

    return &(node->lvl);
}

///@brief Fonction pour supprimer un chainon (contenant un pokemon et son niveau)
///@brief si le chainon du pokemon est le dernier de la liste chainée du noeud de l'arbre, alors delete Node supprimer aussi le noeud de l'arbre
///@brief cette fonction change aussi la taille de la Hashmap en fonction de si un noeud de l'arbre a été supprimé ou non
int removeHM(Hashmap *map, char *pokemon) {
    int success = 0; // 0 indicates failure, 1 indicates success

    if (searchNode(map->head, pokemon) != NULL) {
        map->head = deleteNode(map->head, pokemon);
        map->size--;
        success = 1;
    }
    return success;
}


///@brief Fonction qui permet d'afficher la Hashmap
void display(Tree *head) {
    if (head != NULL) {
        printf("[%d] -> ", head->key);
        Node *current = head->chaine;
        while (current != NULL) {
            printf("(%s, %d) -> ", current->pokemon, current->lvl);
            current = current->next;
        }
        printf("NULL\n");
        display(head->left);
        display(head->right);
    }
}

///@brief Fonction pour connaitre la taille de la Hashmap
int sizeHM(Hashmap *map) {
    return map->size;
}
///@brief fonction pour chager le niveau d'un pokemon.
///@brief Le niveau d'un pokemon est contenu dans un chainon d'une liste chainee d'un noeud de l'arbre.
///@brief Cette fonction fait appel à la fonction searchNode pour retrouver le pokemon et son niveau
int updateHM(Hashmap *map, char *key, int *value) {
    Node *node = searchNode(map->head, key);
    if (node != NULL) {
        node->lvl = *value;
        return 1; // Update successful
    }

    return 0; // Key not found
}