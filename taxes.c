/*
-----------------------------------------------------------------------------------
Nom du fichier : taxes.c
Auteur(s)      : Florian conti, Léo Zmoos & Leandro Saraiva Maia
Date creation  : 24.05.2022

Description    : 

Remarque(s)    : Les limites du programme sont :
                  - 

Compilateur    : Compilation fonctionnelle avec :
                  - Mingw-w64 gcc 11.2.0
                  - gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
-----------------------------------------------------------------------------------
*/

#include <assert.h> // Requis pour assert
#include "taxes.h"
	
// Utilisation de macro afin d'améliorer la lisibilité du code
#define VOIT_ALIAS vehicule->specificiteVehicule.voiture
#define VOIT_STANDARD_ALIAS VOIT_ALIAS.specificiteVoiture.standard
#define VOIT_HAUT_DE_GAMME_ALIAS VOIT_ALIAS.specificiteVoiture.hautDeGamme
#define CAMIONETTE_ALIAS vehicule->specificiteVehicule.camionette

double calculerTaxeAnnuelle(const Vehicule* vehicule) {
	assert(vehicule);

	double montant = 0.;

	switch (vehicule->typeVehicule) {
		case VOITURE:
			// Taxe de base
			montant += TAXE_BASE_VOITURE_CHF;

			// Taxe spécifique
			switch (VOIT_ALIAS.typeVoiture) {
				case STANDARD:
					if (VOIT_STANDARD_ALIAS.cm3Cylindree < LIMITE_CYLINDREE_TAXE) {
						montant += VOIT_STANDARD_ALIAS.quantiteRejetCO2 < LIMITE_CO2_TAXE ? TAXE_POLLUTION_1 : TAXE_POLLUTION_2;
					} else {
						montant += TAXE_POLLUTION_3 * (double)VOIT_STANDARD_ALIAS.cm3Cylindree;
					}
					break;
				case HAUT_DE_GAMME:
					if (VOIT_HAUT_DE_GAMME_ALIAS.puissanceDuMoteur <= LIMITE_PUISSANCE_MOTEUR_TAXE) {
						montant += TAXE_PUISSANCE_MOTEUR_CHF;
					} else {
						montant += TAXE_HAUTE_PUISSANCE_MOTEUR_CHF + (double)VOIT_ALIAS.poids / 1000. * TAXE_PUISSANCE_POIDS_CHF;
					}
					break;
			}
			break;
		case CAMIONETTE:
			// Taxe de base
			montant += TAXE_BASE_CAMIONETTE_CHF;

			// Taxe spécifique
			montant += TAXE_CAMIONETTE_PAR_VOLUME_CHF * CAMIONETTE_ALIAS.volumeTransport;
			break;
	}

	return montant;
}

// Nettoyage des defines
#undef VOIT_ALIAS
#undef VOIT_STANDARD_ALIAS
#undef VOIT_HAUT_DE_GAMME_ALIAS
#undef CAMIONETTE_ALIAS
