/*
Codigo_a.c
V 1.0 Abril 2024
Grupo: 2CM2
Autores: Colunga Aguilar Javier Alejandro
		
Programa que lee una cantidad "k" que representa el peso m�ximo de la mochila y un n�mero "n"
de elementos de los que escoger para llenar hacer las cambinatorias posibles y llenar la 
mochila. Despu�s, el programa lee en secuencia los pesos y valores "n" de cada objeto  en 
un arreglo din�mico. Finalmente, el programa regresa la m�xima ganancia posible que puede 
haber sin sobrepasar el peso "k"

Compilaci�n:
En el script.bat: 				
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TRUE 1
#define FALSE 0
int mochila(int peso, int i, int objetos, int *w);

int main(int argc, char* argv[]){
	
	int i, j, peso=atoi(argv[1]), n=atoi(argv[2]);
	int* w, *v;
	
	//Recibir por argumento el tamaño de n y el valor a buscar
	if (argc!=3) 
	{
		printf("\nIndique el peso y la cantidad de objetos - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	} 
	
	w = malloc(n*sizeof(int));
	v = malloc(n*sizeof(int));
	
	
	if(w==NULL || v==NULL){
		
		printf("Ingrese una cantidad de objetos valida");
		
	}else{
		
		//Leer de la entrada estandar los n valores y colocarlos en el arreglo de números
		for(i=0;i<=(2*n-1);i++){
			scanf("\n%d",&w[i]);
		}
		
		for(j=0;j<=(2*n-1);j++){
			printf("\n%d",w[j]);
		}
	
		//Llama al algoritmo de b�squeda exhaustiva
		int resul = mochila(peso, 0, n, w);
	
		printf("\nLa m�xima ganancia posible es %d", resul);
	}
	
	return 0;
}

/*
float mochila(int peso,int indice, int objetos)

Recibe: int peso, peso actual disponible en la mochila
		int indice, indicador del objeto que se revisa en la funci�n
		int objetos, cantidad total de objetos a considerar
		
Devuelve: float, beneficio m�ximo posible al comparar los dos posibles beneficios

Observaciones: Si la primera posici�n del arreglo es menor que la �ltima se manda a llamar
la funci�n "pivote" para obtener un n�mero pivote ("j") que "divida" el arreglo en dos partes.
Despu�s, se vuelve a llamar la funci�n "rapido", enviando el arreglo, y la posici�n "p" como el 
inicio y "j-1" como el final para los n�meros a la derecha del pivote y la posici�n "j+1" como 
el inicio y "r" como el final para los n�meros a la izquierda del pivote. 
*/
int mochila(int peso, int i, int objetos, int *w){
	
	int ben1, ben2;
	
	/*Revisa que no se haya llegado al peso m�ximo de la mochila o que no se hayan
	revisado todos los elementos disponibles*/
	if(peso==0 || i==objetos-1){
		return 0;
	}
	
	printf("\nPeso es: %d", w[i]);
	printf("\nPeso mochila es: %d", peso);
	if(w[i]>peso){
		/*Si el peso del objeto actual sobrepasa el del peso disponible en la mochila 
		se vuelve a llamar la funci�n aumentando el �ndice en uno para revisar el 
		siguiente objeto*/
		
		return mochila(peso, i+1, objetos, w); 
		
	}else{
		/*Si el peso del objeto actual NO sobrepasa el del peso disponible en la mochila 
		se determinan dos posibles valores de beneficio: "ben1" cuando se guarda el objeto
		y "ben2" cuando se descarta. 
		Para el primero caso se suma el valor del objeto actual m�s el valor que regrese 
		al volver a llamar a la funci�n, aumentando el indice en 1.
		Para el segundo caso simplemente se vuelve a llamar la funci�n tomando el valor
		que regrese al aumentar el indice en 1. */
		
		printf("\nValor es: %d", w[i+objetos]);
		ben1=w[i+objetos]+mochila(peso-w[i], i+1, objetos, w);
		printf("\nBen1 es: %d", ben1);
		ben2=mochila(peso, i+1, objetos, w);
		printf("\nBen2 es: %d", ben2);
		
		
		/*Finalmente, la funci�n regresa el beneficio m�ximo posible*/	

		if(ben1>ben2){
			return ben1;
		}else{
			return ben2;
		}
	}
	
}



