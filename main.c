/*
TODO
 - Réordonner les attributs des structs pour que ça prennent le moins de place possible

*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "vehicule.h"



// Constantes
const ui16 TAXE_BASE_VOITURE_CHF = 400;
const ui16 TAXE_BASE_CAMIONETTE_CHF = 700;
const ui16 TAXE_CAMIONETTE_PAR_VOLUME_CHF = 10; // volume m3
const ui16 TAXE_PUISSANCE_MOTEUR_CHF = 200; // en chevaux
const ui16 TAXE_POIDS_CHF = 20; // en tonnes
const ui16 TAXE_CYLINDREE_1 = 0; // en cm3
const ui16 TAXE_CYLINDREE_2 = 50; // en cm3
const double TAXE_CYLINDREE_3 = 0.05; // en cm3



int main(void) {
	// Exemples d'utilisation

   const Vehicule *parking[] = {
      voitureStandard("VD123456", "Fiat", 300, 150, 5),
      voitureHautDeGamme("VD123455", "Jaguar", 1000, 600),
      camionette("VD123444", "Citroen", 500)
   };

}



/*
Vehicule
   |
   |
   |--- Voiture
   |       |
   |	   |--- Bas de gamme
   |	   |
   |	   |--- Haut de gamme
   |
   |--- Camionette


Commun
 - char* Plaque d'immatriculation
 - char* Marque
 - Type vehicule (voiture et camionette)

Camionette
 - double volume de transport [m3]

Voiture standard
 - uint16_t cm3 de cylindrée
 - uint16_t quantité rejet de CO2
 - uint16_t Poids

Voiture haut de gamme
 - uint16_t Puissance du moteur [CV]
 - uint16_t Poids
*/


/*
Une ville possède un parking municipal dont les places sont louées à l'année.
Ladite ville vous a mandaté pour lui réaliser un logiciel lui permettant de calculer le montant
de la taxe annuelle due par chacun des véhicules stationnnant sur son parking.
Les informations que vous avez recueillies sont les suivantes :
• Seules des voitures et des camionnettes peuvent stationner sur le parking.
• Tout véhicule (camionnette et voiture) possède une plaque d'immatriculation (par ex "VD
123456") et est d'une certaine marque (par ex "Peugeot")
• Deux catégories de voitures sont à considérer : les voitures standards et les voitures haut
de gamme.
• Si le véhicule est une camionette, il faut enregistrer son volume de transport en [m3] (type
double)
• Toute voiture se caractérise par son poids [kg] (type uint16_t)
• Si la voiture est de type "standard", il faut enregistrer sa cylindrée [cm3] (type uint16_t)
ainsi que sa quantité de rejet de CO2 [g/km] (type uint16_t)
• Si la voiture est de type "haut de gamme", il faut enregistrer sa puissance [CV] (type
uint16_t)
• La taxe annuelle (réel exprimé en CHF) due par véhicule est composée de deux
contributions :
o une taxe de base, identique pour tous les véhicules d'une même catégorie
(camionnette, voiture)
o une taxe spécifique, dépendant du type de véhicule
• Taxe de base :
o 700 CHF pour une camionnette
o 400 CHF pour une voiture
• Taxe spécifique :
o Camionnette :
 10 CHF * volume de transport [m3]
o Voiture standard :
 0 CHF si la cylindrée est < 1400 [cm3] et la quantité de rejet de CO2 est
< 130 [g/km]
 50 CHF si la cylindrée est < 1400 [cm3] et la quantité de rejet de CO2 est
≥ 130 [g/km]
 0.05 CHF * cylindrée [cm3], si la cylindrée est ≥ 1400 [cm3]
o Voiture haut de gamme :
 200 CHF si la puissance du moteur ≤ 250 [CV]
 300 CHF + 20 CHF * poids (en tonnes), sinon
HEIG-VD PRG2 : Laboratoire
Département TIC 23.05.2022 / RRH
2 / 2
Il est demandé ici :
• d'implémenter le plus proprement possible les divers éléments nécessaires à la
modélisation du problème décrit plus haut
• d'écrire un programme principal (main) qui doit :
1) déclarer un tableau (qui représentera le parking) et le remplir "en dur" (donc pas de
dialogue utilisateur !) avec quelques véhicules
2) afficher l'ensemble des caractéristiques ainsi que la taxe annuelle due de chacun des
véhicules du parking
N.B. L'affichage doit se faire par ordre décroissant des taxes annuelles
3) afficher, par type de véhicule (camionnette, voiture standard, voiture haut de gamme),
la somme, la moyenne, la médiane et l'écart-type des taxes annuelles dues
*/
