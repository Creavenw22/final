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
ArrayList* nuevaCadena(ArrayList*this);

int main()
{
    ArrayList* letras;
    ArrayList* repetido;

    letras=al_newArrayList();
    repetido=al_newArrayList();
    int opcion;
    char respuesta='s';


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
        nuevaCadena(repetido);
        break;

    case 3:
        parserRead(repetido);
        printAll(repetido);
    default:
        break;
    }
        system("cls");
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
    printf("\n3-Mostrar cadena en array list\n");
    printf("\nIngrese una opcion: ");
    scanf("%d",&opcion);

    return opcion;
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

/*ArrayList* arrayRepetido(ArrayList*this)
{
    eLetra* auxStruct;

    char* auxCadena;
     if(!getStringLetras("\nIngrese una cadena de caracteres: ",auxCadena))
    {
        printf("La cadena contenia elementos que no eran letras");
    }


    auxStruct=al_filter(this,funcionQueFiltra());

    return auxStruct;

} */







ArrayList* nuevaCadena(ArrayList* this)
{
    eLetra* auxStruct;
    ArrayList* auxAL;
    auxAL=al_newArrayList();
    char auxCadena[20];
    int auxVocal;
    int auxConsonante;

    if(!getStringLetras("\nIngrese una cadena de caracteres: ",auxCadena))
    {
        printf("La cadena contenia elementos que no eran letras");
    }

    printf("\nCadena: %s\n",auxCadena);
    system("pause");
    for(int i=0;i<strlen(auxCadena);i++)
    {
        char letra;
        letra = auxCadena[i];

        auxStruct=constructor();

        set_letra(auxStruct,letra);
        set_name(auxStruct,"NULL");

        auxVocal=isVocal(auxStruct);
        auxConsonante=isConsonante(auxStruct);

        set_vocal(auxStruct,auxVocal);
        set_consonante(auxStruct,auxConsonante);

        for(int i=0;i<al_len(this);i++)
        {
            if(this->(pElements+i)->letra==auxStruct->letra)
            {
                al_add(auxStruct);
            }
        }


    }
}

