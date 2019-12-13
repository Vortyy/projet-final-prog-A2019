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

void readFileToTable(string path, double table[]);
void readFileTo2Tables(string path, double table1[], string table2[]);
void writeAnal(string path, string tableNom[], string tableType[], double tableInv[], double tableAchat[], double tableVentes[], double tablePertes[], double tableAnal[]);

#endif /* SRC_FILESORCERY_H_ */