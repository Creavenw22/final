#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "Parser.h"

int getInt(char mensaje[], int enteroIngresado, int maximo, int minimo);
void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int esSoloLetras(char str[]);
int menu();

int main()
{
    ArrayList* letras;
    letras=al_newArrayList();
    int opcion;
    char respuesta='s';
    eLetra* aux;

    while(respuesta=='s')
    {
    opcion=menu();

    switch(opcion)
    {
    case 1:
        printf("\n---Lista de Letras---\n");
        parserRead(letras);
        printAll(letras);
        //parserWrite(letras);

        printf("\n\n---Presione una tecla para salir---\n");
        system("pause > nul");
        break;

    case 2:

        break;

    default:
        break;
    }

    }//cierre while

    return 0;
}


int getInt(char mensaje[], int enteroIngresado, int maximo, int minimo)
{
    do
    {
        printf("%s",mensaje);
        scanf("%d",&enteroIngresado);
    }
    while(enteroIngresado>maximo||enteroIngresado<minimo);
    return enteroIngresado;
}


int menu()
{
    int opcion;
    printf("\n1-Listar datos\n");
    printf("\n2-Ingresar nueva cadena\n");
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

ArrayList* nuevaCadena()
{
    ArrayList* nuevasLetras;
    ArrayList* nuevasNoLetras;
    nuevasLetras=al_newArrayList();
    nuevasNoLetras=al_newArrayList();
    eLetra* auxStruct;
    char* auxCadena;

    if(!getStringLetras("Ingrese una cadena de caracteres",auxCadena))
    {
        printf("La cadena contenia elementos que no eran letras");
    }
}
