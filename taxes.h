#ifndef PARKING_TAXES_H
#define PARKING_TAXES_H

#include "vehicule.h"

// Constantes --------------------------------------------------------------------------------------
// Taxes de base
const ui16   TAXE_BASE_VOITURE_CHF;
const ui16   TAXE_BASE_CAMIONETTE_CHF;

// Taxes spécifiques aux voitures standardes
const ui16   TAXE_POLLUTION_1; // cylindree en cm3
const ui16   TAXE_POLLUTION_2; // cylindree en cm3
const double TAXE_POLLUTION_3; // cylindree en cm3

// Taxes spécifiques aux voitures haut de gamme
const ui16   TAXE_PUISSANCE_MOTEUR_CHF; // puissance en chevaux
const ui16   TAXE_HAUTE_PUISSANCE_MOTEUR_CHF; // puissance en chevaux
const ui16   TAXE_PUISSANCE_POIDS_CHF; // poids en tonnes

// Taxes spécifiques aux camionettes
const ui16   TAXE_CAMIONETTE_PAR_VOLUME_CHF; // volume m3

// Valeurs limites avant d'appliquer certaines taxes
const ui16   LIMITE_PUISSANCE_MOTEUR_TAXE; // puissance en chevaux
const ui16   LIMITE_CYLINDREE_TAXE; // cylindree en cm3
const ui16   LIMITE_CO2_TAXE; // Rejet de CO2 en g/km

// Déclarations de fonctions ------------------------------------------------------------------------
ui16 calculerTaxeAnnuelle(const Vehicule* vehicule);
#endif //PARKING_TAXES_H
