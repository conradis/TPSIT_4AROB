#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DELIM ","
#define NGAMES 16600    //numero di giochi massimi
#define NAME 30     //numero di caratterri per il nome del gioco
const char SEP = ','; //carattere separatore

//definisco la struttura
    typedef struct game{
        int rank;
        char name[NAME];
        char platform[NAME];
        int year;
        char genre[NAME];
        char publisher[NAME];
        float NA_Sales;
        float EU_Sales;
        float JP_Sales;
        float Other_Sales;
        float Global_Sales;
    }Game;

//prototipi
void loadTabFromFile(char n[], Game list[]);

main(){
    //definizione di variabili
    char fileN[NAME] = "vgsales.csv";
    Game list[NGAMES];  //creo la tabella

    //carico la tabella da file
    loadTabFromFile(fileN,list);

}


void loadTabFromFile(char n[], Game list[]){
    char c;
    char forwhile[NAME];
    FILE *fp;
    int k=0;

    fp = fopen(n,"r");

    if(fp==NULL){
        printf("File %s inesistente\n" , n);
        getch();
    }else{
        while(fgets(fp, "s", list)!=NULL){
            list[k].rank=(int)strtok(list, DELIM);
            list[k].name[NAME]=(char)strtok(NULL, DELIM);
            list[k].platform[NAME]=(char)strtok(NULL, DELIM);
            list[k].year=(int)strtok(NULL, DELIM);
            list[k].genre[NAME]=(char)strtok(NULL, DELIM);
            list[k].publisher[NAME]=(char)strtok(NULL, DELIM);
            list[k].NA_Sales=(float)strtok(NULL, DELIM);
            list[k].EU_Sales=(float)strtok(NULL, DELIM);
            list[k].JP_Sales=(float)strtok(NULL, DELIM);
            list[k].Other_Sales=(float)strtok(NULL, DELIM);
            list[k].Global_Sales=(float)strtok(NULL, DELIM);
        }

    }

    fclose(fp);
}
