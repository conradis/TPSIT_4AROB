//Gabutti Irene
//file CSV
//strtok


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LUNG 200
#define RIGHE 16600
#define COLONNE 11

#define DELIM ","

typedef struct
{
    int Rank;
    char* Name;
    char* Platform;
    int Year;
    char* Genre;
    char* Publisher;
    float NA_Sales;
    float EU_Sales;
    float JP_Sales;
    float Other_Sales;
    float Global_Sales;
}Struttura;

int main()
{
    Struttura dati;
    int cont = 0;
    int i;
    FILE fp;
    char buffer[LUNG];
    char split[LUNG];
    fp = fopen("giochi.cvs","r");
    if(fp == NULL)
    {
        printf("Non esiste il file");
    }
    else
    {
        while(fgets(buffer,LUNG,fp))        //fino a quando ci sono rige nel file legge                                  
                                            //la funzione gets va fino a fine riga, prende anche gli spazi  
        {
            if(cont == 0)       //quando il contatore è uguale a 0 vado a stampare la prima riga in cui è contenuta la descizione dei vari campi (una sola volta all'inizio dell'esercizio)
            {
                split = strtok(buffer,",");
                printf("   s   ", split);
                split = strtok(NULL, ",");
                printf("   s   ", split);
                split = strtok(NULL, ",");
                printf("   s   ", split);
                split = strtok(NULL, ",");
                printf("   s   ", split);
                split = strtok(NULL, ",");
                printf("   s   ", split);
                split = strtok(NULL, ",");
                printf("   s   ", split);
                split = strtok(NULL, ",");
                printf("   s   ", split);
                split = strtok(NULL, ",");
                printf("   s   ", split);
                split = strtok(NULL, ",");
                printf("   s   ", split);
                split = strtok(NULL, ",");
                printf("   s   ", split);
                split = strtok(NULL, ",");
                printf("   s   ", split);
            }
            else if(cont != 0)
            {
                split = strtok(buffer,",");
                dati[cont].Rank = atoi(split);
                split = strtok(NULL, ",");
                dati[cont].Name = split;
                split = strtok(NULL, ",");
                dati[cont].Platform = split;
                split = strtok(NULL, ",");
                dati[cont].Year = atoi(split);
                split = strtok(NULL, ",");
                dati[cont].Genre = split;
                split = strtok(NULL, ",");
                dati[cont].Publisher = split;
                split = strtok(NULL, ",");
                dati[cont].EU_Sales = atof(split);
                split = strtok(NULL, ",");
                dati[cont].JP_Sales = atof(split);
                split = strtok(NULL, ",");
                dati[cont].Other_Sales = atof(split);
                split = strtok(NULL, ",");
                dati[cont].Global_Sales = atof(split);
            } 
        }      
        cont++;
        for(i=1; i<RIGHE; i++)
        {
            printf("%d %s %s %d %s %s %f %f %f %f %f", dati[i].Rank, dati[i].Name, dati[i].Platform, dati[i].Year, dati[i].Genre, dati[i].Platform, dati[i].NA_Sales, dati[i].EU_Sales, dati[i].JP_Sales, dati[i].Other_Sales, dati[i].Global_Sales);
            printf("\n");
        }
    }
    fclose(fp);
    
}