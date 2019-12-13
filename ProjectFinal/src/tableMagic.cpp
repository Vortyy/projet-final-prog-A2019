/*
 * tableMagic.cpp
 *
 *  Created on: 12 dec. 2019
 *      Author: Étienne
 */

#include "tableMagic.h"
#include "beeseChurger.h"

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

double editQnt(string qnt, string tableType[], int index) {
	double newQnt;
	newQnt = stod(qnt);

	if (tableType[index] == "kg") {
		newQnt *= 1000;
	}
	return newQnt;
}

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

void calcPertes(double tableInv[], double tableVntes[], double tablePertes[]) {
	for (int i = 0; i < 9; i++) {
		tablePertes[i] = tableInv[i] - tableVntes[i];
	}
}

void calcAnal(double tableInv[], double tableAchats[], double tableVntes[], double tablePertes[], double tableAnal[]) {
	for (int i = 0; i < 9; i++) {
		tableAnal[i] = tableInv[i] + tableAchats[i] - tableVntes[i] - tablePertes[i];
	}
}