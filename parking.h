/*
--------------------------------------------------------------------------------
Nom du fichier : parking.h
Auteur(s)      : Florian Conti, Léo Zmoos & Leandro Saraiva Maia
Date creation  : 24.05.2022

Description    : 

Remarque(s)    : Les limites du programme sont :
                  - 

Compilateur    : Compilation fonctionnelle avec :
                  - Mingw-w64 gcc 11.2.0
                  - gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
--------------------------------------------------------------------------------
*/

#ifndef PRG2_LABO_2_PARKING_H
#define PRG2_LABO_2_PARKING_H

#include <stdlib.h>  // Requis pour size_t
#include <stdbool.h> // Requis pour bool
#include "vehicule.h"
#include "statistique.h"

// Structure permettant d'associer une taxe à chaque véhicule
typedef struct {
   Vehicule* vehicule;
   double taxeAnnuelle;
} PlaceDeParking;

// Déclarations de fonctions ---------------------------------------------------
// Fonction qui calcule les taxes annuelles des véhicules d'un parking
PlaceDeParking* calculerTaxesAnnuellesParking(Vehicule* parking,
   size_t nbPlace);

// On considère que le tableau de données est préalablement trié
// par ordre croissant ou décroissant, il y a un résultat indeterminé sinon.
const Stat calculerStatPlaceDePark(PlaceDeParking* parking,
   size_t nbPlace, bool (*estVehicule)(const Vehicule*));

// Fonction de comparaison binaire utilisée pour trier
// les places de parking par ordre
int taxeAnnuelleDecroissant (const void* a, const void* b);

// Génère un tableau de nbPlace place de parking triées selon la fonction
// passée en paramètre
PlaceDeParking* trierParking(PlaceDeParking* parking,
   size_t nbPlace, int (*comparer)(const void*, const void*));

// Affiche toutes les voitures du parking avec leur caractéristiques
void afficherParking(const PlaceDeParking* parking, size_t nbPlace);

// Affiche une voiture du parking avec ses caractéristiques
void afficherPlaceDeParking(const PlaceDeParking* placeDeParking);

#endif // PRG2_LABO_2_PARKING_H
