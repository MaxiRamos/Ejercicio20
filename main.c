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
void vaciarListaPartidos(t_listaPartidos *pp);
//////////////////////////////////////////////////////////////////////
int main()
{   t_listaPartidos listaPartidos;
    FILE *archivoPartidos=NULL;
    archivoPartidos=fopen("partidos.txt","rt");
    if(!archivoPartidos) {printf("no se puede abrir el archivo...");return 0;}
    crearLista(&listaPartidos);
    FILE *archivoBinario=NULL;
    cargarPartidosEnLista(archivoPartidos,&listaPartidos);
    mostrarListapartidos(&listaPartidos);

    char *nombres[]={"AB","BE","CE","DE","PEPE","PEPITO","PEPAZO","BOCA","RIVER","SAN LORENZO","HIMAN","POPEYE","JACKOUBREY","YO","TU","EL",
                     "NOSOTROS","VOSOTROS","ELLOS","USTED","MIO","TUYO","FACTURAS","CON","CREMA"}; //el numero de agrupacion va del 0 al 24
    //generarVotaciones(archivoBinario,"agrupaciones.bin","wb");
    vaciarListaPartidos(&listaPartidos);
    fclose(archivoPartidos);
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

                        fwrite(&reg,sizeof(t_datoBinario),1,pf);

        i++;

    }
      reg.nAgrup=9999; // a fines de testeo ingreso un registro con claves erroneas
                 reg.distrito=8888;
                  reg.region=7777;

                        fwrite(&reg,sizeof(t_datoBinario),1,pf);
    printf("%d Registros Guardados.",i);
    fclose(pf);


}


int cargarPartidosEnLista(FILE* archivoPartidos,t_listaPartidos *pp){
    t_nodoListaPartidos  *aux;

    char linea[20];
    char *cadAux;
    t_datoTexto dat;
    int cont=0;
    cadAux=fgets(linea,sizeof(linea),archivoPartidos);
    while(cadAux!=NULL){
        cadAux=strrchr(linea,'\n');
        //*cadAux='\0';
        cadAux=strrchr(linea,'-');
        sscanf(cadAux+1,"%s",dat.nombre);
        *cadAux='\0';
        dat.numeroPartido=atoi(linea);
        cont ++;
        cargarNodoEnListaPartidos(pp,&dat);
        cadAux=fgets(linea,sizeof(linea),archivoPartidos);



    }
    return cont;

}
int cargarNodoEnListaPartidos(t_listaPartidos *pp, t_datoTexto *dat){
while(*pp){
    pp=&(*pp)->psig;

}
*pp=(t_nodoListaPartidos*)malloc(sizeof(t_nodoListaPartidos));
if(!*pp) return 0;
(*pp)->reg=*dat;
(*pp)->psig=NULL;
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

void vaciarListaPartidos(t_listaPartidos *pp){
    t_nodoListaPartidos *aux;
    while (*pp){
    aux=*pp;
    pp=&(*pp)->psig;
    free(aux);
        }
    *pp=NULL;
    printf("lista vaciada exitosiamente...\n");

}


