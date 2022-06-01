/*
--------------------------------------------------------------------------------
Nom du fichier : main.c
Laboratoire    : Laboratoire nº 2 - Parking
Auteur(s)      : Florian Conti, Léo Zmoos & Leandro Saraiva Maia
Date creation  : 24.05.2022

Description    : Ce programme permet de modéliser un parking ainsi que les
                 voitures qui s'y trouvent. Ce programme calcule également
                 le montant des taxes pour les véhicules se trouvant dans
                 le parking. Le calcul des taxes est différent pour chaque
                 catégorie de véhicule et selon divers critères.

Remarque(s)    : Les limites du programme sont :
                  - 

Compilateur    : Compilation fonctionnelle avec :
                  - Mingw-w64 gcc 11.2.0
                  - gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
--------------------------------------------------------------------------------
*/

#include "vehicule.h"
#include "parking.h"

int main(void) {
   Vehicule vehicules[] = {
      creerVoitureStandard("VD123456", "Fiat", 1130u, 1200u, 125u),
      creerVoitureStandard("JU654321", "Toyota", 1320u, 1330u, 130u),
      creerVoitureStandard("BE011235", "Ford", 1660u, 2200u, 190u),
      creerVoitureHautDeGamme("LU080085", "Rolls-Royce", 2600u, 220u),
      creerVoitureHautDeGamme("GR343112", "Porsche", 1400u, 250u),
      creerVoitureHautDeGamme("ZH420666", "Jaguar", 1660u, 600u),
      creerCamionette("FR987654", "Citroen", 10.),
   };

   const size_t NB_VEHICULES = sizeof(vehicules) / sizeof(vehicules[0]);

   // Calcul de taxes et affichage du parking
   PlaceDeParking* parking =
      calculerTaxesAnnuellesParking(vehicules, NB_VEHICULES);
   trierParking(parking, NB_VEHICULES);
   afficherParking(parking, NB_VEHICULES);

   // Calcul et affichage des statistiques du parking
   const StatTaxes statVoitureStandard =
   calculerStatPlaceDePark(parking, NB_VEHICULES, estVoitureStandard);
   const StatTaxes statVoitureHautDeGamme =
      calculerStatPlaceDePark(parking, NB_VEHICULES, estVoitureHautDeGamme);
   const StatTaxes statCamionette =
      calculerStatPlaceDePark(parking, NB_VEHICULES, estCamionette);

   afficherStat("Statistiques des taxes des voitures standards:",
      &statVoitureStandard);
   afficherStat("\nStatistiques des taxes des voitures haut de gamme:",
      &statVoitureHautDeGamme);
   afficherStat("\nStatistiques des taxes des camionettes:",
      &statCamionette);

   // Libère la mémoire du parking
   free(parking);
}
