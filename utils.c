#include <stdio.h>

#include "utils.h"


/*
 * Fonction : afficher_resultat
 *
 * Affiche le résultat de chaque chiffre :
 *
 * 1 = bien placé
 * 2 = correct mais mal placé
 * 0 = incorrect
 */
void afficher_resultat(Combinaison tentative, Resultat res)
{
    printf("\n========================================\n");
    printf("               RESULTAT\n");
    printf("========================================\n");

    /*
     * Affichage de chaque chiffre.
     */
    for (int i = 0; i < TAILLE_CODE; i++)
    {
        printf("%d -> ", tentative.valeurs[i]);

        if (res.statut[i] == 1)
        {
            printf("[BIEN PLACE]");
        }
        else if (res.statut[i] == 2)
        {
            printf("[CORRECT MAIS MAL PLACE]");
        }
        else
        {
            printf("[INCORRECT]");
        }

        printf("\n");
    }

    printf("----------------------------------------\n");
    printf("Bien places : %d\n", res.bien_places);
    printf("Mal places  : %d\n", res.mal_places);
    printf("========================================\n");
}

