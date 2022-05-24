//
// Created by florian on 24.05.2022.
//

#include "vehicule.h"
#include "assert.h"

Vehicule *voitureStandard(char* plaqueImmatriculation, char* marque, ui16 poids, uint16_t cm3Cylindree, uint16_t quantiteRejetCO2){
   assert(plaqueImmatriculation != NULL && marque != NULL);
   Vehicule *vehicule = &(Vehicule) {
      .marque = marque,
      .typeVehicule = VOITURE,
      .plaqueImmatriculation = plaqueImmatriculation,
      .unionVehicule = {
         .voiture = {
            .poids = poids,
            .typevoiture = STANDARD,
            .standard = {
               .cm3Cylindree = cm3Cylindree,
               .quantiteRejetCO2 = quantiteRejetCO2
            }
         }
      }
   };
   return vehicule;
}

Vehicule *voitureHautDeGamme(char* plaqueImmatriculation, char* marque, ui16 poids, uint16_t puissanceDuMoteur){
   assert(plaqueImmatriculation != NULL && marque != NULL);

   Vehicule *vehicule = &(Vehicule) {
      .marque = marque,
      .typeVehicule = VOITURE,
      .plaqueImmatriculation = plaqueImmatriculation,
      .unionVehicule = {
         .voiture = {
            .poids = poids,
            .typevoiture = HAUT_DE_GAMME,
            .hautDeGamme = {
               .puissanceDuMoteur = puissanceDuMoteur
            }
         }
      }
   };

   return vehicule;
}

Vehicule *camionette(char* plaqueImmatriculation, char* marque, double volumeTransport){
   assert(plaqueImmatriculation != NULL && marque != NULL);

   Vehicule *vehicule = &(Vehicule) {
      .marque = marque,
      .typeVehicule = CAMIONETTE,
      .plaqueImmatriculation = plaqueImmatriculation,
      .unionVehicule = {
         .camionette = {
            .volumeTransport = volumeTransport
         }
      }
   };
   return vehicule;
}
