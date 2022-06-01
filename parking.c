/*
--------------------------------------------------------------------------------
Nom du fichier : parking.c
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

#include <stdio.h>   // Requis pour printf
#include <string.h>  // Requis pour strlen
#include <assert.h>  // Requis pour assert
#include "parking.h"
#include "taxes.h"
#include "statistique.h"

PlaceDeParking* calculerTaxesAnnuellesParking(Vehicule* vehicule,
   size_t nbPlace) {
   assert(vehicule);
   assert(nbPlace > 0);

   PlaceDeParking* parking =
      (PlaceDeParking*)calloc(nbPlace, sizeof(PlaceDeParking));
   
   if (!parking) return NULL;

   for (size_t i = 0; i < nbPlace; ++i) {
      parking[i].vehicule = vehicule + i;
      parking[i].taxeAnnuelle = calculerTaxeAnnuelle(vehicule + i);
   }

   return parking;
}

const StatTaxes calculerStatPlaceDePark(PlaceDeParking* parking,
   size_t nbPlace, bool (*estVehicule)(const Vehicule*)) {
   assert(parking);
   assert(estVehicule);

   StatTaxes stat = {};

   // Extrait les taxes des véhicules filtrés par la fonction passé
   // en paramètre dans un tableau de double
   double taxes[nbPlace];
   size_t nbVehiculeFiltree = 0;

   for (size_t i = 0; i < nbPlace; ++i) {
      if (estVehicule(parking[i].vehicule)) {
         taxes[nbVehiculeFiltree++] = parking[i].taxeAnnuelle;
      }
   }

   stat.somme = somme(taxes, nbVehiculeFiltree);
   stat.moyenne = moyenne(taxes, nbVehiculeFiltree);
   stat.ecartType = ecartType(taxes, nbVehiculeFiltree);

   // Attention, ici la médiane peut être calculé uniquement si le parking passé
   // en paramètre a été préalablement trié par ordre croissant ou décroissant
   stat.mediane = mediane(taxes, nbVehiculeFiltree);
   
   return stat;
}

int taxeAnnuelleDecroissant (const void* a, const void* b) {
   const PlaceDeParking* placeA = (const PlaceDeParking*)a;
   const PlaceDeParking* placeB = (const PlaceDeParking*)b;

   return placeA->taxeAnnuelle > placeB->taxeAnnuelle ? -1 :
      placeA->taxeAnnuelle < placeB->taxeAnnuelle ? 1 : 0;
}

PlaceDeParking* trierParking(PlaceDeParking* parking,
   size_t nbPlace, int (*comparer)(const void*, const void*)) {
   assert(parking);
   
   if (!nbPlace) return NULL;

   return (PlaceDeParking*)trier((void*)parking, nbPlace,
      comparer, sizeof(PlaceDeParking));
}

void afficherParking(const PlaceDeParking* parking, size_t nbPlace) {
   assert(parking);

   const char* TITRE = "*  Affichage du parking  *";
   const unsigned TAILLE_TITRE = (unsigned)strlen(TITRE);

   for (unsigned i = TAILLE_TITRE; i--; putchar('*'));
   printf("\n%s\n", TITRE);
   for (unsigned i = TAILLE_TITRE; i--; putchar('*'));
   printf("\n\n");

   for (size_t i = 0; i < nbPlace; ++i) {
      assert(&parking[i]);
      assert(parking[i].vehicule);

      afficherPlaceDeParking(&parking[i]);

      printf("\n--------------------------------\n\n");
   }
}

// Utilisation de macro afin d'améliorer la lisibilité du code
#define VOIT_ALIAS placeDeParking->vehicule->voiture
#define VOIT_STANDARD_ALIAS VOIT_ALIAS.standard
#define VOIT_HAUT_DE_GAMME_ALIAS VOIT_ALIAS.hautDeGamme
#define CAMIONETTE_ALIAS placeDeParking->vehicule->camionette

void afficherPlaceDeParking(const PlaceDeParking* placeDeParking) {
   assert(placeDeParking);

   printf("Type                     : %s\n",
      TYPES_VEHICULE[placeDeParking->vehicule->typeVehicule]);
   printf("Marque                   : %s\n",
      placeDeParking->vehicule->marque);
   printf("Plaque                   : %s\n",
      placeDeParking->vehicule->plaqueImmatriculation);

   switch (placeDeParking->vehicule->typeVehicule) {
      case VOITURE:

         printf("Categorie voiture        : %s\n",
            TYPES_VOITURE[VOIT_ALIAS.typeVoiture]);
         printf("Poids [kg]               : %" PRIu16 "\n", VOIT_ALIAS.poids);

         switch (VOIT_ALIAS.typeVoiture) {
            case STANDARD:
               printf("Cylindree [cm3]          : %" PRIu16 "\n",
                  VOIT_STANDARD_ALIAS.cylindree);
               printf("Rejet CO2 [g/km]         : %" PRIu16 "\n",
                  VOIT_STANDARD_ALIAS.quantiteRejetCO2);
               break;

            case HAUT_DE_GAMME:
               printf("Puissance moteur [CV]    : %" PRIu16 "\n",
                  VOIT_HAUT_DE_GAMME_ALIAS.puissanceDuMoteur);
               break;
            default: break;
         }
         break;

      case CAMIONETTE:
         printf("Volume de transport [m3] : %.2f\n",
            CAMIONETTE_ALIAS.volumeTransport);
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
