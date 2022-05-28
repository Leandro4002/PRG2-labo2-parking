#include "vehicule.h"
#include <assert.h>
#include <stdio.h>

Vehicule voitureStandard(char* plaqueImmatriculation, char* marque, ui16 poids, ui16 cm3Cylindree, ui16 quantiteRejetCO2) {
   assert(plaqueImmatriculation != NULL && marque != NULL);

   return (Vehicule) {.marque = marque, .plaqueImmatriculation = plaqueImmatriculation, .typeVehicule = VOITURE,{.voiture ={.poids = poids,.typevoiture = STANDARD, {.standard = {.quantiteRejetCO2 = quantiteRejetCO2, .cm3Cylindree = cm3Cylindree}}}}};
}

Vehicule voitureHautDeGamme(char* plaqueImmatriculation, char* marque, ui16 poids, ui16 puissanceDuMoteur) {
   assert(plaqueImmatriculation != NULL && marque != NULL);

   return (Vehicule) {.marque = marque, .plaqueImmatriculation = plaqueImmatriculation, .typeVehicule = VOITURE, {.voiture = {.poids = poids, .typevoiture = HAUT_DE_GAMME, {.hautDeGamme = {.puissanceDuMoteur = puissanceDuMoteur}}}}};
}

Vehicule camionette(char* plaqueImmatriculation, char* marque, double volumeTransport) {
   assert(plaqueImmatriculation != NULL && marque != NULL);

   return (Vehicule) {.marque = marque, .plaqueImmatriculation = plaqueImmatriculation, .typeVehicule = CAMIONETTE, {.camionette = {.volumeTransport = volumeTransport}}};
}
