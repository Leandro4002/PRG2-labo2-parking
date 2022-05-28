#include <assert.h>
#include "taxes.h"

// Constantes --------------------------------------------------------------------------------------
// Voir le fichier .h correspondant pour plus d'informations
const double TAXE_BASE_VOITURE_CHF = 400.;
const double TAXE_BASE_CAMIONETTE_CHF = 700.;
const double TAXE_POLLUTION_1 = 0.;
const double TAXE_POLLUTION_2 = 50.;
const double TAXE_POLLUTION_3 = 0.05;
const double TAXE_PUISSANCE_MOTEUR_CHF = 200.;
const double TAXE_HAUTE_PUISSANCE_MOTEUR_CHF = 300.;
const double TAXE_PUISSANCE_POIDS_CHF = 20.;
const double TAXE_CAMIONETTE_PAR_VOLUME_CHF = 10.;
const ui16   LIMITE_PUISSANCE_MOTEUR_TAXE = 250u;
const ui16   LIMITE_CYLINDREE_TAXE = 1400u;
const ui16   LIMITE_CO2_TAXE = 130u;
	
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
			switch (VOIT_ALIAS.typevoiture) {
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
