/*
 ============================================================================
 Name        : 3.c
 Author      : Edicilio Lopez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*Debemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo de personas (no más de 100),
de cada persona debemos obtener los siguientes datos:
	Número de cliente,
	Estado civil ('s' para soltero", 'c' para casado o 'v' viudo),
	Edad( solo mayores de edad, más de 17),
	Temperatura corporal (validar por favor)
	Genero('f' para femenino, 'm' para masculino, 'o' para no binario).
NOTA: El precio por pasajero es de $600.
Se debe informar (solo si corresponde):
	a) La cantidad de personas con estado civil "viudo" de más de 60 años.
	b) El número de cliente y edad de la mujer soltera más joven.
	c) Cuánto sale el viaje total sin descuento.
	d) Si hay más del 50% de los pasajeros que tiene más de 60 años,
	el precio final tiene un descuento del 25%, que solo mostramos si corresponde.
*/

#include <stdio.h>
#include <stdlib.h>

#define PRECIO 600
#define DESCUENTO 25
#define LIMITE_PERSONAS 100

int main(void) {
	setbuf(stdout, NULL);
	int cantidadPersonas;
	int numeroCliente;
	int edad;
	int contadorViudos;
	int edadMujerMasJoven;
	int flagMujerMasJoven;
	int numeroClienteMujerMasJoven;
	int precioSinDescuento;
	int contadorPersonasMayores60;
	int contadorPersonasMenores60;
	char estadoCivil;
	char genero;
	char respuesta;
	float temperatura;
	float descuento;
	float precioConDescuento;
	cantidadPersonas = 0;
	numeroCliente = 0;
	contadorViudos = 0;
	flagMujerMasJoven = 0;
	precioSinDescuento = 0;
	contadorPersonasMayores60 = 0;
	contadorPersonasMenores60 = 0;
	do{
		numeroCliente++;
		printf("Numero de cliente: %d\n", numeroCliente);
		printf("Ingrese estado civil ('s' para soltero, 'c' para casado o 'v' viudo): ");
		scanf("%c", &estadoCivil);
		fflush(stdin);
		while(estadoCivil != 's' && estadoCivil != 'c' && estadoCivil != 'v'){
			printf("ERROR. Ingrese estado civil ('s' para soltero, 'c' para casado o 'v' viudo): ");
			scanf("%c", &estadoCivil);
			fflush(stdin);
		}
		printf("Ingrese edad (solo mayores de edad, más de 17): ");
		scanf("%d", &edad);
		fflush(stdin);
		while(edad <= 17 || edad > 110){
			printf("ERROR. Ingrese edad (solo mayores de edad, más de 17): ");
			scanf("%d", &edad);
			fflush(stdin);
		}
		printf("Ingrese temperatura corporal: ");
		scanf("%f", &temperatura);
		fflush(stdin);
		while(temperatura < 35 || temperatura > 41){
			printf("ERROR. Ingrese temperatura corporal: ");
			scanf("%f", &temperatura);
			fflush(stdin);
		}
		printf("Genero('f' para femenino, 'm' para masculino, 'o' para no binario): ");
		scanf("%c", &genero);
		fflush(stdin);
		while(genero != 'f' && genero != 'm' && genero != 'o'){
			printf("ERROR. Genero('f' para femenino, 'm' para masculino, 'o' para no binario): ");
			scanf("%c", &genero);
			fflush(stdin);
		}
		switch(estadoCivil){
			case 's':
				if(genero == 'f' && (flagMujerMasJoven == 0 || edad < edadMujerMasJoven)){
					edadMujerMasJoven = edad;
					numeroClienteMujerMasJoven = numeroCliente;
					flagMujerMasJoven = 1;
				}
				break;
			case 'c':
				break;
			case 'v':
				if(edad > 60){
					contadorViudos++;
				}
				break;
		}
		if(edad > 60){
			contadorPersonasMayores60++;
		}
		else{
			contadorPersonasMenores60++;
		}
		precioSinDescuento += PRECIO;
		cantidadPersonas++;
		printf("Ingresar otra persona (s/n): ");
		scanf("%c", &respuesta);
		fflush(stdin);
		printf("\n");
	}while(respuesta == 's' && cantidadPersonas < LIMITE_PERSONAS);
	if(cantidadPersonas == LIMITE_PERSONAS){
		printf("Limite de personas alcanzado (%d)\n", cantidadPersonas);
	}
	else{
		printf("Cantidad de personas en el viaje (%d)\n", cantidadPersonas);
	}
	printf("La cantidad de personas con estado civil viudo de más de 60 años: %d\n", contadorViudos);
	printf("Edad de la mujer soltera más joven: %d - Número de cliente: %d\n", edadMujerMasJoven, numeroClienteMujerMasJoven);
	printf("Precio viaje total sin descuento: $%d\n", precioSinDescuento);
	if(contadorPersonasMayores60 > contadorPersonasMenores60){
		descuento = (float)precioSinDescuento * DESCUENTO / 100;
		precioConDescuento = precioSinDescuento - descuento;
		printf("Descuento: $%.2f - Precio viaje total con descuento: $%.2f", descuento, precioConDescuento);
		}
	return 0;
}

