/*
 * fileSorcery.cpp
 *
 *  Created on: 12 dec. 2019
 *      Author: �tienne
 */

#include "fileSorcery.h"

 /*
  * fonction: Lit un fichier et envoit la ligne pour calculer la quantit� de produits avec addVntesQnt
  * param: path: le path du fichier
  * param: double table: le table avec les quantit�s
  */
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

/*
 * fonction: fonction qui lit des lignes d'un fichier et mets les donn�es dans table1 et table2
 * param: string path: le path du fichier � lire
 * param: double table1[]: table de double
 * param: string table2[]: table de string
 */
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
void writeAnal(string path, string tableNom[], string tableType[], double tableInv[], double tableAchat[], double tableVentes[], double tablePertes[], double tableAnal[]) {
	ofstream file(path.c_str());
	deKiloGraphy(tableType);
	
	if (file) {
		file << setw(16) << left << "" << setw(18) << "Quantit� au" << setw(18) << "Quantit�" << setw(18) << "Quantit�" << setw(18) << "Quantit�" << setw(18) << "Quantit� �" << endl;
		file << setw(16) << left << "" << setw(18) << "d�but" << setw(18) << "achet�e" << setw(18) << "utilis�e" << setw(18) << "perdue" << setw(18) << "la fin" << endl << endl;
		for (int i = 0; i < 9; i++) {
			file << setw(16) << left << tableNom[i] << setw(8) << tableInv[i] << setw(10) << tableType[i] << setw(8) << tableAchat[i] << setw(10) << tableType[i] << setw(8) << tableVentes[i] << setw(10) << tableType[i] << setw(8) << tablePertes[i] << setw(10) << tableType[i] << setw(8) << tableAnal[i] << setw(10) << tableType[i] << endl;
		}
		
		cout << path << " has been created." << endl;
		file.close();
	}
	else cout << path << " could not be opened." << endl;
}