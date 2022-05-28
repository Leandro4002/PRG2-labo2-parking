#ifndef PARKING_PARKING_H
#define PARKING_PARKING_H

#include <stdlib.h>
#include "vehicule.h"

typedef struct {
	Vehicule vehicule;
	double taxeAnnuelle;
} PlaceDeParking;

// la somme, la moyenne, la médiane et l'écart-type
typedef struct {
	double somme, mediane, moyenne, ecartType;
} StatTaxes;

void calculerTaxesAnnuellesParking(PlaceDeParking *parking, const size_t nbPlace);

const StatTaxes calculerStatPlaceDePark(PlaceDeParking *parking, const size_t nbPlace, const int (*estVehicule)(const Vehicule *));

void trierParking(PlaceDeParking *parking, const size_t nbPlace);

void afficherParking(const PlaceDeParking *parking, const size_t nbPlace);

void afficherPlaceDeParking(const PlaceDeParking* placeDeParking);

void afficherStat(const char* nomStat, const StatTaxes* stat);

#endif //PARKING_PARKING_H
