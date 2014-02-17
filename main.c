#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 2500
#define MIN 10
#define RANDMAX 2500
#define RANDMIN 0
typedef struct{
int nAgrup;
char*nombreAgrup;
}t_datoSimple;
 void grabarEnArchivo(FILE*pf,t_datoSimple *reg);

FILE* abrirArchivo(FILE *pf,char* nombre, char*modo);

int main()
{   srand(time(NULL));
    FILE *archivoBinario=NULL;
    char *nombres[]={"AB","BE","CE","DE","PEPE","PEPITO","PEPAZO","BOCA","RIVER",
                    "SAN LORENZO","ALBERT","TESLA","JACK OUBREY","YO","TU","EL",
                    "NOSOTROS","VOSOTROS","ELLOS",
                    "USTED","MIO","TUYO","FACTURAS","CON","CREMA"}; //el numero de agrupacion va del 0 al 24
    abrirArchivo(archivoBinario,"agrupaciones.bin","wb");
    if(archivoBinario==NULL)return 0;
    int i=0;
    int num=0;
    t_datoSimple reg;
    while(i<=MAX){
        num=rand()%24;
        strcpy(reg.nombreAgrup,nombres[num]);
        reg.nAgrup=num;
        fwrite(&reg,sizeof(t_datoSimple),1,archivoBinario);

    }
    printf("Hello world!\n");
    fclose(archivoBinario);
    return 0;
}

FILE* abrirArchivo(FILE *pf,char* nombre, char*modo){

    pf=fopen(nombre,modo);
    if(!pf) return NULL;
    return pf;

}
