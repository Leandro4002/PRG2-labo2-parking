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

typedef struct {
   Vehicule* vehicule;
   double taxeAnnuelle;
} PlaceDeParking;

// la somme, la moyenne, la médiane et l'écart-type
typedef struct {
   double somme, mediane, moyenne, ecartType;
} StatTaxes;

PlaceDeParking* calculerTaxesAnnuellesParking(Vehicule* parking,
   size_t nbPlace);

const StatTaxes calculerStatPlaceDePark(PlaceDeParking* parking,
   size_t nbPlace, bool (*estVehicule)(const Vehicule *));

void trierParking(PlaceDeParking* parking, size_t nbPlace);

void afficherParking(const PlaceDeParking* parking, size_t nbPlace);

void afficherPlaceDeParking(const PlaceDeParking* placeDeParking);

void afficherStat(const char* nomStat, const StatTaxes* stat);

#endif // PRG2_LABO_2_PARKING_H
