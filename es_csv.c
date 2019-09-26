/* Author: Acchiardi Paolo
Date: 16/09/2019
Es: Creare un programma in linguaggio C che legga il file vgsales.csv e lo importi in un array di strutture.
Ogni riga contiene i campi separati da virgole, per cui può essere comodo creare una funzione split
che dalla riga letta ritorni la struttura valorizzata. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LUNGHEZZA_NOME 30
#define GIOCHI 16600
#define LUNGHEZZA_LINE 1024
// Rank,Name,Platform,Year,Genre,Publisher,NA_Sales,EU_Sales,JP_Sales,Other_Sales,Global_Sales

typedef struct c{
    int rank;
    char* name;
    char* platform;
    int year;
    char* genre;
    char* publisher;
    float na_sales;
    float eu_sales;
    float jp_sales;
    float other_sales;
    float global_sales;
}Videogame;

void caricastruttura(Videogame tab[], int dim);

int main(){
    Videogame tabella[GIOCHI];
    caricastruttura(tabella, GIOCHI);
}

void caricastruttura(Videogame tab[], int dim){
    FILE *fp;
    fp = fopen("vgsales.csv","r");
    int k; k=0;
    char line[LUNGHEZZA_LINE]; //cattura la linea del file a cui è posizionato fp
    if(fp == NULL){
        printf("\nNon esiste.");
    }
    else{
    while(fgets(line,LUNGHEZZA_LINE,fp)){ //strtok prende la riga di buffer e la salva in field fino alla prima virgola che incontra nel file (salva il numero del rank in questo caso)
              tab[k].rank = atoi(strtok(line, ",")); //counter è il contatore, data è il vettore di strutture, atoi trasforma un %s in %d//dalla seconda volta in poi strtok non ha più bisogno di sapere la riga, già la sa
              tab[k].name = strtok(NULL, ",");
              tab[k].platform = strtok(NULL, ",");
              tab[k].year = atoi(strtok(NULL, ","));
              tab[k].genre = strtok(NULL, ",");
              tab[k].publisher = strtok(NULL, ",");
              tab[k].na_sales = atof(strtok(NULL, ",")); //Atof trasforma %s in %f
              tab[k].eu_sales = atof(strtok(NULL, ","));
              tab[k].jp_sales = atof(strtok(NULL, ","));
              tab[k].other_sales = atof(strtok(NULL, ","));
              tab[k].global_sales = atof(strtok(NULL, ","));
              k++;
              }
    }

    fclose(fp);
}