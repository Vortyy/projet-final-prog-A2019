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

void addLineToTables(string ligne, double tableQnt[9], string tableType[9], int index);
double editQnt(string qnt, string tableType[9], int index);

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

	// stoi(string) => string to int
	// stod(string) => string to double

	cout << endl << "Programme par Étienne Ménard et Emily Bernier." << endl;
	system("PAUSE");
}

void addLineToTables(string ligne, double tableQnt[9], string tableType[9], int index) {
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
