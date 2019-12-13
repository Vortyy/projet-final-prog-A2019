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

void writeAnal(string path, string tableNom[], string tableType[], double tableInv[], double tableAchat[], double tableVentes[], double tablePertes[], double tableAnal[]) {
	ofstream file(path.c_str());
	deKiloGraphy(tableType);
	
	if (file) {
		file << setw(16) << left << "" << setw(18) << "Quantité au" << setw(18) << "Quantité" << setw(18) << "Quantité" << setw(18) << "Quantité" << setw(18) << "Quantité à" << endl;
		file << setw(16) << left << "" << setw(18) << "début" << setw(18) << "achetée" << setw(18) << "utilisée" << setw(18) << "perdue" << setw(18) << "la fin" << endl << endl;
		for (int i = 0; i < 9; i++) {
			file << setw(16) << left << tableNom[i] << setw(8) << tableInv[i] << setw(10) << tableType[i] << setw(8) << tableAchat[i] << setw(10) << tableType[i] << setw(8) << tableVentes[i] << setw(10) << tableType[i] << setw(8) << tablePertes[i] << setw(10) << tableType[i] << setw(8) << tableAnal[i] << setw(10) << tableType[i] << endl;
		}
		
		cout << path << " has been created." << endl;
		file.close();
	}
	else cout << path << " could not be opened." << endl;
	
}