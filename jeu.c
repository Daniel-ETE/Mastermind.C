#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "jeu.h"


/*
 * Fonction : generer_combinaison_secrete
 * Rôle : Génère une combinaison aléatoire de 4 chiffres entre 0 et 9.
 */
Combinaison generer_combinaison_secrete(void)
{
    Combinaison code_secret;

    /*
     * Cette variable permet d'initialiser le générateur
     * de nombres aléatoires une seule fois.
     */
    static int hasard_initialise = 0;

    if (!hasard_initialise)
    {
        srand((unsigned int)time(NULL));
        hasard_initialise = 1;
    }

    /*
     * Génération des 4 chiffres.
     */
    for (int i = 0; i < TAILLE_CODE; i++)
    {
        code_secret.valeurs[i] = rand() % 10;
    }

    return code_secret;
}


/*
 * Fonction : saisir_chiffre
 * Rôle : Demande au joueur un chiffre valide entre 0 et 9.
 */
static int saisir_chiffre(void)
{
    char ligne[100];
    int valeur;
    char autre;

    while (1)
    {
        /*
         * Lecture d'une ligne complète.
         */
        if (fgets(ligne, sizeof(ligne), stdin) == NULL)
        {
            printf("\nErreur de lecture.\n");
            exit(EXIT_FAILURE);
        }

        /*
         * Vérifie qu'il y a bien un seul nombre.
         */
        if (sscanf(ligne, "%d %c", &valeur, &autre) == 1)
        {
            if (valeur >= 0 && valeur <= 9)
            {
                return valeur;
            }
        }

        printf("Erreur ! Entrez un seul chiffre entre 0 et 9 : ");
    }
}


/*
 * Fonction : saisir_tentative
 * Rôle : Demande au joueur les 4 chiffres de sa tentative.
 */
Combinaison saisir_tentative(void)
{
    Combinaison tentative;

    printf("\n--- Votre proposition ---\n");

    for (int i = 0; i < TAILLE_CODE; i++)
    {
        printf("Chiffre %d (entre 0 et 9) : ", i + 1);

        tentative.valeurs[i] = saisir_chiffre();
    }

    return tentative;
}


/*
 * Fonction : comparer_combinaisons
 *
 * Compare la tentative du joueur avec le code secret.
 *
 * 1. On recherche d'abord les chiffres bien placés.
 * 2. Ensuite, parmi les chiffres restants, on recherche
 *    ceux qui sont corrects mais mal placés.
 */
Resultat comparer_combinaisons(Combinaison secrete,
                               Combinaison tentative)
{
    Resultat res = {0};

    /*
     * Permet de savoir quelles positions ont déjà été utilisées.
     */
    int examine_secret[TAILLE_CODE] = {0};
    int examine_tentative[TAILLE_CODE] = {0};


    /*
     * ÉTAPE 1 :
     * Recherche des chiffres bien placés.
     */
    for (int i = 0; i < TAILLE_CODE; i++)
    {
        if (tentative.valeurs[i] == secrete.valeurs[i])
        {
            res.bien_places++;

            /*
             * 1 signifie : bien placé.
             */
            res.statut[i] = 1;

            /*
             * On marque ces positions comme déjà traitées.
             */
            examine_secret[i] = 1;
            examine_tentative[i] = 1;
        }
    }


    /*
     * ÉTAPE 2 :
     * Recherche des chiffres corrects mais mal placés.
     */
    for (int i = 0; i < TAILLE_CODE; i++)
    {
        /*
         * On ignore les chiffres déjà bien placés.
         */
        if (examine_tentative[i] == 0)
        {
            for (int j = 0; j < TAILLE_CODE; j++)
            {
                /*
                 * Si le chiffre existe dans le code secret
                 * mais à une autre position.
                 */
                if (examine_secret[j] == 0 &&
                    tentative.valeurs[i] == secrete.valeurs[j])
                {
                    res.mal_places++;

                    /*
                     * 2 signifie :
                     * correct mais mal placé.
                     */
                    res.statut[i] = 2;

                    /*
                     * Ce chiffre du secret ne doit plus
                     * être utilisé.
                     */
                    examine_secret[j] = 1;

                    break;
                }
            }
        }
    }

    return res;
}

