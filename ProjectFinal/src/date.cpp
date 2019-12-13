/*
 * date.cpp
 *
 *  Created on: 7 dec. 2019
 *      Author: Étienne
 */

#include "date.h"

 /*
  *  Demandes la date à l'utilisateur
  *  param: string &today : String dans lequel la date demandée en format AAAA_MM_JJ sera enregistrée.
  *  param: string &hier : String dans lequel la date d'hier en format AAAA_MM_JJ sera enregistrée.
  */
void getDates(string &today, string &hier) {
	int annee, mois, jour;
	askToday(annee, mois, jour);

	int anneeHier = annee, moisHier = mois, jourHier = jour;
	getHier(annee, mois, jour, anneeHier, moisHier, jourHier);

	dateToFormat(today, annee, mois, jour);
	dateToFormat(hier, anneeHier, moisHier, jourHier);
}

/*
 * fonction: demande a l'utilsateur l'année et le mois
 * param: annee, mois et jour
 */
void askToday(int &annee, int &mois, int &jour) {
	askPositiveInt("Entrez l'année: ", annee);
	askIntWithBounds("Entrez le mois (1-12): ", mois, 1, 12);
	askJour(annee, mois, jour);
}

/*
 * fonction: retourne la date de hier dapres la date entrer par l'utilisateur
 * param: annee, jour, mois,
 * param: anneeHier, moisHier, jourHier: ont la valeur de la date entré par l'utilisateur et, à la fin, ont la valeur de hier
 */
void getHier(int annee, int mois, int jour, int &anneeHier, int &moisHier, int &jourHier) {
	if (jour == 1) {
		moisHier -= 1;
		switch (moisHier) {
		case 0:
			anneeHier = annee - 1;
			moisHier = 12;
			jourHier = 31;
			break;

		case 2:
			if (annee % 4 == 0) {
				jourHier = 29;
			} else jourHier = 28;
			break;

		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			jourHier = 31;
			break;

		case 4:
		case 6:
		case 9:
		case 11:
			jourHier = 30;
			break;
		}
	} else jourHier = jour - 1;
}

/*
 * fonction: demande a l'utilisateur, dépendant du mois entré, le jour
 * param: annee, mois et jour
 */
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
 * param: &nombre: Annee, mois ou jour
 * param: nbChiffres: nombre de characters que le string doit avoir
 */
void zeroSpacing(string &nombre, int nbChiffres) {
	string temp = "";
	for (int i = 0; i < (nbChiffres - nombre.length()); i++) {
		temp = "0" + temp;
	}

	nombre = temp + nombre;
}

/* 
 * fonction: met les int annee, mois et jour en string et envoie les string a zeroSpacing avec le nombre de spacing requit et finalement retourne la variable "date" format final
 * param: string &date: today ou hier
 * param: int annee, mois et jour: la date precise
 */
void dateToFormat(string &date, int annee, int mois, int jour) {
	string strAnnee = to_string(annee), strMois = to_string(mois), strJour = to_string(jour);
	
	zeroSpacing(strAnnee, 4); 
	zeroSpacing(strMois, 2); 
	zeroSpacing(strJour, 2);

	date = strAnnee + "_" + strMois + "_" + strJour;
}