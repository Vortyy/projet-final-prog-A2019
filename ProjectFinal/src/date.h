/*
 * cleanIO.h
 *
 *  Created on: 17 oct. 2019
 *      Author: �tienne
 */

#include <iostream>
#include <string>
#include "cleanIO.h"

using namespace std;

#ifndef SRC_DATE_H_
#define SRC_DATE_H_

/*
 *  Demandes la date � l'utilisateur
 *  param: string &today : String dans lequel la date demand�e en format AAAA_MM_JJ sera enregistr�e.
 *  param: string &hier : String dans lequel la date d'hier en format AAAA_MM_JJ sera enregistr�e.
 */
void getDates(string &today, string &hier);

void askToday(int &annee, int &mois, int &jour);

void getHier(int annee, int mois, int jour, int &anneeHier, int &moisHier, int &jourHier);

void askJour(int annee, int mois, int &jour);

void dateToFormat(string &date, int annee, int mois, int jour);

void zeroSpacing(string &nombre, int nbChiffres);

#endif /* SRC_DATE_H_ */