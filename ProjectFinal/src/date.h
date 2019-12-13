/*
 * cleanIO.h
 *
 *  Created on: 17 oct. 2019
 *      Author: Étienne
 */

#include <iostream>
#include <string>
#include "cleanIO.h"

using namespace std;

#ifndef SRC_DATE_H_
#define SRC_DATE_H_

/*
 *  Demandes la date à l'utilisateur
 *  param: string &today : String dans lequel la date demandée en format AAAA_MM_JJ sera enregistrée.
 *  param: string &hier : String dans lequel la date d'hier en format AAAA_MM_JJ sera enregistrée.
 */
void getDates(string &today, string &hier);

/* 
 * fonction: demande a l'utilsateur l'année et le mois
 * param: annee, mois et jour
 */
void askToday(int &annee, int &mois, int &jour);

/* 
 * fonction: retourne la date de hier dapres la date entrer par l'utilisateur
 * param: annee, jour, mois,
 * param: anneeHier, moisHier, jourHier: ont la valeur de la date entré par l'utilisateur et, à la fin, ont la valeur de hier
 */
void getHier(int annee, int mois, int jour, int &anneeHier, int &moisHier, int &jourHier);

/* 
 * fonction: demande a l'utilisateur, dépendant du mois entré, le jour
 * param: annee, mois et jour
 */
void askJour(int annee, int mois, int &jour);

/*
 * fonction: met les int annee, mois et jour en string et envoie les string a zeroSpacing avec le nombre de spacing requit et finalement retourne la variable "date" format final
 * param: string &date: today ou hier
 * param: int annee, mois et jour: la date precise
 */
void dateToFormat(string &date, int annee, int mois, int jour);

/*
 * Ajoutes des "0" avant le nombre jusqu'au nombre désiré de chiffres.
 * param: &nombre: Annee, mois ou jour
 * param: nbChiffres: nombre de characters que le string doit avoir
 */
void zeroSpacing(string &nombre, int nbChiffres);

#endif /* SRC_DATE_H_ */