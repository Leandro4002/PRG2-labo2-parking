/*
-----------------------------------------------------------------------------------
Nom du fichier : vehicule.c
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

#include <stdio.h>    // Requis pour la macro NULL
#include <assert.h>   // Requis pour assert
#include "vehicule.h"

Vehicule creerVoitureStandard(char* plaqueImmatriculation, const char* marque, ui16 poids, ui16 cm3Cylindree, ui16 quantiteRejetCO2) {
   assert(plaqueImmatriculation != NULL && marque != NULL);

   return (Vehicule){
      .marque = marque,
      .plaqueImmatriculation = plaqueImmatriculation,
      .typeVehicule = VOITURE,
      .specificiteVehicule = {
         .voiture = {
            .poids = poids,
            .typeVoiture = STANDARD,
            .specificiteVoiture = {
               .standard = {
                  .quantiteRejetCO2 = quantiteRejetCO2,
                  .cm3Cylindree = cm3Cylindree
               }
            }
         }
      }
   };
}

Vehicule creerVoitureHautDeGamme(char* plaqueImmatriculation, const char* marque, ui16 poids, ui16 puissanceDuMoteur) {
   assert(plaqueImmatriculation != NULL && marque != NULL);

   return (Vehicule){
      .marque = marque,
      .plaqueImmatriculation = plaqueImmatriculation,
      .typeVehicule = VOITURE,
      .specificiteVehicule = {
         .voiture = {
            .poids = poids,
            .typeVoiture = HAUT_DE_GAMME,
            .specificiteVoiture = {
               .hautDeGamme = {
                  .puissanceDuMoteur = puissanceDuMoteur
               }
            }
         }
      }
   };
}

Vehicule creerCamionette(char* plaqueImmatriculation, const char* marque, double volumeTransport) {
   assert(plaqueImmatriculation != NULL && marque != NULL);

   return (Vehicule){
      .marque = marque,
      .plaqueImmatriculation = plaqueImmatriculation,
      .typeVehicule = CAMIONETTE,
      .specificiteVehicule = {
         .camionette = {
            .volumeTransport = volumeTransport
         }
      }
   };
}

int estVoitureStandard(const Vehicule* vehicule) {
   assert(vehicule);

   return vehicule->typeVehicule == VOITURE && vehicule->specificiteVehicule.voiture.typeVoiture == STANDARD;
}

int estVoitureHautDeGamme(const Vehicule* vehicule) {
   assert(vehicule);

   return vehicule->typeVehicule == VOITURE && vehicule->specificiteVehicule.voiture.typeVoiture == HAUT_DE_GAMME;
}

int estCamionette(const Vehicule* vehicule) {
   assert(vehicule);

   return vehicule->typeVehicule == CAMIONETTE;
}
