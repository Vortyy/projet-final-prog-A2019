/*
 * date.cpp
 *
 *  Created on: 7 dec. 2019
 *      Author: Étienne
 */

#include "date.h"

 /*
  *  Demandes la date à l'utilisateur
  *  param: string &date : String dans lequel la date demandée en format AAAA_MM_JJ sera enregistrée.
  */
void getDate(string &date) {
	int annee, mois, jour;

	askPositiveInt("Entrez l'année: ", annee);
	askIntWithBounds("Entrez le mois (1-12): ", mois, 1, 12);
	askJour(annee, mois, jour);

	string strAnnee = to_string(annee), strMois = to_string(mois), strJour = to_string(jour);
	zeroSpacing(strMois, -4); zeroSpacing(strJour, 2);

	date = strAnnee + "_" + strMois + "_" + strJour;
}

void askJour(int annee, int mois, int &jour) {
	switch (mois) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		askIntWithBounds("Entrez le jour (1-31): ", jour, 1, 31);
		break;

	case 4:
	case 6:
	case 9:
	case 11:
		askIntWithBounds("Entrez le jour (1-30): ", jour, 1, 30);
		break;

	case 2:
		if (annee % 4 == 0) {
			askIntWithBounds("Entrez le jour (1-29): ", jour, 1, 29);
		}
		else askIntWithBounds("Entrez le jour (1-28): ", jour, 1, 28);
		break;
	}
}

/*
 * Ajoutes des "0" avant le nombre jusqu'au nombre désiré de chiffres.
 */
void zeroSpacing(string &nombre, int nbChiffres) {
	string temp = "";
	for (int i = 0; i < (nbChiffres - 1); i++) {
		temp = "0" + temp;
	}

	nombre = temp + nombre;
}