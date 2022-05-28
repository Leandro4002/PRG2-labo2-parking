#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "parking.h"
#include "taxes.h"

void afficherParking(const Vehicule *parking, const size_t nbVehicule) {
   assert(parking);
   const char *TITRE = "*  Affichage du parking  *";
   const unsigned TAILLE_TITRE = (unsigned int) strlen(TITRE);

   for (unsigned i = TAILLE_TITRE; i--; putchar('*'));
   printf("\n%s\n", TITRE);
   for (unsigned i = TAILLE_TITRE; i--; putchar('*'));
   printf("\n\n");

   for (size_t i = 0; i < nbVehicule; ++i) {
      assert(&parking[i]);
      afficherVehicule(&parking[i]);
      
      ui16 taxeAnnuelle = calculerTaxeAnnuelle(&parking[i]);
      printf("Taxe annuelle [CHF]      : %" PRIu16 "\n", taxeAnnuelle);

      printf("\n--------------------------------\n\n");
   }
}