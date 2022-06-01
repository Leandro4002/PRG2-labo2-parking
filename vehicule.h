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

// Alias de type ---------------------------------------------------------------
typedef uint16_t typePuissanceMoteur;
typedef uint16_t typeCylindree;
typedef uint16_t typeRejetCO2;
typedef uint16_t typePoids;
typedef double typeVolume;

// Déclarations des types enum -------------------------------------------------
typedef enum { VOITURE, CAMIONETTE } TypeVehicule;
typedef enum { STANDARD, HAUT_DE_GAMME } TypeVoiture;

// Déclarations des tableaux de noms -------------------------------------------
static const char* TYPES_VEHICULE[] = { "Voiture", "Camionette" };
static const char* TYPES_VOITURE[] = { "Standard", "Haut de gamme" };

// Déclaration des unions et structures-----------------------------------------
typedef struct {
   typePuissanceMoteur puissanceDuMoteur; // Chevaux (CV)
} HautDeGamme;

typedef struct {
   typeCylindree cylindree; // cm3
   typeRejetCO2 quantiteRejetCO2; // g/km
} Standard;

typedef struct {
   const TypeVoiture typeVoiture;
   union {
      HautDeGamme hautDeGamme;
      Standard    standard;
   };
   typePoids poids; // kg
} Voiture;

typedef struct {
   typeVolume volumeTransport; // m3
} Camionette;

typedef struct {
   const char* marque;
   char* plaqueImmatriculation;
   union {
      Voiture voiture;
      Camionette camionette;
   };
   const TypeVehicule typeVehicule;
} Vehicule;

// Déclaration des fonctions ---------------------------------------------------
// Constructeur pour voiture standard
Vehicule creerVoitureStandard(char* plaqueImmatriculation, const char* marque,
   typePoids poids, typeCylindree cylindree, typeRejetCO2 quantiteRejetCO2);

// Constructeur pour voiture haut de gamme
Vehicule creerVoitureHautDeGamme(char* plaqueImmatriculation,
   const char* marque, typePoids poids, typePuissanceMoteur puissanceDuMoteur);

// Constructeur pour camionette
Vehicule creerCamionette(char* plaqueImmatriculation, const char* marque,
   typeVolume volumeTransport);

// Détermine si le véhicule passé en paramètre est une voiture standard
bool estVoitureStandard(const Vehicule* vehicule);

// Détermine si le véhicule passé en paramètre est une voiture haut de gamme
bool estVoitureHautDeGamme(const Vehicule* vehicule);

// Détermine si le véhicule passé en paramètre est une camionette
bool estCamionette(const Vehicule* vehicule);

#endif // PRG2_LABO_2_VEHICULE_H
