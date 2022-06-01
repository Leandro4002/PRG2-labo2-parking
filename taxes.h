/*
--------------------------------------------------------------------------------
Nom du fichier : taxes.h
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

#ifndef PRG2_LABO_2_TAXES_H
#define PRG2_LABO_2_TAXES_H

#include "vehicule.h"

// Constantes ------------------------------------------------------------------
// Taxes de base
static const double TAXE_BASE_VOITURE_CHF = 400.;
static const double TAXE_BASE_CAMIONETTE_CHF = 700.;

// Taxes spécifiques aux voitures standardes
static const double TAXE_POLLUTION_1 = 0.;   // cylindree en cm3
static const double TAXE_POLLUTION_2 = 50.;  // cylindree en cm3
static const double TAXE_POLLUTION_3 = 0.05; // cylindree en cm3

// Taxes spécifiques aux voitures haut de gamme
static const double TAXE_PUISSANCE_MOTEUR_CHF = 200.;       // puiss. en chevaux
static const double TAXE_HAUTE_PUISSANCE_MOTEUR_CHF = 300.; // puiss. en chevaux
static const double TAXE_PUISSANCE_POIDS_CHF = 20.;         // poids en tonnes

// Taxes spécifiques aux camionettes
static const double TAXE_CAMIONETTE_PAR_VOLUME_CHF = 10.; // volume m3

// Valeurs limites avant d'appliquer certaines taxes
// Puissance en chevaux
static const typePuissanceMoteur LIMITE_PUISSANCE_MOTEUR_TAXE = 250u;
// Cylindree en cm3
static const typeCylindree       LIMITE_CYLINDREE_TAXE = 1400u;
// Rejet de CO2 en g/km
static const typeRejetCO2        LIMITE_CO2_TAXE = 130u;

// Déclarations de fonctions ---------------------------------------------------
// Calcul le montant de la taxe annelle pour un véhicule donné
double calculerTaxeAnnuelle(const Vehicule* vehicule);

#endif // PRG2_LABO_2_TAXES_H
