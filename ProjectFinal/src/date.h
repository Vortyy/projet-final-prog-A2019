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
 *  param: string &date : String dans lequel la date demand�e en format AAAA_MM_JJ sera enregistr�e.
 */
void getDate(string &date);

/*
 *
 *
 */
void askJour(int annee, int mois, int &jour);

/*
 *
 *
 */
void zeroSpacing(string &nombre, int nbChiffres);

#endif /* SRC_DATE_H_ */