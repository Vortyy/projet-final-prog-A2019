/*
 * tableMagic.h
 *
 *  Created on: 12 dec. 2019
 *      Author: �tienne
 */

#include <iostream>
#include <string>

using namespace std;

#ifndef SRC_TABLEMAGIC_H_
#define SRC_TABLEMAGIC_H_

/* 
 * fonction: S�pare les strings par le limiter ";"
 * param: string ligne
 * param: double tableQnt[]: Table
 * param: string tableType[]:
 * param: index: incrementeur
 */
void addLineToTables(string ligne, double tableQnt[], string tableType[], int index);

/* fonction: Si le type est "kg", il calcule le type en grammes
 * param: string path: le path du fichier � lire
 * param: tableType[]: table avec les types d'unit� de mesures
 * param: int index: incrementeur
 * return:
 */
double editQnt(string qnt, string tableType[], int index);

/* 
 * fonction: Calcule la quantit� de produits
 * param: string path: le path du fichier � lire
 * param: double table1[]: table de double
 * param: string table2[]: table de string
 */
void addVntesQnt(string ligne, double tableQnt[], int index);

/*
 * fonction: Calcul les pertes
 * param: tableInv[]: table avec les quantit�s de produits en inventaire
 * param: tableVntes[]: table avec la quantit� de produits vendu
 * param: tablePertes[]: table avec les pertes, necessaire pour calculer l'analyse
 */
void calcPertes(double tableInv[], double tableVntes[], double tablePertes[]);

/*
 * fonction: Effectue le calcul pour le table d'analyse
 * param: tableInv[]: Table avec les quantit�s de produits dans l'inventaire
 * param: tableAchats[]: Table avec les quantit�s de produits d'achats du jour
 * param: tableVntes[]: Table avec les quantit�s de produits vendus
 * param: tablePertes[]: Table avec la quantit� de pertes
 * param: tableAnal[]: Table avec les quantit�s finals d'analyse
 */
void calcAnal(double tableInv[], double tableAchats[], double tableVntes[], double tablePertes[], double tableAnal[]);

/*
 * fonction: transforme les valeurs "kg" en "g"
 * param: table[]: tableau dans lequel le changement de valeur est effectu�.
 */
void deKiloGraphy(string table[]);

#endif /* SRC_TABLEMAGIC_H_ */