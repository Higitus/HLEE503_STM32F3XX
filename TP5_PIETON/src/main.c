/**
  ******************************************************************************
  * @file    main.c
  * @author  SIRANGAMA Matthieu
  * @version V1.0
  * @date    06-December-2016
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f3xx.h"
#include "stm32f3_discovery.h"

/*Private include*/
#include "main.h"

/*Initialisation variables externes*/
int count_v=0, etat_v=0, etat_feu=0;


int main(void)
{
	//Initialisation
	BSP_LED_Init(LED3); 	// Voie verticale up
	BSP_LED_Init(LED10); 	// Voie verticale down
	BSP_LED_Init(LED6); 	// voie horizontale left
	BSP_LED_Init(LED7); 	// Voie horizontale right
	BSP_PB_Init(BUTTON_USER,BUTTON_MODE_EXTI);

	if (SysTick_Config(SystemCoreClock / 10)) {
			BSP_LED_On(LED3); BSP_LED_On(LED10); BSP_LED_On(LED6); BSP_LED_On(LED7);//En cas d'erreur
			while(1);
	}
	while(1);
}

void gestion_etats(void){
	//fonction permetant la gestion des etat_v(oies) et etat_feu(x)
	/*Gestion etat*/
	if((etat_v==VHORIZ) && (etat_feu==VERT) && (count_v==tmp_vert_normal)){
			etat_feu=ORANGE;
			count_v=0;
	};
	if((etat_v==VVERTI) && (etat_feu==VERT) && (count_v==tmp_vert_normal)){
			etat_feu=ORANGE;
			count_v=0;
	};
	if((etat_v==VHORIZ) && (etat_feu==ORANGE) && (count_v==tmp_orange_normal)){
			etat_v=VVERTI;
			etat_feu=VERT;
			count_v=0;
	};
	if((etat_v==VVERTI) && (etat_feu==ORANGE) && (count_v==tmp_orange_normal)){
			etat_v=VHORIZ;
			etat_feu=VERT;
			count_v=0;
	};

	/*Gestion etat pieton*/
	if((etat_feu==VERT_PIETON) && (count_v>=tmp_vert_pieton)){
			etat_feu=ORANGE;
	};
}
void gestion_temps(void){
	//fonction permetant la gestion ininterompue des feux
	count_v++;
	gestion_etats();

	/*Gestion temps plein*/
	if((etat_v==VHORIZ) && (etat_feu==VERT) && (count_v<tmp_vert_normal)){
		BSP_LED_On(LED6);BSP_LED_On(LED7);
		BSP_LED_Off(LED3);BSP_LED_Off(LED10);
	};
	if((etat_v==VVERTI) && (etat_feu==VERT) && (count_v<tmp_vert_normal)){
		BSP_LED_On(LED3);BSP_LED_On(LED10);
		BSP_LED_Off(LED6);BSP_LED_Off(LED7);
	};
	if((etat_v==VHORIZ) && (etat_feu==ORANGE) && (count_v<tmp_orange_normal)){
		if(count_v%periode_2Hz==0){
			BSP_LED_Toggle(LED6);BSP_LED_Toggle(LED7);
			BSP_LED_Off(LED3);BSP_LED_Off(LED10);
		};
	};
	if((etat_v==VVERTI) && (etat_feu==ORANGE) && (count_v<tmp_orange_normal)){
		if(count_v%periode_2Hz==0){
			BSP_LED_Toggle(LED3);BSP_LED_Toggle(LED10);
			BSP_LED_Off(LED6);BSP_LED_Off(LED7);
		};
	};
	if((etat_v==VHORIZ) && (etat_feu==VERT_PIETON) && (count_v<tmp_vert_pieton)){
				BSP_LED_On(LED6);BSP_LED_On(LED7);
				BSP_LED_Off(LED3);BSP_LED_Off(LED10);
	};
	if((etat_v==VVERTI) && (etat_feu==VERT_PIETON) && (count_v<tmp_vert_pieton)){
				BSP_LED_On(LED3);BSP_LED_On(LED10);
				BSP_LED_Off(LED6);BSP_LED_Off(LED7);
	};
}

void gestion_pieton(void){
	//fonction permetant la gestion de la demande pieton
	if(etat_feu==VERT){
		etat_feu=VERT_PIETON;
	};
}
