/*
-----------------------------------------------------------------------------------
Nom du fichier : parking.c
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

#include <stdio.h>   // Requis pour printf
#include <string.h>  // Requis pour strlen
#include <assert.h>  // Requis pour assert
#include <math.h>    // Requis pour sqrt
#include "parking.h"
#include "taxes.h"

void calculerTaxesAnnuellesParking(PlaceDeParking *parking, const size_t nbPlace) {
   assert(parking);
   
   for (size_t i = 0; i < nbPlace; ++i) {
      assert(&parking[i]);
      assert(&parking[i].vehicule);

      parking[i].taxeAnnuelle = calculerTaxeAnnuelle(&parking[i].vehicule);
   }
}

const StatTaxes calculerStatPlaceDePark(PlaceDeParking *parking, const size_t nbPlace, const int (*estVehicule)(const Vehicule *)) {
   StatTaxes stat = {};
   double sommeDesCarres = 0.;

   // Tableau contenant les index des places de parking qui ont les véhicules qui ont le bon type
   size_t* indexPlaceFiltree = (size_t*)calloc(nbPlace, sizeof(size_t));
   size_t nbPlaceFiltree = 0; // Nombre de places de park filtré selon la fonction estVehicule
   
   for (size_t i = 0; i < nbPlace; ++i) {
      assert(&parking[i]);
      assert(&parking[i].vehicule);
      if (estVehicule(&parking[i].vehicule)) {
         indexPlaceFiltree[nbPlaceFiltree++] = i;

         stat.somme += parking[i].taxeAnnuelle;
         sommeDesCarres += parking[i].taxeAnnuelle * parking[i].taxeAnnuelle;
      }
   }

   if (nbPlaceFiltree > 0u) {
      if (nbPlaceFiltree % 2u) {
         stat.mediane = parking[indexPlaceFiltree[nbPlaceFiltree / 2u]].taxeAnnuelle;
      } else {
         stat.mediane = (parking[indexPlaceFiltree[nbPlaceFiltree / 2u]].taxeAnnuelle + parking[indexPlaceFiltree[nbPlaceFiltree / 2u + 1]].taxeAnnuelle) / 2.;
      }
   }
   free(indexPlaceFiltree);

   stat.moyenne = nbPlaceFiltree > 0u ? stat.somme / (double)nbPlaceFiltree : 0.;

   // La variance est égale à la différence entre la moyenne des carrés et le carré de la moyenne
   // L'écart type est égale à la racine carré de la variance
   stat.ecartType = nbPlaceFiltree > 0u ? sqrt(sommeDesCarres / (double)nbPlaceFiltree - stat.moyenne * stat.moyenne) : 0;

   return stat;
}

int taxeAnnuelleDecroissant (const void* a, const void* b) {
   const PlaceDeParking* placeA = (const PlaceDeParking*)a;
   const PlaceDeParking* placeB = (const PlaceDeParking*)b;
   
   return placeB->taxeAnnuelle - placeA->taxeAnnuelle;
}

void trierParking(PlaceDeParking *parking, const size_t nbPlace) {
   assert(parking);

   qsort(parking, nbPlace, sizeof(PlaceDeParking), taxeAnnuelleDecroissant);
}

void afficherParking(const PlaceDeParking *parking, const size_t nbPlace) {
   assert(parking);

   const char *TITRE = "*  Affichage du parking  *";
   const unsigned TAILLE_TITRE = (unsigned)strlen(TITRE);

   for (unsigned i = TAILLE_TITRE; i--; putchar('*'));
   printf("\n%s\n", TITRE);
   for (unsigned i = TAILLE_TITRE; i--; putchar('*'));
   printf("\n\n");

   for (size_t i = 0; i < nbPlace; ++i) {
      assert(&parking[i]);
      assert(&parking[i].vehicule);

      afficherPlaceDeParking(&parking[i]);

      printf("\n--------------------------------\n\n");
   }
}

// Utilisation de macro afin d'améliorer la lisibilité du code
#define VOIT_ALIAS placeDeParking->vehicule.specificiteVehicule.voiture
#define VOIT_STANDARD_ALIAS VOIT_ALIAS.specificiteVoiture.standard
#define VOIT_HAUT_DE_GAMME_ALIAS VOIT_ALIAS.specificiteVoiture.hautDeGamme
#define CAMIONETTE_ALIAS placeDeParking->vehicule.specificiteVehicule.camionette

void afficherPlaceDeParking(const PlaceDeParking* placeDeParking) {
   assert(placeDeParking);

   printf("Type                     : %s\n", TYPES_VEHICULE[placeDeParking->vehicule.typeVehicule]);
   printf("Marque                   : %s\n", placeDeParking->vehicule.marque);
   printf("Plaque                   : %s\n", placeDeParking->vehicule.plaqueImmatriculation);

   switch (placeDeParking->vehicule.typeVehicule) {
      case VOITURE:

         printf("Categorie voiture        : %s\n", TYPES_VOITURE[VOIT_ALIAS.typeVoiture]);
         printf("Poids [kg]               : %" PRIu16 "\n", VOIT_ALIAS.poids);

         switch (VOIT_ALIAS.typeVoiture) {
            case STANDARD:
               printf("Cylindree [cm3]          : %" PRIu16 "\n", VOIT_STANDARD_ALIAS.cm3Cylindree);
               printf("Rejet CO2 [g/km]         : %" PRIu16 "\n", VOIT_STANDARD_ALIAS.quantiteRejetCO2);
               break;

            case HAUT_DE_GAMME:
               printf("Puissance moteur [CV]    : %" PRIu16 "\n", VOIT_HAUT_DE_GAMME_ALIAS.puissanceDuMoteur);
               break;
            default: break;
         }
         break;

      case CAMIONETTE:
         printf("Volume de transport [m3] : %.2f\n", CAMIONETTE_ALIAS.volumeTransport);
         break;

      default: break;
   }

   printf("Taxe annuelle [CHF]      : %.2f\n", placeDeParking->taxeAnnuelle);
}

// Nettoyage des defines
#undef VOIT_ALIAS
#undef VOIT_STANDARD_ALIAS
#undef VOIT_HAUT_DE_GAMME_ALIAS
#undef CAMIONETTE_ALIAS

void afficherStat(const char* nomStat, const StatTaxes* stat) {
   printf("%s\n", nomStat);
   printf("\tTotal      : %.2f\n", stat->somme);
   printf("\tMoyenne    : %.2f\n", stat->moyenne);
   printf("\tMediane    : %.2f\n", stat->mediane);
   printf("\tEcart-type : %.2f\n", stat->ecartType);
}
