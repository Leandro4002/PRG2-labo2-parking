/*
--------------------------------------------------------------------------------
Nom du fichier : parking.h
Auteur(s)      : Florian Conti, Léo Zmoos & Leandro Saraiva Maia
Date creation  : 24.05.2022

Description    : Ce module modèlise un parking de véhicules. Il définit une
                 permettant d'associer une taxe à un véhicule, cette structure
                 sera celle utilisé dans les fonctions de ce module.
                 Ce module permet d'effectuer diverses opérations sur le parking
                 en appelant d'autre module (taxes et statistique). C'est un
                 module qui sert d'interface entre les modules.

Compilateur    : Compilation fonctionnelle avec :
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
// Calcule les taxes annuelles des véhicules d'un parking.
// Cette fonction alloue de la mémoire pour le tableau de PlaceDeParking et
// retourne un pointeur vers ce tableau. Il faut donc penser à libérer la
// mémoire quand on n'en a plus besoin.
PlaceDeParking* calculerTaxesAnnuellesParking(Vehicule* parking,
   size_t nbPlace);

// On considère que le tableau de données est préalablement trié
// par ordre croissant ou décroissant, il y a un résultat indeterminé sinon.
const Stat calculerStatPlaceDePark(PlaceDeParking* parking,
   size_t nbPlace, bool (*estVehicule)(const Vehicule*));

// Fonction de comparaison binaire utilisée pour trier
// les places de parking par ordre décroissant.
int taxeAnnuelleDecroissant (const void* a, const void* b);

// Génère un tableau de nbPlace place de parking triées selon la fonction
// passée en paramètre. Cette fonction alloue de la mémoire pour le tableau
// et retourne un pointeur vers ce tableau. Il faut donc penser à libérer
// la mémoire quand on n'en a plus besoin.
PlaceDeParking* trierParking(PlaceDeParking* parking,
   size_t nbPlace, int (*comparer)(const void*, const void*));

// Affiche toutes les voitures du parking avec leur caractéristiques
void afficherParking(const PlaceDeParking* parking, size_t nbPlace);

// Affiche une voiture du parking avec ses caractéristiques
void afficherPlaceDeParking(const PlaceDeParking* placeDeParking);

#endif // PRG2_LABO_2_PARKING_H
