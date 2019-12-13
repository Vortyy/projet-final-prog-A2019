/*
 * fileSorcery.h
 *
 *  Created on: 12 dec. 2019
 *      Author: Étienne
 */

#include <string>
#include <fstream>
#include "tableMagic.h"

using namespace std;

#ifndef SRC_FILESORCERY_H_
#define SRC_FILESORCERY_H_

void readFileToTable(string path, double table[]);
void readFileTo2Tables(string path, double table1[], string table2[]);

#endif /* SRC_FILESORCERY_H_ */