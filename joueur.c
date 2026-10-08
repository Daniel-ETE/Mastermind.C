#include <stdio.h>

#include "joueur.h"


/*
 * Fonction : initialiser_joueur
 * Rôle : demande le nom du joueur et initialise ses informations.
 */
Joueur initialiser_joueur(void)
{
    Joueur j;

    printf("=== INSCRIPTION DU JOUEUR ===\n");
    printf("Entrez votre nom : ");

    /*
     * Lecture sécurisée du nom.
     */
    if (fgets(j.nom, sizeof(j.nom), stdin) != NULL)
    {
        int i = 0;

        /*
         * Suppression du retour à la ligne.
         */
        while (j.nom[i] != '\0')
        {
            if (j.nom[i] == '\n')
            {
                j.nom[i] = '\0';
                break;
            }

            i++;
        }
    }

    /*
     * Le joueur commence avec 0 essai.
     */
    j.essais = 0;

    printf("Bienvenue %s ! Bonne chance.\n", j.nom);

    return j;
}

