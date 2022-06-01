/*
--------------------------------------------------------------------------------
Nom du fichier : vehicule.c
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

#include <assert.h>   // Requis pour assert
#include "vehicule.h"

Vehicule creerVoitureStandard(char* plaqueImmatriculation, const char* marque,
   typePoids poids, typeCylindree cylindree, typeRejetCO2 quantiteRejetCO2) {
   assert(plaqueImmatriculation);
   assert(marque);
   assert(poids > 0);
   assert(cylindree > 0);
   // Pas d'assert pour quantiteRejetCO2 car il est possible d'avoir
   // une voiture électrique qui ne rejette pas de CO2 par exemple.

   return (Vehicule){
      .marque = marque,
      .plaqueImmatriculation = plaqueImmatriculation,
      .typeVehicule = VOITURE,
      .voiture = (Voiture){
         .poids = poids,
         .typeVoiture = STANDARD,
         .standard = (Standard){
            .quantiteRejetCO2 = quantiteRejetCO2,
            .cylindree = cylindree
         }
      }
   };
}

Vehicule creerVoitureHautDeGamme(char* plaqueImmatriculation,
   const char* marque, typePoids poids, typePuissanceMoteur puissanceDuMoteur) {
   assert(plaqueImmatriculation);
   assert(marque);
   assert(poids > 0);
   assert(puissanceDuMoteur > 0);

   return (Vehicule){
      .marque = marque,
      .plaqueImmatriculation = plaqueImmatriculation,
      .typeVehicule = VOITURE,
      .voiture = (Voiture){
         .poids = poids,
         .typeVoiture = HAUT_DE_GAMME,
         .hautDeGamme = (HautDeGamme){
            .puissanceDuMoteur = puissanceDuMoteur
         }
      }
   };
}

Vehicule creerCamionette(char* plaqueImmatriculation, const char* marque,
   typeVolume volumeTransport) {
   assert(plaqueImmatriculation);
   assert(marque);
   assert(volumeTransport >= 0);

   return (Vehicule){
      .marque = marque,
      .plaqueImmatriculation = plaqueImmatriculation,
      .typeVehicule = CAMIONETTE,
      .camionette = (Camionette){
         .volumeTransport = volumeTransport
      }
   };
}

bool estVoitureStandard(const Vehicule* vehicule) {
   assert(vehicule);

   return vehicule->typeVehicule == VOITURE
      && vehicule->voiture.typeVoiture == STANDARD;
}

bool estVoitureHautDeGamme(const Vehicule* vehicule) {
   assert(vehicule);

   return vehicule->typeVehicule == VOITURE
      && vehicule->voiture.typeVoiture == HAUT_DE_GAMME;
}

bool estCamionette(const Vehicule* vehicule) {
   assert(vehicule);

   return vehicule->typeVehicule == CAMIONETTE;
}
