//
// Created by florian on 24.05.2022.
//

#include "parking.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

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
      //printf(calculerTaxe);
      printf("\n--------------------------------\n\n");
   }
}