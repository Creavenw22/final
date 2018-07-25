#include "Builder.h"
#include<stdio.h>

eLetra* constructor()
{
    eLetra* aux;
    aux=(eLetra*)malloc(sizeof(eLetra));
    return aux;
}

void set_letra(eLetra* this, char letra)
{
    this->letra=letra;
}

void set_name(eLetra* this, char name[])
{
    strcpy(this->nombre,name);
}

void set_vocal(eLetra* this, int vocal)
{
    this->vocal=vocal;
}

void set_consonante(eLetra* this, int consonante)
{
    this->consonante=consonante;
}


char get_letra(eLetra* this)
{
    return this->letra;
}

char* get_nombre(eLetra* this)
{
    return this->nombre;
}

int get_vocal(eLetra* this)
{
    return this->vocal;
}

int get_consonante(eLetra* this)
{
    return this->consonante;
}

void printAll(ArrayList* this)
{
    int i;
    int len=this->len(this);
    eLetra* aux;
    printf("\nid\tletra\tNombre\t\t\tvocal\tconsonante\t");
    for(i=0;i<50;i++)
    {


        aux=this->get(this,i);
        if(aux!=NULL)
        {
            printf("\n%d\t",i);
            printOne(aux);
        }
    }
    printf("\n\n");
    system("pause");
    for(i=0;i<len;i++)
    {


        aux=this->get(this,i);
        if(aux!=NULL)
        {
            printf("\n%d\t",i);
            printOne(aux);
        }
    }

}
void printOne(eLetra* this)
{
    printf("%c\t%s",get_letra(this),get_nombre(this));
    if(strlen(get_nombre(this))<16)
    {
        printf("\t");
    }
    if(strlen(get_nombre(this))<8)
    {
        printf("\t");
    }

    if(get_vocal(this)==0)
    {
        printf("\tNO");
    }
    else if(get_vocal(this)==1)
    {
        printf("\tSI");
    }

    if(get_consonante(this)==0)
    {
        printf("\tNO");
    }
    else if(get_consonante(this)==1)
    {
        printf("\tSI");
    }

}

int isVocal(eLetra* this)
{
    int auxReturn=0;
    char letra=get_letra(this);
    if((letra < 'a' || letra > 'z') || (letra < 'A' || letra > 'Z'))
    {
        if(letra=='a'||letra=='e'||letra=='i'||letra=='o'||letra=='u'||letra=='A'||letra=='E'||letra=='I'||letra=='O'||letra=='U')
        {
            auxReturn=1;
        }
    }

    return auxReturn;
}

int isConsonante(eLetra* this)
{
    int auxReturn=0;
    char letra=get_letra(this);

    if((letra < 'a' || letra > 'z') || (letra < 'A' || letra > 'Z'))
    {
        if(letra!='a'&&letra!='e'&&letra!='i'&&letra!='o'&&letra!='u'&&letra!='A'&&letra!='E'&&letra!='I'&&letra!='O'&&letra!='U')
        {
            auxReturn=1;
        }
    }

    return auxReturn;
}


/*int funcionQueFiltra(void* elemento)
{
    if(get_edad((numeroNatural*)elemento)>30&&strcmp(get_profesion((numeroNatural*)elemento),"programador")==0)
    {
        return 1;
    }
}*/
