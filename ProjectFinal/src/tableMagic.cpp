/*
 * tableMagic.cpp
 *
 *  Created on: 12 dec. 2019
 *      Author: �tienne
 */

#include "tableMagic.h"
#include "beeseChurger.h"

 /*
  * fonction: S�pare les strings par le limiter ";"
  * param: string ligne
  * param: double tableQnt[]: Table
  * param: string tableType[]:
  * param: index: incrementeur
  */
void addLineToTables(string ligne, double tableQnt[], string tableType[], int index) {
	string limiter = ";"; string temp;
	auto start = 0U;
	auto limit = ligne.find(limiter);

	temp = ligne.substr(start, limit - start);

	start = limit + limiter.length();
	limit = ligne.find(limiter, start);

	string qnt = ligne.substr(start, limit - start);

	start = limit + limiter.length();
	limit = ligne.find(limiter, start);

	tableType[index] = ligne.substr(start, limit - start);
	tableQnt[index] = editQnt(qnt, tableType, index);
}

/* 
 * fonction: Si le type est "kg", il calcule le type en grammes
 * param: string path: le path du fichier � lire
 * param: tableType[]: table avec les types d'unit� de mesures
 * param: int index: incrementeur
 * return:
 */
double editQnt(string qnt, string tableType[], int index) {
	double newQnt;
	newQnt = stod(qnt);

	if (tableType[index] == "kg") {
		newQnt *= 1000;
	}
	return newQnt;
}

/* 
 * fonction: Calcule la quantit� de produits
 * param: string path: le path du fichier � lire
 * param: double table1[]: table de double
 * param: string table2[]: table de string
 */
void addVntesQnt(string ligne, double tableQnt[], int index) {
	string limiter = ";"; string temp;
	double ventes; double nbItem;
	auto start = 0U; auto limit = ligne.find(limiter);

	temp = ligne.substr(start, limit - start);
	start = limit + limiter.length();
	limit = ligne.find(limiter, start);

	string qnt = ligne.substr(start, limit - start);
	ventes = stoi(qnt);

	switch (index) {
	case 0:
		nbItem = ceil(ventes / 5.23);
		bigMac(nbItem, tableQnt);
		break;

	case 1:
		nbItem = ceil(ventes / 2.62);
		beeseChurger(nbItem, tableQnt);
		break;

	case 2:
		nbItem = ceil(ventes / 4.96);
		quartLivre(nbItem, tableQnt);
		break;

	case 3:
		nbItem = ceil(ventes / 6.27);
		doubleQuartLivre(nbItem, tableQnt);
		break;

	case 4:
		nbItem = ceil(ventes / 5.88);
		baconClub(nbItem, tableQnt);
	default:
		break;
	}
}

/* 
 * fonction: Calcul les pertes
 * param: tableInv[]: table avec les quantit�s de produits en inventaire
 * param: tableVntes[]: table avec la quantit� de produits vendu
 * param: tablePertes[]: table avec les pertes, necessaire pour calculer l'analyse
 */
void calcPertes(double tableInv[], double tableVntes[], double tablePertes[]) {
	for (int i = 0; i < 9; i++) {
		tablePertes[i] = tableInv[i] - tableVntes[i];
	}
}

/* 
 * fonction: Effectue le calcul pour le table d'analyse
 * param: tableInv[]: Table avec les quantit�s de produits dans l'inventaire
 * param: tableAchats[]: Table avec les quantit�s de produits d'achats du jour
 * param: tableVntes[]: Table avec les quantit�s de produits vendus
 * param: tablePertes[]: Table avec la quantit� de pertes
 * param: tableAnal[]: Table avec les quantit�s finals d'analyse
 */
void calcAnal(double tableInv[], double tableAchats[], double tableVntes[], double tablePertes[], double tableAnal[]) {
	for (int i = 0; i < 9; i++) {
		tableAnal[i] = tableInv[i] + tableAchats[i] - tableVntes[i] - tablePertes[i];
	}
}

/*
 * fonction: transforme les valeurs "kg" en "g"
 * param: table[]: tableau dans lequel le changement de valeur est effectu�.
 */
void deKiloGraphy(string table[]) {
	for (int i = 0; i < 9; i++) {
		if (table[i] == "kg") table[i] = "g";
	}
}