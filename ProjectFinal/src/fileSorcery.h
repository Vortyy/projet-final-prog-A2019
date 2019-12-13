/*
 * fileSorcery.h
 *
 *  Created on: 12 dec. 2019
 *      Author: Étienne
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
 * fonction: Lit un fichier et envoit la ligne pour calculer la quantité de produits avec addVntesQnt
 * param: path: le path du fichier
 * param: double table: le table avec les quantités
 */
void readFileToTable(string path, double table[]);

/* 
 * fonction: fonction qui lit des lignes d'un fichier et mets les données dans table1 et table2
 * param: string path: le path du fichier à lire
 * param: double table1[]: table de double
 * param: string table2[]: table de string
 */
void readFileTo2Tables(string path, double table1[], string table2[]);

/*
 * fonction: Écrit dans un fichier un complexe mélange de données de trop de tableaux.
 * param: string path: le path du fichier à écrire
 * param: string tableNom[]: table contenant les noms des ingrédients.
 * param: string tableType[]: table contenant le type des ingrédients.
 * param: double tableInv[]: table contenant la quantité des ingrédients dans le fichier d'inventaire.
 * param: double tableAchat[]: table contenant la quantité des ingrédients dans le fichier d'achat.
 * param: double tableVentes[]: table contenant la quantité des ingrédients dans le fichier de ventes.
 * param: double tablePertes[]: table contenant la quantité des ingrédients perdus.
 * param: double tableAchat[]: table contenant la quantité finale des ingrédients.
 */
void writeAnal(string path, string tableNom[], string tableType[], double tableInv[], double tableAchat[], double tableVentes[], double tablePertes[], double tableAnal[]);

#endif /* SRC_FILESORCERY_H_ */