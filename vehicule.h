//
// Created by florian on 24.05.2022.
//

#ifndef PARKING_VEHICULE_H
#define PARKING_VEHICULE_H

#include <inttypes.h>

typedef uint16_t ui16;

// Déclarations des types enum ---------------------------------------------------------------------
typedef enum { VOITURE, CAMIONETTE } TypeVehicule;
typedef enum { STANDARD, HAUT_DE_GAMME } TypeVoiture;

// Déclarations des tableaux de noms ---------------------------------------------------------------
static const char* TYPES_VEHICULE[] = {"Voiture", "Camionette"};
static const char* TYPES_VOITURE[] = {"Standard", "Haut de gamme"};

// Déclaration des unions et structures-------------------------------------------------------------
typedef struct {
   uint16_t puissanceDuMoteur;
} HautDeGamme;

typedef struct {
   uint16_t cm3Cylindree;
   uint16_t quantiteRejetCO2;
} Standard;

typedef union {
   HautDeGamme hautDeGamme;
   Standard    standard;
} SpecificiteVoiture;

typedef struct{
   ui16 poids;
   TypeVoiture typevoiture;
   SpecificiteVoiture specificiteVoiture;

} Voiture;

typedef struct{

   double volumeTransport;

} Camionette;

typedef union {
   Camionette camionette;
   Voiture voiture;
} SpecificiteVehicule;

typedef struct {

   const char* marque;
   char* plaqueImmatriculation;
   TypeVehicule typeVehicule;
   SpecificiteVehicule specificiteVehicule;

} Vehicule;

// Initialisation des fonctions --------------------------------------------------------------------
Vehicule voitureStandard(char* plaqueImmatriculation, char* marque, ui16 poids, uint16_t cm3Cylindree, uint16_t quantiteRejetCO2);

Vehicule voitureHautDeGamme(char* plaqueImmatriculation, char* marque, ui16 poids, uint16_t puissanceDuMoteur);

Vehicule camionette(char* plaqueImmatriculation, char* marque, double volumeTransport);

void afficherVehicule(const Vehicule *vehicule);

#endif //PARKING_VEHICULE_H
