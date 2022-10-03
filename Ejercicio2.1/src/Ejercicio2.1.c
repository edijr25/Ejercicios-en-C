/*
 ============================================================================
 Name        : 1.c
 Author      : Edicilio Lopez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/* Ingresar 5 números enteros calcular y mostrar el promedio de los números.
   Probar la aplicación con distintos valores. */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int contador;
	int acumulador=0;
	int num;
	float prom;
	setbuf(stdout,NULL);

	for(contador=0 ;contador<5; contador++){
		printf ("Ingrese un numero: ");
		scanf ("%d", &num);
		acumulador = acumulador + num;
	}
	prom = acumulador / contador;

	printf("El promedio es %2f",prom);

	return EXIT_SUCCESS;
}
