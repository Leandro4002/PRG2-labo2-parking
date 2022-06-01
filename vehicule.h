/*
--------------------------------------------------------------------------------
Nom du fichier : vehicule.h
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

#ifndef PRG2_LABO_2_VEHICULE_H
#define PRG2_LABO_2_VEHICULE_H

#include <inttypes.h> // Requis pour uint16_t
#include <stdbool.h>  // Requis pour bool

typedef uint16_t ui;

// Déclarations des types enum -------------------------------------------------
typedef enum { VOITURE, CAMIONETTE } TypeVehicule;
typedef enum { STANDARD, HAUT_DE_GAMME } TypeVoiture;

// Déclarations des tableaux de noms -------------------------------------------
static const char* TYPES_VEHICULE[] = { "Voiture", "Camionette" };
static const char* TYPES_VOITURE[] = { "Standard", "Haut de gamme" };

// Déclaration des unions et structures-----------------------------------------
// A côté de chaque structure il y a un commentaire indiquant la taille
// que va prendre la structure en mémoire.
// Cela dépend du compilateur mais les tailles indiqué sont les plus probables.

typedef struct { // 2 bytes
   ui puissanceDuMoteur; // Chevaux (CV)
} HautDeGamme;

typedef struct { // 4 bytes
   ui cylindree; // cm3
   ui quantiteRejetCO2; // g/km
} Standard;

typedef struct { // 12 bytes
   const TypeVoiture typeVoiture;
   union {
      HautDeGamme hautDeGamme;
      Standard    standard;
   };
   ui poids; // kg
} Voiture;

typedef struct { // 8 bytes
   double volumeTransport; // m3
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

// Déclaration des fonctions ---------------------------------------------------
Vehicule creerVoitureStandard(char* plaqueImmatriculation, const char* marque,
   ui poids, ui cylindree, ui quantiteRejetCO2);

Vehicule creerVoitureHautDeGamme(char* plaqueImmatriculation,
   const char* marque, ui poids, ui puissanceDuMoteur);

Vehicule creerCamionette(char* plaqueImmatriculation, const char* marque,
   double volumeTransport);

bool estVoitureStandard(const Vehicule* vehicule);

bool estVoitureHautDeGamme(const Vehicule* vehicule);

bool estCamionette(const Vehicule* vehicule);

#endif // PRG2_LABO_2_VEHICULE_H
