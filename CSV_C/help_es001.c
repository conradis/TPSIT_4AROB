#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DELIM ","
#define NGAMES 16600    //numero di giochi massimi
#define NAME 30     //numero di caratterri per il nome del gioco
const char SEP = ','; //carattere separatore

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


main(){
    char forwhile[NAME];
    Game list[NGAMES];
    int k=0;
    FILE *fp;
    fp= fopen("vgsales.csv", "r");
    int ran,yea;
    char nam[NAME], platfor[NAME], genr[NAME], publishe[NAME];
    float NA, EU, JP, Other, Global;

    char line[NGAMES]; /* suppongo che le linee siano al piu' 80 caratteri */
    char *f1;

    while(fgets(fp, "s", line)!=NULL)
    {
        list[k].rank=(int)strtok(line, DELIM);
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
