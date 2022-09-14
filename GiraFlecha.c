/*******************
COMPILACIÓN:    gcc GiraFlecha.c presentacionWin.c -o GiraFlecha
Ejecucion:      GiraFlecha.exe

Autor: Ericka Ruiz López --- Septiembre 2021

Versión: 1.0
*********************/

//Librerías
#include <stdio.h>
#include "presentacion.h"

//Definición de constantes
#define TAM 8 
#define TIEMPO_ESPERA 100

//Prototipo de funciones

void girar(int matriz[TAM][TAM], int tamMatriz, int numDesplazamientos, int fil, int col);  //Gira una matriz dada recursivamente
void mostrarMatriz(int matriz[TAM][TAM]);   //Muestra una matriz dada

//Función principal
void main (){
    //Declaración de matriz
    int matriz[TAM][TAM] = {
        0, 0, 0, 0, 0, 0, 1, 1,
        0, 0, 0, 0, 0, 1, 1, 0,
        1, 0, 0, 0, 1, 1, 0, 0,
        1, 0, 0, 1, 1, 0, 0, 0,
        1, 0, 1, 1, 0, 0, 0, 0,
        1, 1, 1, 0, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 0, 0
    };

    //Limpia la pantalla para la simulación
    BorrarPantalla();

    //Muestra el estado original de la matriz
    mostrarMatriz(matriz);
    EsperarMiliSeg(TIEMPO_ESPERA);

    //Gira la matriz 90 grados
    girar(matriz,TAM,7,0,0);
}

//** Definición de funciones **//

/*
Recibe: Referencia a una matriz cuadrada de tipo entero de tamaño TAM, tamaño de la matriz, número de desplazamientos a 
        realizar, fila y columna de inicio de giro.
Efecto: Gira la matriz dada a partir de la posición indicada realizando el número de desplazamientos indicado.
Devuelve: -
*/
void girar(int matriz[TAM][TAM], int tamMatriz, int numDesplazamientos, int fil, int col){
    //Llamada recursiva:
    //Se subdivide la matriz hasta el tamaño mínimo en el que se puede realizar un desplazamiento (caso base)
    if(tamMatriz > 2){
        girar(matriz, tamMatriz-2, numDesplazamientos-2, fil+1, col+1);
    }

    //Variables auxiliares
    int temp, i, j;

    //Mueve los elementos de la submatriz de acuerdo al número de desplazamientos indicado
    for(i=0;i<numDesplazamientos;i++){
        //Guarda de manera temporal el elemento de la posición de inicio de giro
        temp = matriz[fil][(col)];

        //Mueve una posición los elementos verticales izquierdos
        for(j=0;j<tamMatriz-1;j++){
            matriz[fil][col] = matriz[fil+1][col];
            fil++;
        }

        //Mueve una posición los elementos horizontales de la parte de abajo
        for(j=0;j<tamMatriz-1;j++){
            matriz[fil][col] = matriz[fil][col+1];
            col++;
        }

        //Mueve una posición los elementos verticales izquierdos
        for(j=0;j<tamMatriz-1;j++){
            matriz[fil][col] = matriz[fil-1][col];
            fil--;
        }

        //Mueve una posición los elementos horizontales de la parte de arriba
        for(j=0;j<tamMatriz-1;j++){
            matriz[fil][col] = matriz[fil][col-1];
            col--;
        }

        //Guarda el elemento temporal en la última posición
        matriz[fil][col+1] = temp;

        //Muestra el estado de la matriz
        mostrarMatriz(matriz);
    }

}

/*
Recibe: Referencia a una matriz cuadrada de tipo entero de tamaño TAM.
Efecto: Muestra la matriz indicada. 
Devuelve: -
*/
void mostrarMatriz(int matriz[TAM][TAM]){
    int i,j;

    for(i=0; i<TAM;i++){
        MoverCursor(1,i);
        for(j=0;j<TAM;j++){
            printf("%d  ", matriz[i][j]);
        }
        
    }

    EsperarMiliSeg(TIEMPO_ESPERA);
}