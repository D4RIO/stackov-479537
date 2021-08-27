/**
 * Copiado del código publicado por el usuario Rinxs en
 * Stackoverflow en Español:
 *
 * https://es.stackoverflow.com/questions/479537/problema-con-variable-para-llamado-de-funcion
 */

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

void calcularHoja(char*** hojaInicial, int nfilas,int ncolumnas, int **hojaFinal)
{
	int fil,col,suma;
	char *celda;
	for(int i=0;i<nfilas;i++){
		for(int j=0;j<ncolumnas;j++){
			if(hojaInicial[i][j][0] != '='){
				hojaFinal[i][j]=atoi(hojaInicial[i][j]);
				cout<<hojaFinal[i][j]<<"\t";
			}
			else{
				suma=0;
				celda=strtok(hojaInicial[i][j],"+=");
				while(celda != NULL)
				{
					if((celda[0]>= 'A')&&(celda[0]<='Z')){
						col=int(celda[0])-65;
						celda++;
						fil=atoi(celda)-1;
						suma=suma+(hojaFinal[fil][col]);
						celda=strtok(NULL,"+=");
					}
					else{
						suma=suma+atoi(celda);
						celda=strtok(NULL,"+=");
					}
				}
				hojaFinal[i][j]=suma;
				cout<<hojaFinal[i][j]<<"\t";
			}
		}
		cout<<endl;
	}
}


int main(void)
{
	int nfilas, ncolumnas;
	char ***hojaInicial;
	int **hojaFinal;

	cout << "Ingrese cantidad de filas y columnas: ";
	cin >> nfilas >> ncolumnas;

	cin.ignore();

	for (int i = 0; i < nfilas; i++) {
		for (int j = 0; j < ncolumnas; j++) {
			cin.getline(hojaInicial[i][j], 10);
		}
	}

	hojaFinal = new int *[nfilas];
	cout << "Hoja final: \n\n";
	for (int i = 0; i < nfilas; i++) {
		hojaFinal[i] = new int[ncolumnas];
	}
	calcularHoja(hojaInicial,nfilas,ncolumnas,hojaFinal);
}

