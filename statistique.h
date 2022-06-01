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

double somme(const double* donnee, size_t nbDonnee);

double moyenne(const double* donnee, size_t nbDonnee);

double mediane(const double* donnee, size_t nbDonnee);

double ecartType(const double* donnee, size_t nbDonnee);

void* trier(const void* donnee, size_t nbDonnee,
   int (*comparer)(const void*, const void*), size_t tailleElem);

#endif // PRG2_LABO_2_STAT_H
