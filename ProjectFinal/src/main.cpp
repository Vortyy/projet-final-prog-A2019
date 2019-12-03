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
 * R�sultat: Produit un fichier .txt
 */

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <locale>
#include "cleanIO.h"

using namespace std;

/* fonction: lancement du programme
 * param: int argc: nb param�tres recus de la ligne de commande
 * param: char ** argv: tableau contenant les parametres recus de ligne de commande
 * return: int: code d'erreur: 0 = aucune erreur
 */
void main (int argc, char **argv) {
	locale::global(locale{ "fr" });

	cout << "Programme par �tienne M�nard et Emily Bernier." << endl;

	system("PAUSE");
}
