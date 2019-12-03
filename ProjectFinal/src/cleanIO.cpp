/*
 * cleanIO.cpp
 *
 *  Created on: 17 oct. 2019
 *      Author: �tienne
 */

#include "cleanIO.h"

/*
 *  Vides le buffer de cin.
 */
void cinClear() {
	cin.clear();
	cin.ignore();
}

/*
 *  V�rifies si le int entr� en param�tre est un int.
 *  param: int &positiveIntVar : Int � v�rifier
 */
void cinIntCheck(int &intVar) {
	while (cin.fail()) { //loop tant que le cin est corrompu
		cout << "Veuillez rentrer une valeur numerique: ";
		cinClear();
		cin >> intVar;
	}
}

/*
 *  V�rifies si le int entr� en param�tre est positif.
 *  param: int &intVar : Int � v�rifier
 */
void cinPositiveIntCheck(int &intVar) {
	cinIntCheck(intVar);
	while (intVar < 0) {
		cout << "Veuillez rentrer une valeur numerique positive: ";
		cinClear();
		cin >> intVar;
	}
}

/*
 *  V�rifies si le int entr� en param�tre est positif.
 *  param: int &intVar : Int � v�rifier
 *  param: int min : Valeur minimale � rentrer.
 *  param: int max : Valeur maximale � rentrer.
 */
void cinIntWithBoundsCheck(int &intVar, int min, int max) {
	cinIntCheck(intVar);
	while (intVar < min || intVar > max) {
		cout << "Veuillez rentrer une valeur numerique entre " << min << " et " << max << ": ";
		cinClear();
		cin >> intVar;
	}
}

/*
 *  V�rifies si le int entr� en param�tre est un int.
 *  param: int &intVar : Int � v�rifier
 */
void askInt(string message, int &intVar) {
	cout << message;
	cin >> intVar;
	cinIntCheck(intVar);
	cinClear();
}

/*
 *  Demandes un int positif � l'utilisateur.
 *  param: string question : La question � poser � l'utilisateur.
 *  param: int &intVar : Le param�tre dans lequel la r�ponse de l'utilisateur sera enregistr�e.
 */
void askPositiveInt(string message, int &intVar) {
	cout << message;
	cin >> intVar;
	cinPositiveIntCheck(intVar);
	cinClear();
}

/*
 *  Demandes un int entre les bornes d�finies � l'utilisateur.
 *  param: string question : La question � poser � l'utilisateur.
 *  param: int &intVar : Le param�tre dans lequel la r�ponse de l'utilisateur sera enregistr�e.
 *  param: int min : Valeur minimale � rentrer.
 *  param: int max : Valeur maximale � rentrer.
 */
void askIntWithBounds(string message, int &intVar, int min, int max) {
	cout << message;
	cin >> intVar;
	cinIntWithBoundsCheck(intVar, min, max);
	cinClear();
}

/*
 *  Demandes un double � l'utilisateur.
 *  param: string question : La question � poser � l'utilisateur.
 *  param: double &doubleVar : Le param�tre dans lequel la r�ponse de l'utilisateur sera enregistr�e.
 */
void askDouble(string message, double &doubleVar) {
	cout << message;
	cin >> doubleVar;
}

/*
 *  V�rifies si le int entr� en param�tre est un int.
 *  param: int &positiveIntVar : Int � v�rifier
 */
void cinDoubleCheck(int &doubleVar) {
	while (cin.fail()) { //loop tant que le cin est corrompu
		cout << "Veuillez rentrer une valeur numerique: ";
		cinClear();
		cin >> doubleVar;
	}
}

/*
 *  V�rifies si le double entr� en param�tre est positif.
 *  param: int &intVar : Int � v�rifier
 */
void cinPositiveDoubleCheck(int &doubleVar) {
	cinDoubleCheck(doubleVar);
	while (doubleVar < 0) {
		cout << "Veuillez rentrer une valeur numerique positive: ";
		cinClear();
		cin >> doubleVar;
	}
}

/*
 *  Demandes un string � l'utilisateur.
 *  param: string question : La question � poser � l'utilisateur.
 *  param: string &stringVar : Le param�tre dans lequel la r�ponse de l'utilisateur sera enregistr�e.
 */
void askString(string message, string &stringVar) {
	cout << message;
	cin >> stringVar;
}
