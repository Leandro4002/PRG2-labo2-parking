/*
--------------------------------------------------------------------------------
Nom du fichier : taxes.c
Auteur(s)      : Florian Conti, Léo Zmoos & Leandro Saraiva Maia
Date creation  : 24.05.2022

Remarque(s)    : Lors du calcul de taxe, on retourne 0 quand le type de véhicule
                 n'est pas pris en charge. Il y a une fonction par type de
                 véhicule pour calculer la taxe, lors de l'ajout d'un type, il
                 suffira d'ajouter une fonction et de l'utiliser au bon endroit.
                 Il y a beaucoup de fonctions qui ne sont pas exposés et qui
                 sont nécessaires uniquement en interne.

Compilateur    : Compilation fonctionnelle avec :
                  - gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
--------------------------------------------------------------------------------
*/

#include <assert.h> // Requis pour assert
#include "taxes.h"

// Prédéclarations de fonctions internes
double calculerTaxeVoitureStandard(const Vehicule* vehicule);
double calculerTaxeVoitureHautDeGamme(const Vehicule* vehicule);
double calculerTaxeVoiture(const Vehicule* vehicule);
double calculerTaxeCamionette(const Vehicule* vehicule);

double calculerTaxeAnnuelle(const Vehicule* vehicule) {
   assert(vehicule);

   switch (vehicule->typeVehicule) {
      case VOITURE:
         return calculerTaxeVoiture(vehicule);
         break;
      case CAMIONETTE:
         return calculerTaxeCamionette(vehicule);
      default:
         return 0;
   }
}

double calculerTaxeVoitureStandard(const Vehicule* vehicule) {
   assert(vehicule);

   double montant = 0.;

   if (vehicule->voiture.standard.cylindree < LIMITE_CYLINDREE_TAXE) {
      montant += vehicule->voiture.standard.quantiteRejetCO2
         < LIMITE_CO2_TAXE ? TAXE_POLLUTION_1 : TAXE_POLLUTION_2;
   } else {
      montant += TAXE_POLLUTION_3
         * (double)vehicule->voiture.standard.cylindree;
   }

   return montant;
}

double calculerTaxeVoitureHautDeGamme(const Vehicule* vehicule) {
   assert(vehicule);

   double montant = 0.;

   if (vehicule->voiture.hautDeGamme.puissanceDuMoteur
         <= LIMITE_PUISSANCE_MOTEUR_TAXE) {
      montant += TAXE_PUISSANCE_MOTEUR_CHF;
   } else {
      montant += TAXE_HAUTE_PUISSANCE_MOTEUR_CHF
         + (double)vehicule->voiture.poids / 1000.
         * TAXE_PUISSANCE_POIDS_CHF;
   }

   return montant;
}

double calculerTaxeVoiture(const Vehicule* vehicule) {
   assert(vehicule);

   double montant = 0.;

   // Taxe de base
   montant += TAXE_BASE_VOITURE_CHF;

   // Taxe spécifique
   switch (vehicule->voiture.typeVoiture) {
      case STANDARD:
         montant += calculerTaxeVoitureStandard(vehicule);
         break;
      case HAUT_DE_GAMME:
         montant += calculerTaxeVoitureHautDeGamme(vehicule);
         break;
   }

   return montant;
}

double calculerTaxeCamionette(const Vehicule* vehicule) {
   assert(vehicule);

   double montant = 0.;

   // Taxe de base
   montant += TAXE_BASE_CAMIONETTE_CHF;

   // Taxe spécifique
   montant += TAXE_CAMIONETTE_PAR_VOLUME_CHF
      * vehicule->camionette.volumeTransport;

   return montant;
}
