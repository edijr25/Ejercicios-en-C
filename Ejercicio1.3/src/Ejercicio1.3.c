/*
 ============================================================================
 Name        : 3.c
 Author      : Edicilio Lopez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/* ingresar 3 números y mostrar el número del medio, sólo si existe.
  En caso de que no exista también informarlo.*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num1;
		int num2;
		int num3;
		setbuf(stdout,NULL);

		printf("Ingresar un numero: ");
		scanf("%d", &num1);

		printf("Ingresar un numero: ");
		scanf("%d", &num2);

		printf("Ingresar un numero: ");
		scanf("%d", &num3);

		if((num1>num2 && num1<num3) || (num1<num2 && num1>num3)){
		printf("El numero del medio es %d", num1);
			}
		else if((num2>num1 && num2<num3) || (num2<num1 && num2>num3)){
		printf("El numero del medio es %d", num2);

		}else if((num3>num2 && num3<num1) || (num3<num2 && num3>num1)){
			printf("El numero del medio es %d", num3);
		}else{
			printf("No existe numero del medio");
		}

	return EXIT_SUCCESS;
}
