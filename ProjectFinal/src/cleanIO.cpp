/*
 * cleanIO.cpp
 *
 *  Created on: 17 oct. 2019
 *      Author: Étienne
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
 *  Vérifies si le int entré en paramètre est un int.
 *  param: int &positiveIntVar : Int à vérifier
 */
void cinIntCheck(int &intVar) {
	while (cin.fail()) { //loop tant que le cin est corrompu
		cout << "Veuillez rentrer une valeur numerique: ";
		cinClear();
		cin >> intVar;
	}
}

/*
 *  Vérifies si le int entré en paramètre est positif.
 *  param: int &intVar : Int à vérifier
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
 *  Vérifies si le int entré en paramètre est positif.
 *  param: int &intVar : Int à vérifier
 *  param: int min : Valeur minimale à rentrer.
 *  param: int max : Valeur maximale à rentrer.
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
 *  Vérifies si le int entré en paramètre est un int.
 *  param: int &intVar : Int à vérifier
 */
void askInt(string message, int &intVar) {
	cout << message;
	cin >> intVar;
	cinIntCheck(intVar);
	cinClear();
}

/*
 *  Demandes un int positif à l'utilisateur.
 *  param: string question : La question à poser à l'utilisateur.
 *  param: int &intVar : Le paramètre dans lequel la réponse de l'utilisateur sera enregistrée.
 */
void askPositiveInt(string message, int &intVar) {
	cout << message;
	cin >> intVar;
	cinPositiveIntCheck(intVar);
	cinClear();
}

/*
 *  Demandes un int entre les bornes définies à l'utilisateur.
 *  param: string question : La question à poser à l'utilisateur.
 *  param: int &intVar : Le paramètre dans lequel la réponse de l'utilisateur sera enregistrée.
 *  param: int min : Valeur minimale à rentrer.
 *  param: int max : Valeur maximale à rentrer.
 */
void askIntWithBounds(string message, int &intVar, int min, int max) {
	cout << message;
	cin >> intVar;
	cinIntWithBoundsCheck(intVar, min, max);
	cinClear();
}

/*
 *  Demandes un double à l'utilisateur.
 *  param: string question : La question à poser à l'utilisateur.
 *  param: double &doubleVar : Le paramètre dans lequel la réponse de l'utilisateur sera enregistrée.
 */
void askDouble(string message, double &doubleVar) {
	cout << message;
	cin >> doubleVar;
}

/*
 *  Vérifies si le int entré en paramètre est un int.
 *  param: int &positiveIntVar : Int à vérifier
 */
void cinDoubleCheck(int &doubleVar) {
	while (cin.fail()) { //loop tant que le cin est corrompu
		cout << "Veuillez rentrer une valeur numerique: ";
		cinClear();
		cin >> doubleVar;
	}
}

/*
 *  Vérifies si le double entré en paramètre est positif.
 *  param: int &intVar : Int à vérifier
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
 *  Demandes un string à l'utilisateur.
 *  param: string question : La question à poser à l'utilisateur.
 *  param: string &stringVar : Le paramètre dans lequel la réponse de l'utilisateur sera enregistrée.
 */
void askString(string message, string &stringVar) {
	cout << message;
	cin >> stringVar;
}
