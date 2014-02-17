#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 10000 //usado para calcular la cantidad de votos
#define MIN 10

typedef struct{
int nAgrup;
int distrito;
int region;
}t_datoBinario;

typedef struct aux{
    t_datoBinario reg;
    struct aux *psig;

}

void generarVotaciones(FILE *pf,char* nombre, char*modo);

int main()
{
    FILE *archivoBinario=NULL;
    char *nombres[]={"AB","BE","CE","DE","PEPE","PEPITO","PEPAZO","BOCA","RIVER","SAN LORENZO","ALBERT","TESLA","JACKOUBREY","YO","TU","EL",
                     "NOSOTROS","VOSOTROS","ELLOS","USTED","MIO","TUYO","FACTURAS","CON","CREMA"}; //el numero de agrupacion va del 0 al 24
    generarVotaciones(archivoBinario,"agrupaciones.bin","wb");

    return 0;
}

void generarVotaciones(FILE *pf,char* nombre, char*modo){
    srand(time(NULL));
    pf=fopen(nombre,modo);
    if(!pf) return ;
        int i=0;
    int nRegion=0;
    int nDistrito=0;
    int nAgrup=0;
    t_datoBinario reg;
    while(i<MAX){
        nAgrup=(rand()%24);
         nRegion=(rand()%3)+1;
          nDistrito=(rand()%22)+1;
                reg.nAgrup=nAgrup;
                 reg.distrito=nDistrito;
                  reg.region=nRegion;
                    printf("Agrupacion:%d Distrito:%d Region:%d\n",reg.nAgrup,reg.distrito,reg.region);
                        fwrite(&reg,sizeof(t_datoBinario),1,pf);

        i++;

    }
    printf("%d",i);
    fclose(pf);


}

int leerPartidos(FILE *pf,char *nombre,char*modo,t_listaPartidos *pp){



}

int
