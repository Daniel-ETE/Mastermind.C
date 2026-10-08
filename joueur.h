#ifndef JOUEURS_H
#define JOUEURS_H

/*
 * Structure Joueur
 * Stocke les informations du joueur.
 */
typedef struct
{
    char nom[30];
    int essais;
} Joueur;


/*
 * Initialise le joueur.
 */
Joueur initialiser_joueur(void);

#endif

