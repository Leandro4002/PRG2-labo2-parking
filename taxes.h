/*
-----------------------------------------------------------------------------------
Nom du fichier : taxes.h
Auteur(s)      : Florian conti, Léo Zmoos & Leandro Saraiva Maia
Date creation  : 24.05.2022

Description    : 

Remarque(s)    : Les limites du programme sont :
                  - 

Compilateur    : Compilation fonctionnelle avec :
                  - Mingw-w64 gcc 11.2.0
                  - gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
-----------------------------------------------------------------------------------
*/

#ifndef PARKING_TAXES_H
#define PARKING_TAXES_H

#include "vehicule.h"

// Constantes --------------------------------------------------------------------------------------
// Taxes de base
static const double TAXE_BASE_VOITURE_CHF = 400.;
static const double TAXE_BASE_CAMIONETTE_CHF = 700.;

// Taxes spécifiques aux voitures standardes
static const double TAXE_POLLUTION_1 = 0.;   // cylindree en cm3
static const double TAXE_POLLUTION_2 = 50.;  // cylindree en cm3
static const double TAXE_POLLUTION_3 = 0.05; // cylindree en cm3

// Taxes spécifiques aux voitures haut de gamme
static const double TAXE_PUISSANCE_MOTEUR_CHF = 200.;       // puissance en chevaux
static const double TAXE_HAUTE_PUISSANCE_MOTEUR_CHF = 300.; // puissance en chevaux
static const double TAXE_PUISSANCE_POIDS_CHF = 20.;         // poids en tonnes

// Taxes spécifiques aux camionettes
static const double TAXE_CAMIONETTE_PAR_VOLUME_CHF = 10.; // volume m3

// Valeurs limites avant d'appliquer certaines taxes
static const ui16   LIMITE_PUISSANCE_MOTEUR_TAXE = 250u; // puissance en chevaux
static const ui16   LIMITE_CYLINDREE_TAXE = 1400u;       // cylindree en cm3
static const ui16   LIMITE_CO2_TAXE = 130u;              // Rejet de CO2 en g/km

// Déclarations de fonctions ------------------------------------------------------------------------
double calculerTaxeAnnuelle(const Vehicule* vehicule);
#endif //PARKING_TAXES_H
