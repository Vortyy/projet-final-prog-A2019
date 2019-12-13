/*
 * beeseChurger.cpp
 *
 *  Created on: 12 dec. 2019
 *      Author: Étienne
 */

#include "beeseChurger.h"

void bigMac(double nbItem, double tableQntIng[]) {
	tableQntIng[0] += nbItem * 2 * 45.4;
	tableQntIng[1] += nbItem * 3;
	tableQntIng[2] += nbItem * 2;
	tableQntIng[3] += nbItem * 1;
	tableQntIng[5] += nbItem * 3;
	tableQntIng[6] += nbItem * 12;
	tableQntIng[8] += nbItem * 7;
}

void beeseChurger(double nbItem, double tableQntIng[]) {
	tableQntIng[0] += nbItem * 45.4;
	tableQntIng[1] += nbItem * 2;
	tableQntIng[3] += nbItem * 1;
	tableQntIng[5] += nbItem * 2;
	tableQntIng[6] += nbItem * 6;
}

void quartLivre(double nbItem, double tableQntIng[]) {
	tableQntIng[0] += nbItem * 113;
	tableQntIng[1] += nbItem * 2;
	tableQntIng[3] += nbItem * 1;
	tableQntIng[5] += nbItem * 3;
	tableQntIng[6] += nbItem * 12;
}

void doubleQuartLivre(double nbItem, double tableQntIng[]) {
	tableQntIng[0] += nbItem * 226;
	tableQntIng[1] += nbItem * 2;
	tableQntIng[3] += nbItem * 2;
	tableQntIng[5] += nbItem * 4;
	tableQntIng[6] += nbItem * 12;
}

void baconClub(double nbItem, double tableQntIng[]) {
	tableQntIng[0] += nbItem * 113;
	tableQntIng[1] += nbItem * 2;
	tableQntIng[2] += nbItem * 3;
	tableQntIng[4] += nbItem * 1;
	tableQntIng[5] += nbItem * 4;
	tableQntIng[7] += nbItem * 2;
	tableQntIng[8] += nbItem * 7;
}