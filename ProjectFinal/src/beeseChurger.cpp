/*
 * beeseChurger.cpp
 *
 *  Created on: 12 dec. 2019
 *      Author: Étienne
 */

#include "beeseChurger.h"

 /* fonction: Calcul la quantité d'ingredients necessaire pour faire un Big Mac
   * param: double nbItem: Le nombre de fois qu'on a vendu le produit
   * param: tableQntIng[]: Table dans lequel on met la quantité d'ingrédients utilisé pour chaque produit
   */
void bigMac(double nbItem, double tableQntIng[]) {
	tableQntIng[0] += nbItem * 2 * 45.4;
	tableQntIng[1] += nbItem * 3;
	tableQntIng[2] += nbItem * 2;
	tableQntIng[3] += nbItem * 1;
	tableQntIng[5] += nbItem * 3;
	tableQntIng[6] += nbItem * 12;
	tableQntIng[8] += nbItem * 7;
}

/* fonction: Calcul la quantité d'ingredients necessaire pour faire un cheese burger
  * param: double nbItem: Le nombre de fois qu'on a vendu le produit
  * param: tableQntIng[]: Table dans lequel on met la quantité d'ingrédients utilisé pour chaque produit
  */
void beeseChurger(double nbItem, double tableQntIng[]) {
	tableQntIng[0] += nbItem * 45.4;
	tableQntIng[1] += nbItem * 2;
	tableQntIng[3] += nbItem * 1;
	tableQntIng[5] += nbItem * 2;
	tableQntIng[6] += nbItem * 6;
}

/* fonction: Calcul la quantité d'ingredients necessaire pour faire un quart de livre
  * param: double nbItem: Le nombre de fois qu'on a vendu le produit
  * param: tableQntIng[]: Table dans lequel on met la quantité d'ingrédients utilisé pour chaque produit
  */
void quartLivre(double nbItem, double tableQntIng[]) {
	tableQntIng[0] += nbItem * 113;
	tableQntIng[1] += nbItem * 2;
	tableQntIng[3] += nbItem * 1;
	tableQntIng[5] += nbItem * 3;
	tableQntIng[6] += nbItem * 12;
}

/* fonction: Calcul la quantité d'ingredients necessaire pour faire un double quart de livre
  * param: double nbItem: Le nombre de fois qu'on a vendu le produit
  * param: tableQntIng[]: Table dans lequel on met la quantité d'ingrédients utilisé pour chaque produit
  */
void doubleQuartLivre(double nbItem, double tableQntIng[]) {
	tableQntIng[0] += nbItem * 226;
	tableQntIng[1] += nbItem * 2;
	tableQntIng[3] += nbItem * 2;
	tableQntIng[5] += nbItem * 4;
	tableQntIng[6] += nbItem * 12;
}

/* fonction: Calcul la quantité d'ingredients necessaire pour faire un bacon club
  * param: double nbItem: Le nombre de fois qu'on a vendu le produit
  * param: tableQntIng[]: Table dans lequel on met la quantité d'ingrédients utilisé pour chaque produit
  */
void baconClub(double nbItem, double tableQntIng[]) {
	tableQntIng[0] += nbItem * 113;
	tableQntIng[1] += nbItem * 2;
	tableQntIng[2] += nbItem * 3;
	tableQntIng[4] += nbItem * 1;
	tableQntIng[5] += nbItem * 4;
	tableQntIng[7] += nbItem * 2;
	tableQntIng[8] += nbItem * 7;
}