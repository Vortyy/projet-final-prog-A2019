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

/* fonction: lancement du programme
 * param: int argc: nb paramètres recus de la ligne de commande
 * param: char ** argv: tableau contenant les parametres recus de ligne de commande
 * return: int: code d'erreur: 0 = aucune erreur
 */
void main (int argc, char **argv) {
	locale::global(locale{ "fr" });
	string today, hier;
	getDates(today, hier);
	cout << today << endl;
	cout << hier << endl;

	string pathInventaire = "./files/Inventaires_" + hier + ".txt";
	string pathAchats = "./files/Achats_" + today + ".txt";
	string pathVentes = "./files/Ventes_" + today + ".txt";
	string pathAnalyse = "./files/Analyse_" + today + ".txt";
	ifstream fichierInventaire(pathInventaire);
	ifstream fichierAchats(pathAchats);
	ifstream fichierVentes(pathVentes);
	ofstream fichierAnalyse(pathAnalyse);
	string ligne;

	if (fichierInventaire) {
		while (!fichierInventaire.eof())
		{
			getline(fichierInventaire, ligne);
			cout << ligne << endl;
		}

		fichierInventaire.close();
	}
	else cout << pathInventaire << " could not be opened." << endl;

	cout << endl << "Programme par Étienne Ménard et Emily Bernier." << endl;
	system("PAUSE");
}