#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "parking.h"
#include "taxes.h"

void calculerTaxesAnnuellesParking(PlaceDeParking *parking, const size_t nbVehicule) {
   assert(parking);
   
   for (size_t i = 0; i < nbVehicule; ++i) {
      assert(&parking[i]);
      assert(&parking[i].vehicule);

      parking[i].taxeAnnuelle = calculerTaxeAnnuelle(&parking[i].vehicule);
   }
}

int taxeAnnuelleDecroissant (const void* a, const void* b) {
   return ((PlaceDeParking*)b)->taxeAnnuelle - ((PlaceDeParking*)a)->taxeAnnuelle;
}

void trierParking(PlaceDeParking *parking, const size_t nbVehicule) {
   assert(parking);

   qsort(parking, nbVehicule, sizeof(PlaceDeParking), taxeAnnuelleDecroissant);
}

void afficherParking(const PlaceDeParking *parking, const size_t nbVehicule) {
   assert(parking);

   const char *TITRE = "*  Affichage du parking  *";
   const unsigned TAILLE_TITRE = (unsigned)strlen(TITRE);

   for (unsigned i = TAILLE_TITRE; i--; putchar('*'));
   printf("\n%s\n", TITRE);
   for (unsigned i = TAILLE_TITRE; i--; putchar('*'));
   printf("\n\n");

   for (size_t i = 0; i < nbVehicule; ++i) {
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

         printf("Categorie voiture        : %s\n", TYPES_VOITURE[VOIT_ALIAS.typevoiture]);
         printf("Poids [kg]               : %" PRIu16 "\n", VOIT_ALIAS.poids);

         switch (VOIT_ALIAS.typevoiture) {
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

   printf("Taxe annuelle [CHF]      : %" PRIu16 "\n", placeDeParking->taxeAnnuelle);
}

// Nettoyage des defines
#undef VOIT_ALIAS
#undef VOIT_STANDARD_ALIAS
#undef VOIT_HAUT_DE_GAMME_ALIAS
#undef CAMIONETTE_ALIAS
