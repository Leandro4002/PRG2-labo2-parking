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

#include <stdio.h>    // Requis pour printf
#include <stdlib.h>   // Requis pour size_t
#include "vehicule.h"
#include "parking.h"
#include "statistique.h"

// Constantes pour les messages
#define TEXTE_STAT_STANDARD "Statistiques des taxes des voiture(s) standard(s):"
#define TEXTE_STAT_HAUT_DE_GAMME \
"Statistiques des taxes de(s) voiture(s) haut de gamme:"
#define TEXTE_STAT_CAMIONETTE "Statistiques des taxes de(s) camionette(s):"

#define MSR_ERR_ALLOC_MEMOIRE "Erreur d'allocation de mémoire."

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

   // Calcul de taxes, tri et affichage du parking
   PlaceDeParking* parking =
      calculerTaxesAnnuellesParking(vehicules, NB_VEHICULES);
   
   if (!parking) {
      printf(MSR_ERR_ALLOC_MEMOIRE);
      return EXIT_FAILURE;
   }

   PlaceDeParking* parkingTrie = trierParking(parking, NB_VEHICULES,
      taxeAnnuelleDecroissant);

   if (!parkingTrie) {
      printf(MSR_ERR_ALLOC_MEMOIRE);
      return EXIT_FAILURE;
   }

   free(parking);
   parking = NULL;

   afficherParking(parkingTrie, NB_VEHICULES);

   // Calcul et affichage des statistiques du parking
   const Stat statVoitureStandard = calculerStatPlaceDePark(
      parkingTrie, NB_VEHICULES, estVoitureStandard);
   const Stat statVoitureHautDeGamme = calculerStatPlaceDePark(
      parkingTrie, NB_VEHICULES, estVoitureHautDeGamme);
   const Stat statCamionette = calculerStatPlaceDePark(
      parkingTrie, NB_VEHICULES, estCamionette);
   
   free(parkingTrie);
   parkingTrie = NULL;

   afficherStat(TEXTE_STAT_STANDARD, &statVoitureStandard);
   afficherStat("\n" TEXTE_STAT_HAUT_DE_GAMME, &statVoitureHautDeGamme);
   afficherStat("\n" TEXTE_STAT_CAMIONETTE, &statCamionette);

   return EXIT_SUCCESS;
}
