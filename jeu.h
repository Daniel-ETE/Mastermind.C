#ifndef JEU_H
#define JEU_H

#define TAILLE_CODE 4

/*
 * Structure Combinaison
 * Représente le code secret ou une tentative du joueur.
 */
typedef struct
{
    int valeurs[TAILLE_CODE];
} Combinaison;


/*
 * Structure Resultat
 *
 * statut[i] :
 * 0 = chiffre incorrect
 * 1 = chiffre bien placé
 * 2 = chiffre correct mais mal placé
 */
typedef struct
{
    int bien_places;
    int mal_places;
    int statut[TAILLE_CODE];

} Resultat;


/*
 * Génère le code secret.
 */
Combinaison generer_combinaison_secrete(void);


/*
 * Demande au joueur de saisir une tentative.
 */
Combinaison saisir_tentative(void);


/*
 * Compare la tentative avec le code secret.
 */
Resultat comparer_combinaisons(Combinaison secrete,
                               Combinaison tentative);

#endif

