/*
 * Programme: main.cpp
 *
 * Projet: Travail de session
 * Auteurs: Emily Bernier et Étienne Ménard
 *
 * Création: 26 novembre 2019
 * Travail: Gestion d'inventaire
 *
 * Paramètres: Aucun
 * Résultat: Lis les fichiers d'achats, d'inventaire et de ventes, fais des fancy math et écris un fichier d'analyse comportant la date.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include "cleanIO.h"
#include "date.h"

using namespace std;

void addLineToTables(string ligne, double tableQnt[], string tableType[], int index);
double editQnt(string qnt, string tableType[], int index);
void addIngQnt(string ligne, double tableQnt[], int index);
void bigMac(double nbItem, double tableQntIng[]);
void beeseChurger(double nbItem, double tableQntIng[]);
void quartLivre(double nbItem, double tableQntIng[]);
void doubleQuartLivre(double nbItem, double tableQntIng[]);
void baconClub(double nbItem, double tableQntIng[]);

/* fonction: lancement du programme
 * param: int argc: nb paramètres recus de la ligne de commande
 * param: char ** argv: tableau contenant les parametres recus de ligne de commande
 * return: int: code d'erreur: 0 = aucune erreur
 */
void main (int argc, char **argv) {
	locale::global(locale{ "fr" });
	string today, hier;
	getDates(today, hier);
	cout << "Date d'aujourd'hui: " << today << endl << "Date d'hier: " << hier << endl << endl;

	string pathInventaire = "./files/Inventaires_" + hier + ".txt";
	string pathAchats = "./files/Achats_" + today + ".txt";
	string pathVentes = "./files/Ventes_" + today + ".txt";
	string pathAnalyse = "./files/Analyse_" + today + ".txt";
	ifstream fichierInventaire(pathInventaire);
	ifstream fichierAchats(pathAchats);
	ifstream fichierVentes(pathVentes);
	//ofstream fichierAnalyse(pathAnalyse); // not yet

	string ligne; int index;
	string tableNom[9] = { "Boeuf", "Pain" "Laitue", "Cheddar jaune", "Cheddar blanc", "Cornichons", "Oignons", "Tomate" "Sauce" };
	string tableType[9];
	double tableQntInv[9];
	double tableQntAcht[9];
	double tableQntIng[9] = { 0,0,0,0,0,0,0,0,0 };

	if (fichierInventaire) {
		index = 0;
		while (!fichierInventaire.eof()) {
			getline(fichierInventaire, ligne);
			addLineToTables(ligne, tableQntInv, tableNom, index);
			index++;
		}

		fichierInventaire.close();
	}
	else cout << pathInventaire << " could not be opened." << endl;

	if (fichierAchats) {
		index = 0;
		while (!fichierAchats.eof()) {
			getline(fichierAchats, ligne);
			addLineToTables(ligne, tableQntAcht, tableNom, index);
			index++;
		}

		fichierAchats.close();
	}
	else cout << pathAchats << " could not be opened." << endl;

	if (fichierVentes) {
		index = 0;
		while (!fichierVentes.eof()) {
			getline(fichierVentes, ligne);
			addIngQnt(ligne, tableQntIng, index);
			index++;
		}

		for (int i = 0; i < 9; i++) {
			cout << tableQntIng[i] << endl;
		}
		fichierVentes.close();
	}
	else cout << pathVentes << " could not be opened." << endl;


	cout << endl << "Programme par Étienne Ménard et Emily Bernier." << endl;
	system("PAUSE");
}

void addLineToTables(string ligne, double tableQnt[], string tableType[], int index) {
	string limiter = ";"; string temp;
	auto start = 0U;
	auto limit = ligne.find(limiter);

	temp = ligne.substr(start, limit - start);

	start = limit + limiter.length();
	limit = ligne.find(limiter, start);
	
	string qnt = ligne.substr(start, limit - start);

	start = limit + limiter.length();
	limit = ligne.find(limiter, start);

	tableType[index] = ligne.substr(start, limit - start);
	tableQnt[index] = editQnt(qnt, tableType, index);
}

double editQnt(string qnt, string tableType[9], int index) {
	double newQnt;
	newQnt = stod(qnt);

	if (tableType[index] == "kg") {
		newQnt *= 1000;
	}
	return newQnt;
}

void addIngQnt(string ligne, double tableQnt[], int index) {
	string limiter = ";"; string temp;
	double ventes; double nbItem;
	auto start = 0U; auto limit = ligne.find(limiter);

	temp = ligne.substr(start, limit - start);
	start = limit + limiter.length();
	limit = ligne.find(limiter, start);

	string qnt = ligne.substr(start, limit - start);
	ventes = stoi(qnt);
	
	switch (index) {
	case 0: // big mac
		nbItem = ceil(ventes / 5.23);
		bigMac(nbItem, tableQnt);
		break;

	case 1:
		nbItem = ceil(ventes / 2.62);
		beeseChurger(nbItem, tableQnt);
		break;

	case 2:
		nbItem = ceil(ventes / 4.96);
		quartLivre(nbItem, tableQnt);
		break;

	case 3:
		nbItem = ceil(ventes / 6.27);
		doubleQuartLivre(nbItem, tableQnt);
		break;

	case 4:
		nbItem = ceil(ventes / 5.88);
		baconClub(nbItem, tableQnt);
	default:
		break;
	}
}

void bigMac(double nbItem, double tableQntIng[]) {
	tableQntIng[0] += nbItem * 2 * 45.4;
	tableQntIng[1] += nbItem * 3;
	tableQntIng[2] += nbItem * 2;
	tableQntIng[3] += nbItem * 1;
	tableQntIng[5] += nbItem * 3;
	tableQntIng[6] += nbItem * 12;
	tableQntIng[8] += nbItem * 7;
}

void beeseChurger(double nbItem, double tableQntIng[]) {
	tableQntIng[0] += nbItem * 45.4;
	tableQntIng[1] += nbItem * 2;
	tableQntIng[3] += nbItem * 1;
	tableQntIng[5] += nbItem * 2;
	tableQntIng[6] += nbItem * 6;
}

void quartLivre(double nbItem, double tableQntIng[]) {
	tableQntIng[0] += nbItem * 113;
	tableQntIng[1] += nbItem * 2;
	tableQntIng[3] += nbItem * 1;
	tableQntIng[5] += nbItem * 3;
	tableQntIng[6] += nbItem * 12;
}

void doubleQuartLivre(double nbItem, double tableQntIng[]) {
	tableQntIng[0] += nbItem * 226;
	tableQntIng[1] += nbItem * 2;
	tableQntIng[3] += nbItem * 2;
	tableQntIng[5] += nbItem * 4;
	tableQntIng[6] += nbItem * 12;
}

void baconClub(double nbItem, double tableQntIng[]) {
	tableQntIng[0] += nbItem * 113;
	tableQntIng[1] += nbItem * 2;
	tableQntIng[2] += nbItem * 3;
	tableQntIng[4] += nbItem * 1;
	tableQntIng[5] += nbItem * 4;
	tableQntIng[7] += nbItem * 2;
	tableQntIng[8] += nbItem * 7;

}