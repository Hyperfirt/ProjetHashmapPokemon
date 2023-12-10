#include"FonctionABR.h"

///@brief Fonction pour créer l'arbre
Tree* CreateT(Node* new,int key){
    Tree* head=malloc(sizeof(Tree));
    head->right=NULL;
    head->left=NULL;
    head->key=0;
    head->chaine=new;
    return head;
};


///@brief Fonction pour insérer d'autre noeud à l'arbre
Tree* insertABR(Tree *head, char *pokemon, int *lvl) {
    int keyHash = 0;
    if (head == NULL) {
        Tree *new = malloc(sizeof(Tree));
        if (new == NULL) {  
            printf("Erreur new=NULL");
            exit(1);
        }
        ///@brief creation de la clé grâce au nom du pokemon
        new->key = HashCode(pokemon); 
        new->left = new->right = NULL;
        ///@brief creation de la liste chaine du noeud de l'arbre
        new->chaine = CreatefirstNode(pokemon, lvl); 
        return new;
    }

    keyHash = HashCode(pokemon);
    ///@brief creation de la liste chaine du noeud de l'arbre positionnement du nouveau noeud dans l'ABR par rapport à la valeur de sa cle
    if (keyHash < head->key) 
        head->left = insertABR(head->left, pokemon, lvl);
    else if (keyHash > head->key)
        head->right = insertABR(head->right, pokemon, lvl);
    else if (keyHash == head->key){
        Node* new = newNode(head->chaine,pokemon,lvl);
        new->next = head->chaine;
        head->chaine = new;
    }
    else {
        Node *new = CreatefirstNode(pokemon, lvl);
        new->next = head->chaine;
        head->chaine = new;
    }
    return head;
}
///@brief creation de la liste chaine du noeud de l'arbre positionnement du nouveau noeud dans l'ABR par rapport à la valeur de sa cle Fonction qui permet de chercher un pokemon et de renvoyer le chainon contenant le nom du pokemon et son niveau
Node *searchNode(Tree *head, char *pokemon) {
    if (head == NULL)
        return NULL;

    int keyHash = HashCode(pokemon);
    if (keyHash < head->key)
        return searchNode(head->left, pokemon);
    else if (keyHash > head->key)
        return searchNode(head->right, pokemon);
    else // key found in the ABR
        return head->chaine;
}

///@brief Fonction qui permet de supprimer un chainon et le noeud de son arbre si ce chainon est le dernier de sa liste chainee
Tree* deleteNode(Tree* head, char* pokemon) {
    if (head == NULL)
        return head;

    int keyHash = HashCode(pokemon);
    if (keyHash < head->key)
        head->left = deleteNode(head->left, pokemon);
    else if (keyHash > head->key)
        head->right = deleteNode(head->right, pokemon);
    else {
        if (head->chaine != NULL) {
            ///@brief  Supprimer la chaîne de caractères associée au nœud
            Node* current = head->chaine;
            Node* next;
            while (current != NULL) {
                next = current->next;
                free(current);
                current = next;
            }
            head->chaine = NULL;
        }

        ///@brief Supprimer le noeud
        Tree* temp = head;
        if (head->left == NULL) {
            head = head->right;
        } else if (head->right == NULL) {
            head = head->left;
        } else {
            ///@brief Trouver le successeur dans l'arbre de droite
            Tree* succ = head->right;
            while (succ->left != NULL) {
                succ = succ->left;
            }

            ///@brief  Copier le successeur dans le noeud courant
            head->key = succ->key;
            head->chaine = succ->chaine;

            ///@brief  Supprimer le successeur récursivement
            head->right = deleteNode(head->right, succ->chaine->pokemon);
        }

        free(temp);
    }

    return head;
}
