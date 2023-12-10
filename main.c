#include <stdio.h>
#include"hashmap.h"



int main() {
    Hashmap *map = createHM();
    int val1=5,val2=8,val3=34,val4=18,val5=55,val6=67;
    char *searchpoke =""; 
    int *lvlpoke=NULL;  
    // Ajout des pokémons dans la hashmap
    addHM(map, "Bulbizarre", &val1);
    addHM(map, "Pikachu", &val2);
    addHM(map, "Roucarnage", &val3);
    addHM(map, "Evoli", &val4);
    addHM(map, "Lucario", &val5);

    // Affichage de la hashmap
    printf("Le jeu pokémon après l'ajout des pokémons\n");
    display(map->head);
    printf("\n");

    // Test de la fonction getHM
    searchpoke = "Roucarnage";
    lvlpoke = getHM(map, searchpoke);
    if (lvlpoke != NULL) {
        printf("Le niveau de %s est : %d \n", searchpoke, *lvlpoke);
    } else {
        printf("%s n'a pas été trouvé dans ce jeu pokémon.\n", searchpoke);
    }

    // Test de la fonction removeHM
    char *transferpoke = "Roucarnage";
    int remove_result = removeHM(map, transferpoke);
    if (remove_result) {
        printf("%s a été transféré.\n", transferpoke);
    } else {
        printf("%s n'a pas été trouvé dans ce jeu pokémon.\n", transferpoke);
    }

    // Affichage après la suppression
    printf("Le jeu pokemon après le transfère de %s:\n", transferpoke);
    display(map->head);
    printf("\n");

    // Test de la fonction updateHM
    char *update_key = "Bulbizarre";
    int new_value = val1 +1; // marche pas demander à Romuald + makefile + suppr + Doxygen
    int update_result = updateHM(map, update_key, &new_value);
    if (update_result) {
        printf("%s est passé au niveau %d ! \n", update_key, new_value);
    } else {
        printf("%s n'a pas été trouvé dans ce jeu pokémon.\n", update_key);
    }

    // Affichage après la mise à jour
    printf("Le jeu pokemon après la montée de niveau de %s:\n", update_key);
    display(map->head);
    printf("\n");

    // Affichage de la taille de la hashmap
    printf("taille hashmap: %d\n", sizeHM(map));
    transferpoke = "Lucario";
    remove_result = removeHM(map, transferpoke);
    printf("Vidage de la Hashmap:\n transfère de %s\n", transferpoke);
    display(map->head);
    
    transferpoke = "Evoli";
    remove_result = removeHM(map, transferpoke);
    printf("transfert de %s\n0", transferpoke);
    display(map->head);

    transferpoke = "Pikachu";
    remove_result = removeHM(map, transferpoke);
    printf("transfert de %s\n0", transferpoke);
    display(map->head);

    transferpoke = "Bulbizarre";
    remove_result = removeHM(map, transferpoke);
    printf("transfert de %s\n0", transferpoke);
    display(map->head);
    free(map);
    printf("\nLa Hashmap a été vidée !\n");
    return 0;
}


