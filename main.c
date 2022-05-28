#include <stdio.h>
#include "vehicule.h"
#include "parking.h"

int main(void) {
	// Exemples d'utilisation

   PlaceDeParking parking[] = {
      { .vehicule = voitureStandard("VD123456", "Fiat", 1130u, 1200u, 145u) },
      { .vehicule = voitureHautDeGamme("ZH123455", "Jaguar", 1660u, 600u) },
      { .vehicule = camionette("FR123444", "Citroen", 50u) }
   };

   const size_t NB_VEHICULE = sizeof(parking) / sizeof(parking[0]);

   calculerTaxesAnnuellesParking(parking, NB_VEHICULE);

   trierParking(parking, NB_VEHICULE);

   afficherParking(parking, NB_VEHICULE);
}
