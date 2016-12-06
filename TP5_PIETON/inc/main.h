/*
 * main.h
 *
 *  Created on: 06-December-2016
 *      Author: SIRANGAMA Matthieu
 */

#ifndef MAIN_H_
#define MAIN_H_

/*Private include*/
#include "stm32f3xx.h"
#include "stm32f3_discovery.h"

/*Private define*/
#define tmp_vert_normal 600 	//en ds car SystemCoreClock / 10
#define tmp_orange_normal 150 	//en ds car SystemCoreClock / 10
#define tmp_vert_pieton 100 	//en ds car SystemCoreClock / 10
#define periode_2Hz 5			//en ds car SystemCoreClock / 10
#define VHORIZ 0
#define VVERTI 1
#define VERT 10
#define VERT_PIETON 11
#define ORANGE 12

/*Private fonctions*/
void gestion_temps(void);
void gestion_pieton(void);
void gestion_etats(void);

/*Private variable*/
extern int count_v, etat_v, etat_feu;

#endif /* MAIN_H_ */
