#include <stdio.h>
#include <stdlib.h>
#define MAX 2500
#define MIN 10
#define RANDMAX 2500
#define RANDMIN 0
typedef struct{
int nAgrup;
char*nombreAgrup;
}t_datoSimple;

void grabarEnArchivo(FILE*pf,t_datoSimple *reg);
void abrirArchivo(FILE *pf,char* nombre, char*modo);

int main()
{   srand(time(NULL));
    FILE archivoBinario;
    char nombres[]={"AB","BE","CE","DE","PEPE","PEPITO","PEPAZO","BOCA","RIVER",
                    "SAN LORENZO","ALBERT","TESLA","JACK OUBREY","YO","TU","EL",
                    "NOSOTROS","VOSOTROS","ELLOS",
                    "USTED","MIO","TUYO","FACTURAS","CON","CREMA"}; //el numero de agrupacion va del 0 al 24
    abrirArchivo(pf,"agrupacioes.bin","wb");
    if(pf==NULL)return 0;
    int i=0;
    int num=0;
    t_datoSimple reg;
    while(i<=MAX){
        num=rand()%24;

        reg.nombre=nombres[num];
        reg.nAgrup=num;
        fwrite(&reg,sizeof(t_datoSimple),1,pf);

    }
    printf("Hello world!\n");
    return 0;
}
