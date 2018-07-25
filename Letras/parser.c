#include"Parser.h"
#include<string.h>
int parserRead(ArrayList* this)
{
    char letra[5];
    char nombre[50];
    char vocal[2];
    char consonante[2];


    int auxVocal,auxConsonante;

    eLetra* aux;
    int leidos;
    if(this!=NULL)
    {
        FILE* pFile;
        pFile=fopen("datos.csv","r");
        if(pFile!=NULL)
        {
            do
            {
                leidos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n",letra,nombre,vocal,consonante);
                if(leidos==4)
                {
                    aux=constructor();
                    if(aux!=NULL)
                    {
                        set_letra(aux,letra[0]);
                        set_name(aux,nombre);

                        auxVocal=isVocal(aux);
                        auxConsonante=isConsonante(aux);

                        set_vocal(aux,auxVocal);
                        set_consonante(aux,auxConsonante);
                        this->add(this,aux);
                    }
                }
            }
            while(!feof(pFile));
            printf("\nArchivo leido con exito\n");
            system("cls");
        }
        else
        {
            printf("\nArchivo no encontrado\n");
            system("cls");
        }
        fclose(pFile);
    }
}

int parserWrite(ArrayList* this)
{
    int i;
    eLetra* aux;
    FILE* pFile;
    pFile=fopen("info.csv","w");
    if(pFile!=NULL&&this!=NULL)
    {
        for(i=0; i<al_len(this); i++)
        {
            aux=this->get(this,i);
            if(aux!=NULL)
            {
                fprintf(pFile,"%c,%s,%d,%d\n",get_letra(aux),get_nombre(aux),get_vocal(aux),get_consonante(aux));
            }
        }
        printf("\nArchivo guardado con exito\n ");
    }
    fclose(pFile);
}
