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

}t_nodoListaBinario;
typedef t_nodoListaBinario *t_listaBinario;

typedef struct{
char nombre[15];
int numeroPartido;
}t_datoTexto;

typedef struct aux2{
    t_datoTexto reg;
    struct aux2 *psig;

}t_nodoListaPartidos;
typedef t_nodoListaPartidos *t_listaPartidos;
void crearLista(t_listaPartidos *pp);
void generarVotaciones(FILE *pf,char* nombre, char*modo);
int  cargarPartidosEnLista(FILE* pf,t_listaPartidos *pp);
int  cargarNodoEnListaPartidos(t_listaPartidos *lista,t_datoTexto *pp);
void mostrarListapartidos(t_listaPartidos *pp);
//////////////////////////////////////////////////////////////////////
int main()
{   t_listaPartidos listaPartidos;
    FILE *archivoPartidos=NULL;
    crearLista(&listaPartidos);
    cargarPartidosEnLista(archivoPartidos,&listaPartidos);
    mostrarListapartidos(&listaPartidos);

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
                    //printf("Agrupacion:%d Distrito:%d Region:%d\n",reg.nAgrup,reg.distrito,reg.region);
                        fwrite(&reg,sizeof(t_datoBinario),1,pf);

        i++;

    }
    printf("%d",i);
    fclose(pf);


}


int cargarPartidosEnLista(FILE* archivoPartidos,t_listaPartidos *pp){
    t_nodoListaPartidos  *aux;

    char cad[25];
    char *cadAux;
    t_datoTexto dat;
    int cont=0;

    while(fgets(cad,sizeof(cad),archivoPartidos)){
        cadAux=cad;
        cadAux=strrchr(cad,'\n');
        *cadAux='\0';
        cadAux=strrchr(cad,'-');
        sscanf(cadAux+1,"%s",dat.nombre);
        *cadAux='\0';
        dat.numeroPartido=atoi(cad);
        aux=(t_nodoListaPartidos*)malloc(sizeof(t_nodoListaPartidos));
        cont ++;
        if(!aux) return cont;
        cargarNodoEnListaPartidos(pp,&dat);



    }
    return cont;

}
int cargarNodoEnListaPartidos(t_listaPartidos *pp, t_datoTexto *dat){
t_nodoListaPartidos *aux=malloc(sizeof(t_nodoListaPartidos));
if(!aux) return 0;
while(*pp){
    pp=&(*pp)->psig;

}
aux->reg=*dat;
(*pp)->psig=aux;
return 1;

}

void crearLista(t_listaPartidos *pp){
    *pp=NULL;
}
void mostrarListapartidos(t_listaPartidos *pp){
    while(*pp){
        printf("Partido %s Numero: %d\n",(*pp)->reg.nombre,(*pp)->reg.numeroPartido);
        pp=&(*pp)->psig;
    }


}


