/*
 * tableMagic.h
 *
 *  Created on: 12 dec. 2019
 *      Author: Étienne
 */

#include <iostream>
#include <string>

using namespace std;

#ifndef SRC_TABLEMAGIC_H_
#define SRC_TABLEMAGIC_H_

/* 
 * fonction: Sépare les strings par le limiter ";"
 * param: string ligne
 * param: double tableQnt[]: Table
 * param: string tableType[]:
 * param: index: incrementeur
 */
void addLineToTables(string ligne, double tableQnt[], string tableType[], int index);

/* fonction: Si le type est "kg", il calcule le type en grammes
 * param: string path: le path du fichier à lire
 * param: tableType[]: table avec les types d'unité de mesures
 * param: int index: incrementeur
 * return:
 */
double editQnt(string qnt, string tableType[], int index);

/* 
 * fonction: Calcule la quantité de produits
 * param: string path: le path du fichier à lire
 * param: double table1[]: table de double
 * param: string table2[]: table de string
 */
void addVntesQnt(string ligne, double tableQnt[], int index);

/*
 * fonction: Calcul les pertes
 * param: tableInv[]: table avec les quantités de produits en inventaire
 * param: tableVntes[]: table avec la quantité de produits vendu
 * param: tablePertes[]: table avec les pertes, necessaire pour calculer l'analyse
 */
void calcPertes(double tableInv[], double tableVntes[], double tablePertes[]);

/*
 * fonction: Effectue le calcul pour le table d'analyse
 * param: tableInv[]: Table avec les quantités de produits dans l'inventaire
 * param: tableAchats[]: Table avec les quantités de produits d'achats du jour
 * param: tableVntes[]: Table avec les quantités de produits vendus
 * param: tablePertes[]: Table avec la quantité de pertes
 * param: tableAnal[]: Table avec les quantités finals d'analyse
 */
void calcAnal(double tableInv[], double tableAchats[], double tableVntes[], double tablePertes[], double tableAnal[]);

/*
 * fonction: transforme les valeurs "kg" en "g"
 * param: table[]: tableau dans lequel le changement de valeur est effectué.
 */
void deKiloGraphy(string table[]);

#endif /* SRC_TABLEMAGIC_H_ */