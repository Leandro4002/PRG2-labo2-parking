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

#include <assert.h>  // requis pour assert
#include <math.h>    // requis pour sqrt
#include <string.h>  // requis pour memcpy
#include "statistique.h"

double somme(const double* donnee, size_t nbDonnee) {
   assert(donnee);

   if (!nbDonnee) return 0.;

   double total = 0.;

   for (size_t i = 0; i < nbDonnee; ++i) {
      total += donnee[i];
   }

   return total;
}

double moyenne(const double* donnee, size_t nbDonnee) {
   assert(donnee);

   if (!nbDonnee) return 0.;
   
   return somme(donnee, nbDonnee) / nbDonnee;
}

double mediane(const double* donnee, size_t nbDonnee) {
   assert(donnee);
   
   if (!nbDonnee) return 0.;

   return nbDonnee % 2 ? donnee[nbDonnee / 2] :
      (donnee[nbDonnee / 2] + donnee[nbDonnee / 2 + 1]) / 2;
}

double ecartType(const double* donnee, size_t nbDonnee) {
   assert(donnee);

   if (!nbDonnee) return 0.;

   double sommeDesCarree = 0.;

   for (size_t i = 0; i < nbDonnee; ++i) {
      sommeDesCarree += donnee[i] * donnee[i];
   }

   double moy = moyenne(donnee, nbDonnee);

   // La variance est égale à la différence entre la moyenne des carrés
   // et le carré de la moyenne
   // L'écart type est égale à la racine carré de la variance
   return sqrt(sommeDesCarree / nbDonnee - moy * moy);
}

void* trier(const void* donnee, size_t nbDonnee,
   int (*comparer)(const void*, const void*), size_t tailleElem) {
   assert(donnee);
   assert(comparer);
   assert(tailleElem > 0);

   if (!nbDonnee) return NULL;

   // On crée un nouveau tableau pour les données triées
   void* donneeTrie = calloc(nbDonnee, tailleElem);

   if (!donneeTrie) return NULL;

   // On copie les données dans le tableau de données triées
   memcpy(donneeTrie, donnee, nbDonnee * tailleElem);

   // On trie le tableau de données triées
   qsort(donneeTrie, nbDonnee, tailleElem, comparer);

   return donneeTrie;
}

void afficherStat(const char* texteStat, const Stat* stat) {
   printf("%s\n", texteStat);
   printf("\tTotal      : %.2f\n", stat->somme);
   printf("\tMoyenne    : %.2f\n", stat->moyenne);
   printf("\tMediane    : %.2f\n", stat->mediane);
   printf("\tEcart-type : %.2f\n", stat->ecartType);
}
