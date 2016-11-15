/**
  ******************************************************************************
  * @file    main.c
  * @author  SIRANGAMA
  * @version V1.1
  * @date    08-November-2016
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f3xx.h"
#include "stm32f3_discovery.h"
			



int find_maximum(char* , int);
int find_palindrome(char* , int);

int main() {
  //Int variables (32 bit)
  int size, location, maximum;
  int size_palindrome, yes_no;
  //Array of Unsigned 8 bit
  char array[]  = {3, 6, 3, 7, 12, 15, 1, 8, 256, 2, 763, 85};
  char array_palindrome[] ={'P','A','O'};

  //Compute size of the array
  size = sizeof(array)/sizeof(array[0]);
  size_palindrome=sizeof(array_palindrome)/sizeof(array_palindrome[0]);

  //Execute
  location = find_maximum(array, size-1);
  maximum  = array[location];
  yes_no = find_palindrome(array_palindrome, size_palindrome-1);

  //Show
  if (yes_no = 1){
	  BSP_LED_Init(LED4);
	  BSP_LED_On(LED4);
  };
  if (yes_no = 0){
	  BSP_LED_Init(LED7);
	  BSP_LED_On(LED7);
  };

  while(1);
}

int find_maximum(char *a, int n) {
  int c, max, index;
  max = a[0];
  index = 0;

  for (c = 1; c < n; c++) {
    if (a[c] > max) {
       index = c;
       max = a[c];
    }
  }
  return index;
}

int find_palindrome(char *a , int n) {
	int c, indice, index;
	indice=0;

	for(c = 0; c < n; c++) {
		if (a[c] == a[n-c]) {
			indice=indice+1;
		}
	}

	if (indice==n){
		index=1;
	}
	else {
		index=0;
	};
	return index;
}
