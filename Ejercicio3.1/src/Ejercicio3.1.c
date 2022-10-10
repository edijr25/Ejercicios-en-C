/*
 ============================================================================
 Name        : 1.c
 Author      : Edicilio Lopez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*Crear una función que muestre por pantalla el número flotante  que recibe como parámetro.*/
#include <stdio.h>
#include <stdlib.h>
void imprimirFlotante (float num){
	printf ("El numero que retorna es %.2f",num);

}

int main(void) {
	setbuf(stdout, NULL);
	float num;

	printf("Ingrese un numero: ");
	scanf("%f", &num);

	imprimirFlotante (num);
	return EXIT_SUCCESS;
}
