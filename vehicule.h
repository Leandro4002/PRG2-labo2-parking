/*
-----------------------------------------------------------------------------------
Nom du fichier : vehicule.h
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

#ifndef PARKING_VEHICULE_H
#define PARKING_VEHICULE_H

#include <inttypes.h> // Requis pour uint16_t
#include <stdbool.h> // Requis pour bool

typedef uint16_t ui16;

// Déclarations des types enum ---------------------------------------------------------------------
typedef enum { VOITURE, CAMIONETTE } TypeVehicule;
typedef enum { STANDARD, HAUT_DE_GAMME } TypeVoiture;

// Déclarations des tableaux de noms ---------------------------------------------------------------
static const char* TYPES_VEHICULE[] = { "Voiture", "Camionette" };
static const char* TYPES_VOITURE[] = { "Standard", "Haut de gamme" };

// Déclaration des unions et structures-------------------------------------------------------------
// A côté de chaque structure il y a un commentaire indiquant la taille
// que va prendre la structure en mémoire.
// Cela peut dépendre du compilateur mais les tailles indiqué sont les plus probables.

typedef struct { // 2 bytes
   ui16 puissanceDuMoteur;
} HautDeGamme;

typedef struct { // 4 bytes
   ui16 cm3Cylindree;
   ui16 quantiteRejetCO2;
} Standard;

typedef struct { // 12 bytes
   const TypeVoiture typeVoiture;
   union {
      HautDeGamme hautDeGamme;
      Standard    standard;
   };
   ui16 poids;
} Voiture;

typedef struct { // 8 bytes
   double volumeTransport;
} Camionette;

typedef struct { // 36 bytes
   union {
      Voiture voiture;
      Camionette camionette;
   };
   const char* marque;
   const TypeVehicule typeVehicule;
   char* plaqueImmatriculation;
} Vehicule;

// Déclaration des fonctions --------------------------------------------------------------------
Vehicule creerVoitureStandard(char* plaqueImmatriculation, const char* marque, ui16 poids, ui16 cm3Cylindree, ui16 quantiteRejetCO2);

Vehicule creerVoitureHautDeGamme(char* plaqueImmatriculation, const char* marque, ui16 poids, ui16 puissanceDuMoteur);

Vehicule creerCamionette(char* plaqueImmatriculation, const char* marque, double volumeTransport);

int estVoitureStandard(const Vehicule* vehicule);

int estVoitureHautDeGamme(const Vehicule* vehicule);

int estCamionette(const Vehicule* vehicule);

#endif //PARKING_VEHICULE_H
