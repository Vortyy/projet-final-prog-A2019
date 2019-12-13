/*
 * beeseChurger.h
 *
 *  Created on: 12 dec. 2019
 *      Author: Étienne
 */

using namespace std;

#ifndef SRC_BEESECHURGER_H_
#define SRC_BEESECHURGER_H_

/* fonction: Calcul la quantité d'ingredients necessaire pour faire un Big Mac
  * param: double nbItem: Le nombre de fois qu'on a vendu le produit
  * param: tableQntIng[]: Table dans lequel on met la quantité d'ingrédients utilisé pour chaque produit
  */
void bigMac(double nbItem, double tableQntIng[]);

/* fonction: Calcul la quantité d'ingredients necessaire pour faire un cheese burger
  * param: double nbItem: Le nombre de fois qu'on a vendu le produit
  * param: tableQntIng[]: Table dans lequel on met la quantité d'ingrédients utilisé pour chaque produit
  */
void beeseChurger(double nbItem, double tableQntIng[]);

/* fonction: Calcul la quantité d'ingredients necessaire pour faire un quart de livre
  * param: double nbItem: Le nombre de fois qu'on a vendu le produit
  * param: tableQntIng[]: Table dans lequel on met la quantité d'ingrédients utilisé pour chaque produit
  */
void quartLivre(double nbItem, double tableQntIng[]);

/* fonction: Calcul la quantité d'ingredients necessaire pour faire un double quart de livre
  * param: double nbItem: Le nombre de fois qu'on a vendu le produit
  * param: tableQntIng[]: Table dans lequel on met la quantité d'ingrédients utilisé pour chaque produit
  */
void doubleQuartLivre(double nbItem, double tableQntIng[]);

/* fonction: Calcul la quantité d'ingredients necessaire pour faire un bacon club
  * param: double nbItem: Le nombre de fois qu'on a vendu le produit
  * param: tableQntIng[]: Table dans lequel on met la quantité d'ingrédients utilisé pour chaque produit
  */
void baconClub(double nbItem, double tableQntIng[]);

#endif /* SRC_BEESECHURGER_H_ */