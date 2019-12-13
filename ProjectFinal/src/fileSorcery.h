/*
 * fileSorcery.h
 *
 *  Created on: 12 dec. 2019
 *      Author: �tienne
 */

#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "tableMagic.h"

using namespace std;

#ifndef SRC_FILESORCERY_H_
#define SRC_FILESORCERY_H_

/* 
 * fonction: Lit un fichier et envoit la ligne pour calculer la quantit� de produits avec addVntesQnt
 * param: path: le path du fichier
 * param: double table: le table avec les quantit�s
 */
void readFileToTable(string path, double table[]);

/* 
 * fonction: fonction qui lit des lignes d'un fichier et mets les donn�es dans table1 et table2
 * param: string path: le path du fichier � lire
 * param: double table1[]: table de double
 * param: string table2[]: table de string
 */
void readFileTo2Tables(string path, double table1[], string table2[]);

/*
 * fonction: �crit dans un fichier un complexe m�lange de donn�es de trop de tableaux.
 * param: string path: le path du fichier � �crire
 * param: string tableNom[]: table contenant les noms des ingr�dients.
 * param: string tableType[]: table contenant le type des ingr�dients.
 * param: double tableInv[]: table contenant la quantit� des ingr�dients dans le fichier d'inventaire.
 * param: double tableAchat[]: table contenant la quantit� des ingr�dients dans le fichier d'achat.
 * param: double tableVentes[]: table contenant la quantit� des ingr�dients dans le fichier de ventes.
 * param: double tablePertes[]: table contenant la quantit� des ingr�dients perdus.
 * param: double tableAchat[]: table contenant la quantit� finale des ingr�dients.
 */
void writeAnal(string path, string tableNom[], string tableType[], double tableInv[], double tableAchat[], double tableVentes[], double tablePertes[], double tableAnal[]);

#endif /* SRC_FILESORCERY_H_ */