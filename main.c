#include <stdio.h>
#include "vehicule.h"
#include "parking.h"

int main(void) {
	// Exemples d'utilisation

   PlaceDeParking parking[] = {
      { .vehicule = voitureStandard("VD123456", "Fiat", 1130u, 1200u, 125u) },
      { .vehicule = voitureStandard("JU654321", "Toyota", 1320u, 1430u, 145u) },
      { .vehicule = voitureStandard("BE011235", "Ford", 1660u, 2200u, 190u) },
      { .vehicule = voitureHautDeGamme("LU080085", "Rolls-Royce", 2600u, 220u) },
      { .vehicule = voitureHautDeGamme("ZH420666", "Jaguar", 1660u, 600u) },
      { .vehicule = camionette("FR987654", "Citroen", 50u) }
   };

   const size_t NB_PLACE_DE_PARK = sizeof(parking) / sizeof(parking[0]);

   // Calcul de taxes et affichage du parking
   calculerTaxesAnnuellesParking(parking, NB_PLACE_DE_PARK);
   trierParking(parking, NB_PLACE_DE_PARK);
   afficherParking(parking, NB_PLACE_DE_PARK);

   // Calcul et affichage des statistiques du parking
   const StatTaxes statVoitureStandard = calculerStatPlaceDePark(parking, NB_PLACE_DE_PARK, estVoitureStandard);
   const StatTaxes statVoitureHautDeGamme = calculerStatPlaceDePark(parking, NB_PLACE_DE_PARK, estVoitureHautDeGamme);
   const StatTaxes statCamionette = calculerStatPlaceDePark(parking, NB_PLACE_DE_PARK, estCamionette);

   afficherStat("Statistiques des taxes des voitures standards:", &statVoitureStandard);
   afficherStat("\nStatistiques des taxes des voitures haut de gamme:", &statVoitureHautDeGamme);
   afficherStat("\nStatistiques des taxes des camionettes:", &statCamionette);
   
}
