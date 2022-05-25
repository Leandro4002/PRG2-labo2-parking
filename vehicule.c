//
// Created by florian on 24.05.2022.
//

#include "vehicule.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

Vehicule voitureStandard(char* plaqueImmatriculation, char* marque, ui16 poids, uint16_t cm3Cylindree, uint16_t quantiteRejetCO2){
   assert(plaqueImmatriculation != NULL && marque != NULL);

   return (Vehicule) {.marque = marque, .plaqueImmatriculation = plaqueImmatriculation, .typeVehicule = VOITURE,{.voiture ={.poids = poids,.typevoiture = STANDARD, {.standard = {.quantiteRejetCO2 = quantiteRejetCO2, .cm3Cylindree = cm3Cylindree}}}}};
}

Vehicule voitureHautDeGamme(char* plaqueImmatriculation, char* marque, ui16 poids, uint16_t puissanceDuMoteur){
   assert(plaqueImmatriculation != NULL && marque != NULL);

   return (Vehicule) {.marque = marque, .plaqueImmatriculation = plaqueImmatriculation, .typeVehicule = VOITURE, {.voiture = {.poids = poids, .typevoiture = HAUT_DE_GAMME, {.hautDeGamme = {.puissanceDuMoteur = puissanceDuMoteur}}}}};
}

Vehicule camionette(char* plaqueImmatriculation, char* marque, double volumeTransport){
   assert(plaqueImmatriculation != NULL && marque != NULL);

   return (Vehicule) {.marque = marque, .plaqueImmatriculation = plaqueImmatriculation, .typeVehicule = CAMIONETTE, {.camionette = {.volumeTransport = volumeTransport}}};
}

void afficherVehicule(const Vehicule *vehicule){
   assert(vehicule);

   printf("Marque : %s\n", vehicule->marque);
   printf("Plaque : %s\n", vehicule->plaqueImmatriculation);

   switch (vehicule->typeVehicule) {
      case VOITURE:

         printf("Poids [kg] : %" PRIu16 "\n", vehicule->specificiteVehicule.voiture.poids);

         switch (vehicule->specificiteVehicule.voiture.typevoiture) {
            case STANDARD:
               printf("Cylindree [cm3] : %" PRIu16 "\n", vehicule->specificiteVehicule.voiture.specificiteVoiture.standard.cm3Cylindree);
               printf("Rejet CO2 [g/km] : %" PRIu16 "\n", vehicule->specificiteVehicule.voiture.specificiteVoiture.standard.quantiteRejetCO2);
               break;

            case HAUT_DE_GAMME:
               printf("Puissance [CV] : %" PRIu16 "\n", vehicule->specificiteVehicule.voiture.specificiteVoiture.hautDeGamme.puissanceDuMoteur);
               break;
         }

         break;

      case CAMIONETTE:
         printf("Volume de transport : %f\n", vehicule->specificiteVehicule.camionette.volumeTransport);
         break;
   }
}