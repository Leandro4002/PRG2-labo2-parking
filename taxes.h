//
// Created by florian on 24.05.2022.
//

#ifndef PARKING_TAXES_H
#define PARKING_TAXES_H

#include "vehicule.h"

// Constantes
const ui16 TAXE_BASE_VOITURE_CHF = 400;
const ui16 TAXE_BASE_CAMIONETTE_CHF = 700;
const ui16 TAXE_CAMIONETTE_PAR_VOLUME_CHF = 10; // volume m3
const ui16 TAXE_PUISSANCE_MOTEUR_CHF = 200; // en chevaux
const ui16 TAXE_POIDS_CHF = 20; // en tonnes
const ui16 TAXE_CYLINDREE_1 = 0; // en cm3
const ui16 TAXE_CYLINDREE_2 = 50; // en cm3
const double TAXE_CYLINDREE_3 = 0.05; // en cm3

#endif //PARKING_TAXES_H
