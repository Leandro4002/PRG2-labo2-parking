/*
--------------------------------------------------------------------------------
Nom du fichier : statistique.c
Auteur(s)      : Florian Conti, Léo Zmoos & Leandro Saraiva Maia
Date creation  : 01.06.2022

Description    : 

Remarque(s)    : Les limites du programme sont :
                  - 

Compilateur    : Compilation fonctionnelle avec :
                  - Mingw-w64 gcc 11.2.0
                  - gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
--------------------------------------------------------------------------------
*/

#ifndef PRG2_LABO_2_STAT_H
#define PRG2_LABO_2_STAT_H

#include <stdlib.h> // requis pour size_t

// Structure permettant de stocker les informations statistiques
typedef struct {
   double somme, mediane, moyenne, ecartType;
} Stat;

// Déclarations de fonctions ---------------------------------------------------
// Addition de tous les éléments d'un tableau de données
double somme(const double* donnee, size_t nbDonnee);

// Calcul de la moyenne de tous les éléments d'un tableau de données
double moyenne(const double* donnee, size_t nbDonnee);

// On part du principe que le tableau de données est préalablement trié
// par ordre croissant ou décroissant
double mediane(const double* donnee, size_t nbDonnee);

// Calcul de l'écart-type de tous les éléments d'un tableau de données
double ecartType(const double* donnee, size_t nbDonnee);

// Fonction permettant de trier un tableau de données selon un ordre
// défini par l'utilisateur
void* trier(const void* donnee, size_t nbDonnee,
   int (*comparer)(const void*, const void*), size_t tailleElem);

// Affiche proprement les données statistiques
void afficherStat(const char* texteStat, const Stat* stat);

#endif // PRG2_LABO_2_STAT_H
