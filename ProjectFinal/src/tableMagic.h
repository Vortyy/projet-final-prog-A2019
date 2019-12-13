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

void addLineToTables(string ligne, double tableQnt[], string tableType[], int index);
double editQnt(string qnt, string tableType[], int index);
void addVntesQnt(string ligne, double tableQnt[], int index);
void calcPertes(double tableInv[], double tableVntes[], double tablePertes[]);
void calcAnal(double tableInv[], double tableAchats[], double tableVntes[], double tablePertes[], double tableAnal[]);
void deKiloGraphy(string table[]);

#endif /* SRC_TABLEMAGIC_H_ */