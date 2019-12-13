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
#include <string>
#include <locale>
#include "cleanIO.h"
#include "date.h"
#include "fileSorcery.h"
#include "tableMagic.h"
#include "beeseChurger.h"

using namespace std;

/* fonction: lancement du programme
 * param: int argc: nb paramètres recus de la ligne de commande
 * param: char ** argv: tableau contenant les parametres recus de ligne de commande
 * return: int: code d'erreur: 0 = aucune erreur
 */
void main(int argc, char **argv) {
	locale::global(locale{ "fr" });
	string today, hier;
	getDates(today, hier);

	string pathInventaire = "./files/Inventaires_" + hier + ".txt";
	string pathAchats = "./files/Achats_" + today + ".txt";
	string pathVentes = "./files/Ventes_" + today + ".txt";
	string pathAnalyse = "./files/Analyse_" + today + ".txt";

	string tableNom[9] = { "Boeuf", "Pain", "Laitue", "Cheddar jaune", "Cheddar blanc", "Cornichons", "Oignons", "Tomate", "Sauce" };
	string tableType[9];
	double tableQntInv[9];
	double tableQntAcht[9];
	double tableQntVentes[9] = { 0,0,0,0,0,0,0,0,0 };
	double tablePertes[9];
	double tableAnal[9];

	readFileTo2Tables(pathInventaire, tableQntInv, tableType);
	readFileTo2Tables(pathAchats, tableQntAcht, tableType);
	readFileToTable(pathVentes, tableQntVentes);

	calcPertes(tableQntInv, tableQntVentes, tablePertes);
	calcAnal(tableQntInv, tableQntAcht, tableQntVentes, tablePertes, tableAnal);
	
	writeAnal(pathAnalyse, tableNom, tableType, tableQntInv, tableQntAcht, tableQntVentes, tablePertes, tableAnal);


	cout << endl << "Programme par Étienne Ménard et Emily Bernier." << endl;
	system("PAUSE");
}


