/*
-----------------------------------------------------------------------------------
Nom du fichier : main.c
Laboratoire    : Laboratoire nº 2 - Parking
Auteur(s)      : Florian conti, Léo Zmoos & Leandro Saraiva Maia
Date creation  : 24.05.2022

Description    : Ce programme permet de modéliser un parking ainsi que les voitures
                 qui se trouvent dessus. Ce programme calcule également le montant
                 des taxes pour les véhicules se trouvant dans le parking. Le calcul
                 des taxes est différent pour chaque catégorie de véhicule.

Remarque(s)    : Les limites du programme sont :
                  - 

Compilateur    : Compilation fonctionnelle avec :
                  - Mingw-w64 gcc 11.2.0
                  - gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
-----------------------------------------------------------------------------------
*/

#include "vehicule.h"
#include "parking.h"

int main(void) {
   PlaceDeParking parking[] = {
      { creerVoitureStandard("VD123456", "Fiat", 1130u, 1200u, 125u) },
      { creerVoitureStandard("JU654321", "Toyota", 1320u, 1430u, 145u) },
      { creerVoitureStandard("BE011235", "Ford", 1660u, 2200u, 190u) },
      { creerVoitureHautDeGamme("LU080085", "Rolls-Royce", 2600u, 220u) },
      { creerVoitureHautDeGamme("ZH420666", "Jaguar", 1660u, 600u) },
      { creerCamionette("FR987654", "Citroen", 50u) }
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
