#include <stdio.h>

#include "joueur.h"
#include "jeu.h"
#include "utils.h"

#define MAX_ESSAIS 5

int main(void)
{
printf("*********************************\n");
printf("*        BIENVENUE AU           *\n");
printf("*          MASTERMIND           *\n");
printf("*********************************\n\n");


/* Initialisation du joueur */
Joueur utilisateur = initialiser_joueur();

/* Génération du code secret */
Combinaison secret = generer_combinaison_secrete();

int gagne = 0;

printf("\n=================================\n");
printf("              REGLES\n");
printf("=================================\n");
printf("Devinez une combinaison de 4 chiffres.\n");
printf("Chaque chiffre est compris entre 0 et 9.\n");
printf("Vous avez %d essais.\n", MAX_ESSAIS);
printf("=================================\n");

while (utilisateur.essais < MAX_ESSAIS && !gagne)
{
    printf("\n--- Essai %d / %d ---\n",
           utilisateur.essais + 1,
           MAX_ESSAIS);

    Combinaison proposition = saisir_tentative();

    Resultat res = comparer_combinaisons(secret, proposition);

    afficher_resultat(proposition, res);

    utilisateur.essais++;

    if (res.bien_places == TAILLE_CODE)
    {
        gagne = 1;
    }
}

printf("\n=================================\n");

if (gagne)
{
    printf("           VICTOIRE !\n");
    printf("=================================\n");
    printf("Bravo %s !\n", utilisateur.nom);
    printf("Tu as trouve la combinaison en %d essai%s.\n",
           utilisateur.essais,
           utilisateur.essais > 1 ? "s" : "");
}
else
{
    printf("           GAME OVER\n");
    printf("=================================\n");
    printf("Dommage %s !\n", utilisateur.nom);

    printf("La combinaison secrete etait : ");

    for (int i = 0; i < TAILLE_CODE; i++)
    {
        printf("%d", secret.valeurs[i]);
    }

    printf("\n");
}

printf("\nAppuyez sur Entree pour quitter...");
getchar();

return 0;

}
