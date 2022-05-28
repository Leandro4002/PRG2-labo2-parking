#ifndef PARKING_PARKING_H
#define PARKING_PARKING_H

#include <stdlib.h>
#include "vehicule.h"

typedef struct {
	Vehicule vehicule;
	ui16 taxeAnnuelle;
} PlaceDeParking;

void calculerTaxesAnnuellesParking(PlaceDeParking *parking, const size_t nbVehicule);

void trierParking(PlaceDeParking *parking, const size_t nbVehicule);

void afficherParking(const PlaceDeParking *parking, const size_t nbVehicule);

void afficherPlaceDeParking(const PlaceDeParking* placeDeParking);

#endif //PARKING_PARKING_H
