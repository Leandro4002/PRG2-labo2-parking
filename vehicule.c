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
   assert(plaqueImmatriculation);
   assert(marque);
   assert(poids > 0);
   assert(cm3Cylindree > 0);
   // Pas d'assert pour quantiteRejetCO2 car il est possible d'avoir une voiture électrique par exemple

   return (Vehicule){
      .marque = marque,
      .plaqueImmatriculation = plaqueImmatriculation,
      .typeVehicule = VOITURE,
      .voiture = {
         .poids = poids,
         .typeVoiture = STANDARD,
         .standard = {
            .quantiteRejetCO2 = quantiteRejetCO2,
            .cm3Cylindree = cm3Cylindree
         }
      }
   };
}

Vehicule creerVoitureHautDeGamme(char* plaqueImmatriculation, const char* marque, ui16 poids, ui16 puissanceDuMoteur) {
   assert(plaqueImmatriculation);
   assert(marque);
   assert(poids > 0);
   assert(puissanceDuMoteur > 0);

   return (Vehicule){
      .marque = marque,
      .plaqueImmatriculation = plaqueImmatriculation,
      .typeVehicule = VOITURE,
      .voiture = {
         .poids = poids,
         .typeVoiture = HAUT_DE_GAMME,
         .hautDeGamme = {
            .puissanceDuMoteur = puissanceDuMoteur
         }
      }
   };
}

Vehicule creerCamionette(char* plaqueImmatriculation, const char* marque, double volumeTransport) {
   assert(plaqueImmatriculation);
   assert(marque);
   assert(volumeTransport >= 0);

   return (Vehicule){
      .marque = marque,
      .plaqueImmatriculation = plaqueImmatriculation,
      .typeVehicule = CAMIONETTE,
      .camionette = {
         .volumeTransport = volumeTransport
      }
   };
}

int estVoitureStandard(const Vehicule* vehicule) {
   assert(vehicule);

   return vehicule->typeVehicule == VOITURE && vehicule->voiture.typeVoiture == STANDARD;
}

int estVoitureHautDeGamme(const Vehicule* vehicule) {
   assert(vehicule);

   return vehicule->typeVehicule == VOITURE && vehicule->voiture.typeVoiture == HAUT_DE_GAMME;
}

int estCamionette(const Vehicule* vehicule) {
   assert(vehicule);

   return vehicule->typeVehicule == CAMIONETTE;
}
