#include "rafaga.h"
#include <stdlib.h>

struct Nodo{
    Bala dato;
    struct Nodo * sig;
};

Rafaga nuevo_nodo( Bala b ){
    Rafaga nuevo = malloc( sizeof( struct Nodo ) );
    nuevo->dato = b;
    nuevo->sig = NULL;
    return nuevo;
}

Rafaga crea_rafaga () {
    Rafaga cab = malloc ( sizeof( struct Nodo ) );
    cab->sig = NULL;
    return cab;
}

void inserta_rafaga( Rafaga r, Bala	b ){
    Rafaga nuevo = nuevo_nodo( b );
    nuevo->sig = r->sig;
    r->sig = nuevo;
}

void libera_rafaga(	Rafaga r ){
    while ( r->sig != NULL ){
        Rafaga borrar = r->sig;
        r->sig = borrar->sig;
        libera_bala( borrar->dato );
        free( borrar );
    }
    free ( r );
}

void mueve_rafaga( Rafaga r ){
    Rafaga aux = r;
    while ( aux->sig != NULL ){
        mueve_bala( aux->sig->dato );
        if( get_y_bala( aux->sig->dato ) < 0 ){
            Rafaga borrar = aux->sig;
            aux->sig = borrar->sig;
            libera_bala ( borrar->dato );
            free(borrar);
        }
        else{
            aux = aux->sig;
        }
    }
}

void dibuja_rafaga( Rafaga r ){
    Rafaga aux = r;
    while ( aux->sig != NULL ){
        dibuja_bala( aux->sig->dato );
        aux = aux->sig;
    }
}

int longitud_rafaga( Rafaga r ){
    Rafaga aux = r;
    int cont = 0;
    while ( aux->sig != NULL ){
        cont = cont + 1;
        aux = aux->sig;
    }
    return cont;
}

int	colision_rafaga( Rafaga r, double x, double y, double w, double h ){
    Rafaga aux = r;
    while ( aux->sig != NULL ){
        if ( colision_bala( aux->sig->dato, x, y, w, h ) == 1 ){
            Rafaga borrar = aux->sig;
            aux->sig = borrar->sig;
            libera_bala ( borrar->dato );
            free(borrar);
            return 1;
        }
        aux = aux->sig;
    }
    return 0;
}
