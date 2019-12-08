/*
 * Programme: main.cpp
 *
 * Projet: Travail de session
 * Auteurs: Emily Bernier et �tienne M�nard
 *
 * Cr�ation: 26 novembre 2019
 * Travail: Gestion d'inventaire
 *
 * Param�tres: Aucun
 * R�sultat: Lis les fichiers d'achats, d'inventaire et de ventes, fais des fancy math et �cris un fichier d'analyse comportant la date.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include "cleanIO.h"
#include "date.h"

using namespace std;

/* fonction: lancement du programme
 * param: int argc: nb param�tres recus de la ligne de commande
 * param: char ** argv: tableau contenant les parametres recus de ligne de commande
 * return: int: code d'erreur: 0 = aucune erreur
 */
void main (int argc, char **argv) {
	locale::global(locale{ "fr" });
	string today, hier;

	getDates(today, hier);
	cout << today << endl;
	cout << hier << endl;

	cout << endl << "Programme par �tienne M�nard et Emily Bernier." << endl;

	system("PAUSE");
}