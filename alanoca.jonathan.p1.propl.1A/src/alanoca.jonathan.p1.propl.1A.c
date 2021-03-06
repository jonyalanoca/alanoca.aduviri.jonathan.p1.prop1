
#include <stdio.h>
#include <stdlib.h>
#define TAM 5
typedef struct{
	int id;
	char procesador[20];
	char marca[20];
	float precio;
}eNotebook;
float aplicarDescuento(int precio);
int contarCaracteres(char letras[], char letra);
int ordenar(eNotebook notebooks,int tam);
int main(void) {
	setbuf(stdout,NULL);
	eNotebook notebooks[TAM]={
			{2000, "amd","IBM",50000,0},
			{2001, "intel","Samsung",70000,0},
			{2002, "amd","lenovo",40000,0},
			{2003, "intel","IBM",55000,0}

	};

	int precio=2000;
	char caracteres[20]={"hola mundo"};
	char letra='m';
	printf("%.2f\n",aplicarDescuento(precio));
	printf("%d\n",contarCaracteres(caracteres, letra));

	ordenar(notebooks,TAM);
	for(int i=0;i<TAM-1;i++){
		printf("%d %s %s %f",notebooks.id, notebooks.marca,notebooks.procesador, notebooks.precio);
	}
	return EXIT_SUCCESS;
}
int ordenar(eNotebook notebooks,int tam){
	int todoOk=0;
	{
		eNotebook aux;
		for(int i=0;i<tam-1;i++){
			for(int j=i+1;j<tam;j++){
				if(strcmp(notebooks[i].marca,notebooks[j].marca)>0){
					aux=notebooks[i];
					notebooks[i]=notebooks[j];
					notebooks[j]=aux;
				}
				else if(strcmp(notebooks[i].marca,notebooks[j].marca)==0){
					if (notebooks[i].precio> notebooks[j].precio){
						aux=notebooks[i];
						notebooks[i]=notebooks[j];
						notebooks[j]=aux;
					}

				}

			}
		}
		todoOk=1;
	}
	return todoOk;

}

float aplicarDescuento(int precio){
	float precioFinal;
	int descuento=5;
	precioFinal=precio-((float)descuento*precio/100);
	return precioFinal;
}
int contarCaracteres(char letras[], char letra){
	int cantidad=-1;
	if (letras!=NULL){
		int i=0;
		cantidad=0;
		while(letras[i]!='\0'){
			if (letras[i]==letra){
				cantidad++;
			}
			i++;
		}
	}

	return cantidad;
}
