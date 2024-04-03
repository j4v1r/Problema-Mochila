/*
Codigo_a.c
V 1.0 Abril 2024
Grupo: 2CM2
Autores: Colunga Aguilar Javier Alejandro
		
Programa que lee una cantidad "k" que representa el peso máximo de la mochila y un número "n"
de elementos de los que escoger para llenar hacer las cambinatorias posibles y llenar la 
mochila. Después, el programa lee en secuencia los pesos y valores "n" de cada objeto  en 
un arreglo dinámico. Finalmente, el programa regresa la máxima ganancia posible que puede 
haber sin sobrepasar el peso "k"

Compilación:
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
	
	//Recibir por argumento el tamaÃ±o de n y el valor a buscar
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
		
		//Leer de la entrada estandar los n valores y colocarlos en el arreglo de nÃºmeros
		for(i=0;i<=(2*n-1);i++){
			scanf("\n%d",&w[i]);
		}
		
		for(j=0;j<=(2*n-1);j++){
			printf("\n%d",w[j]);
		}
	
		//Llama al algoritmo de búsqueda exhaustiva
		int resul = mochila(peso, 0, n, w);
	
		printf("\nLa máxima ganancia posible es %d", resul);
	}
	
	return 0;
}

/*
float mochila(int peso,int indice, int objetos)

Recibe: int peso, peso actual disponible en la mochila
		int indice, indicador del objeto que se revisa en la función
		int objetos, cantidad total de objetos a considerar
		
Devuelve: float, beneficio máximo posible al comparar los dos posibles beneficios

Observaciones: Si la primera posición del arreglo es menor que la última se manda a llamar
la función "pivote" para obtener un número pivote ("j") que "divida" el arreglo en dos partes.
Después, se vuelve a llamar la función "rapido", enviando el arreglo, y la posición "p" como el 
inicio y "j-1" como el final para los números a la derecha del pivote y la posición "j+1" como 
el inicio y "r" como el final para los números a la izquierda del pivote. 
*/
int mochila(int peso, int i, int objetos, int *w){
	
	int ben1, ben2;
	
	/*Revisa que no se haya llegado al peso máximo de la mochila o que no se hayan
	revisado todos los elementos disponibles*/
	if(peso==0 || i==objetos-1){
		return 0;
	}
	
	printf("\nPeso es: %d", w[i]);
	printf("\nPeso mochila es: %d", peso);
	if(w[i]>peso){
		/*Si el peso del objeto actual sobrepasa el del peso disponible en la mochila 
		se vuelve a llamar la función aumentando el índice en uno para revisar el 
		siguiente objeto*/
		
		return mochila(peso, i+1, objetos, w); 
		
	}else{
		/*Si el peso del objeto actual NO sobrepasa el del peso disponible en la mochila 
		se determinan dos posibles valores de beneficio: "ben1" cuando se guarda el objeto
		y "ben2" cuando se descarta. 
		Para el primero caso se suma el valor del objeto actual más el valor que regrese 
		al volver a llamar a la función, aumentando el indice en 1.
		Para el segundo caso simplemente se vuelve a llamar la función tomando el valor
		que regrese al aumentar el indice en 1. */
		
		printf("\nValor es: %d", w[i+objetos]);
		ben1=w[i+objetos]+mochila(peso-w[i], i+1, objetos, w);
		printf("\nBen1 es: %d", ben1);
		ben2=mochila(peso, i+1, objetos, w);
		printf("\nBen2 es: %d", ben2);
		
		
		/*Finalmente, la función regresa el beneficio máximo posible*/	

		if(ben1>ben2){
			return ben1;
		}else{
			return ben2;
		}
	}
	
}



