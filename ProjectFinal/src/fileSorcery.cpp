/*
 * fileSorcery.cpp
 *
 *  Created on: 12 dec. 2019
 *      Author: Étienne
 */

#include "fileSorcery.h"

void readFileToTable(string path, double table[]) {
	ifstream file(path);
	string ligne;
	int index = 0;

	if (file) {
		index = 0;
		while (!file.eof()) {
			getline(file, ligne);
			addVntesQnt(ligne, table, index);
			index++;
		}

		file.close();
	}
	else cout << path << " could not be opened." << endl;
}

void readFileTo2Tables(string path, double table1[], string table2[]) {
	ifstream file(path);
	string ligne;
	int index = 0;

	if (file) {
		while (!file.eof()) {
			getline(file, ligne);
			addLineToTables(ligne, table1, table2, index);
			index++;
		}

		file.close();
	}
	else cout << path << " could not be opened." << endl;
}