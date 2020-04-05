//Programa que calcula las operaciones básicas entre dos racionales y que los simplifica
//Versión 1.0
//Realizado por Jonathan Gómez
#include <stdio.h>
//Se declara la estructura "racional", la cual hace uso de dos variables que almacenan lo que su nombre dice.
struct racional{
int numerador;
int denominador;
};
//Se declaran las funciones que llevan a cabo la lectura, operaciones básicas, simplificación e impresión.
//Se usa un ciclo while para evitar que se den racionales con denominador == 0, puesto que estos no existen.
void leerNumerador(struct racional *,struct racional *);
void leerDenominador(struct racional *,struct racional *);
void sumarRacional(struct racional,struct racional, int resultados[][2]);
void restarRacional(struct racional,struct racional,int resultados[][2]);
void multiplicarRacional(struct racional,struct racional,int resultados[][2]);
void dividirRacional(struct racional,struct racional,int resultados[][2]);
void simplificarRacional(int resultados[][2],int);
void imprimirResultados(int resultados[][2]);

int main(){
 //Se declara la estructura "racional", la matriz resultados (la cual sirve para almacenar los numeradores y denominadores
 //de cada operación para hacer uso del mcd y simplificarlos, además de imprimirlos con la apariencia "a/b").
 struct racional r1, r2;
 int resultados[4][2];
 //Se incluyen todas las funciones a excepción de la simplificación, misma que es llamada durante cada función de
 //operación para efectuarse.
 leerNumerador(&r1,&r2);
 leerDenominador(&r1,&r2);
 sumarRacional(r1,r2,resultados);
 restarRacional(r1,r2,resultados);
 multiplicarRacional(r1,r2,resultados);
 dividirRacional(r1,r2,resultados);
 imprimirResultados(resultados);
 return 0;
}
//Lee los numeradores de cada racional y los almacena en la estructura mencionada anteriormente.
void leerNumerador(struct racional *r1,struct racional *r2){
 printf("Ingrese el NUMERADOR del RACIONAL 1: ");
 scanf("%d",&r1->numerador);
 printf("Ingrese el NUMERADOR del RACIONAL 2: ");
 scanf("%d",&r2->numerador);
}
//Lee los denominadores de cada racional y los almacena en la estructura mencionada anteriormente.
void leerDenominador(struct racional *r1,struct racional *r2){
 printf("Ingrese el DENOMINADOR del RACIONAL 1: ");
 scanf("%d",&r1->denominador);
 while(r1->denominador==0){
     printf("No existen DENOMINADORES iguales a 0, ingrese de nuevo\n");
     printf("Ingrese el DENOMINADOR del RACIONAL 1: ");
     scanf("%d",&r1->denominador); 
 }
 printf("Ingrese el DENOMINADOR del RACIONAL 2: ");
 scanf("%d",&r2->denominador);
 while(r2->denominador==0){
     printf("No existen DENOMINADORES iguales a 0, ingrese de nuevo\n");
     printf("Ingrese el DENOMINADOR del RACIONAL 2: ");
     scanf("%d",&r2->denominador);
 }
}
//Haciendo llamada a los valores leídos en las funciones anteriores, realiza la suma del racional 1 y 2, entonces
//almacena el numerador y denominador resultante en la matriz "resultados", posteriormente hace llamada a la simplificación.
void sumarRacional(struct racional r1,struct racional r2, int resultados[][2]){

 resultados[0][0]=r1.numerador*r2.denominador+r2.numerador*r1.denominador;
 resultados[0][1]=r1.denominador*r2.denominador;
 simplificarRacional(resultados,0);

}
//Haciendo llamada a los valores leídos en las funciones anteriores, realiza la resta del racional 1 y 2, entonces
//almacena el numerador y denominador resultante en la matriz "resultados", posteriormente hace llamada a la simplificación.
void restarRacional(struct racional r1, struct racional r2, int resultados[][2]){
 resultados[1][0]=r1.numerador*r2.denominador-r2.numerador*r1.denominador;
 resultados[1][1]=r1.denominador*r2.denominador;
 simplificarRacional(resultados,1);
}
//Haciendo llamada a los valores leídos en las funciones anteriores, realiza la multiplicación del racional 1 y 2, entonces
//almacena el numerador y denominador resultante en la matriz "resultados", posteriormente hace llamada a la simplificación.
void multiplicarRacional(struct racional r1, struct racional r2, int resultados[][2]){
 resultados[2][0]=r1.numerador*r2.numerador;
 resultados[2][1]=r1.denominador*r2.denominador;
 simplificarRacional(resultados,2);
}
//Haciendo llamada a los valores leídos en las funciones anteriores, realiza la división del racional 1 y 2, entonces
//almacena el numerador y denominador resultante en la matriz "resultados", posteriormente hace llamada a la simplificación.
void dividirRacional(struct racional r1, struct racional r2, int resultados[][2]){
 resultados[3][0]=r1.numerador*r2.denominador;
 resultados[3][1]=r1.denominador*r2.numerador;
 simplificarRacional(resultados,3);
}
//Haciendo uso del algoritmo de Euclides, se obtiene el MCD del numerador y denominador correspondientes con el apoyo
//de dos variables aux1 y aux2, mismas que almacenan temporalmente el valor de "resultados" para llevar a cabo el
//proceso antes mencionado, requiere de la posición de la función a simplificar.
void simplificarRacional(int resultados[][2],int posicion){
 if(resultados[posicion][0]!=0 & resultados[posicion][1]!=0){
     int aux1=resultados[posicion][0], aux2=resultados[posicion][1];

 while(aux1!=aux2){
     if (aux1>aux2){
         aux1=aux1-aux2;
     } else {
         aux2=aux2-aux1;
     }
}
 if(resultados[posicion][0]!=resultados[posicion][1]){
     resultados[posicion][0]=resultados[posicion][0]/aux1;
     resultados[posicion][1]=resultados[posicion][1]/aux1;
 }
 }

}
//Usando una serie de condiciones, las cuales cubren los posibles casos de salida y simplificación, imprime el resultado
//de cada operación básica en su forma más simplificada.
void imprimirResultados(int resultados[][2]){
    if(resultados[0][0]==resultados[0][1]){
        printf("El resultado de la SUMA es: 1\n");
    } else{
        if((resultados[0][0]>resultados[0][1]) & resultados[0][1]==1){
            printf("El resultado de la SUMA es: %d\n", resultados[0][0]);
        } else {
            if(resultados[0][0]==0){
                printf("El resultado de la SUMA es: 0\n");
            } else{
                printf("El resultado de la SUMA es: %d/%d\n",resultados[0][0],resultados[0][1]);
            }
        }
    }
    if(resultados[1][0]==resultados[1][1]){
        printf("El resultado de la RESTA es: 1\n");
    } else{
        if((resultados[1][0]>resultados[1][1]) & resultados[1][1]==1){
            printf("El resultado de la RESTA es: %d\n", resultados[1][0]);
        } else {
            if(resultados[1][0]==0){
                printf("El resultado de la RESTA es: 0\n");
            } else{
                printf("El resultado de la RESTA es: %d/%d\n",resultados[1][0],resultados[1][1]);
            }
        }
    }
    if(resultados[2][0]==resultados[2][1]){
        printf("El resultado de la MULTIPLICACION es: 1\n");
    } else{
        if((resultados[2][0]>resultados[2][1]) & resultados[2][1]==1){
            printf("El resultado de la MULTIPLICACION es: %d\n", resultados[2][0]);
        } else {
            if(resultados[2][0]==0){
                printf("El resultado de la MULTIPLICACION es: 0\n");
            } else{
                printf("El resultado de la MULTIPLICACION es: %d/%d\n",resultados[2][0],resultados[2][1]);
            }
        }
    }
    if(resultados[3][0]==resultados[3][1]){
        printf("El resultado de la DIVISION es: 1\n");
    } else{
        if((resultados[3][0]>resultados[3][1]) & resultados[3][1]==1){
            printf("El resultado de la DIVISION es: %d\n", resultados[3][0]);
        } else {
            if(resultados[3][0]==0){
                printf("El resultado de la DIVISION es: 0\n");
            } else{
                printf("El resultado de la DIVISION es: %d/%d\n",resultados[3][0],resultados[3][1]);
            }
        }
    }
}
