#include "pantalla.h"
#include "ejercito.h"
#include "enemigo.h"
#include "colisiones.h"
#include "rafaga.h"
#include <stdlib.h>
#define MAX 7
#define SIZE_MIN 50

struct EjercitoRep {
    enemigo datos[MAX];
    int tope;
};

Ejercito crea_ejercito() {
    Ejercito nuevo = malloc( sizeof( struct EjercitoRep ) );
    nuevo->tope = -1;
    return nuevo;
}

void libera_ejercito( Ejercito e ) {
    for( int i=0 ; i<=e->tope ; i++ ){
        libera_enemigo( e->datos[i] );
    }
    free( e );
}

void inserta_enemigo( Ejercito e, double x, double y, double w, double h ) {
    if( e->tope < MAX-1 ){
        e->tope = e->tope + 1;
        e->datos[e->tope] = crea_enemigo( x,y,w,h,-15+rand()%30,-15+rand()%30 );
    }
}

void mueve_ejercito( Ejercito e ){
    for( int i=0 ; i<=e->tope ; i++ ){
        mueve_enemigo ( e->datos[i] );
    }
}

void dibuja_ejercito( Ejercito e ){
    for( int i=0 ; i<=e->tope ; i++ ){
        dibuja_enemigo ( e->datos[i] );
    }
}

int colision_ejercito_objeto( Ejercito e, double x, double y, double w, double h ){
    for( int i=0 ; i<=e->tope ; i++ ){
        if ( solape_rectangulos( get_x_enemigo(e->datos[i]), get_y_enemigo(e->datos[i]), get_w_enemigo(e->datos[i]), get_h_enemigo(e->datos[i]), x, y, w, h ) == 1 ){
            return 1;
        }
    }
    return 0;
}

int colision_ejercito_rafaga( Ejercito e, Rafaga r ){
    Imagen explosion = Pantalla_ImagenLee("explosion.bmp", 1);
    int num_eliminados = 0;
    double size;
    double coordx;
    double coordy;
    for( int i=0 ; i<=e->tope ; i++ ){
        if ( colision_rafaga( r, get_x_enemigo(e->datos[i]), get_y_enemigo(e->datos[i]), get_w_enemigo(e->datos[i]), get_h_enemigo(e->datos[i]) ) == 1 ){
            coordx = get_x_enemigo(e->datos[i]);
            coordy = get_y_enemigo(e->datos[i]);
            size = get_w_enemigo(e->datos[i]);
            Pantalla_DibujaImagen( explosion, coordx, coordy, size, size );

            libera_enemigo(e->datos[i]);
            for( int j=i ; j<e->tope ; j++ ){
                e->datos[j] = e->datos[j+1];
            }
            e->tope = e->tope - 1;
            num_eliminados = num_eliminados + 1;

            if ( size >= SIZE_MIN && e->tope < MAX-2 ){
                inserta_enemigo( e, coordx-40, coordy, size/1.2, size/1.2 );
                inserta_enemigo( e, coordx+100, coordy, size/1.2, size/1.2 );
            }
        }

    }
    Pantalla_ImagenLibera( explosion );
    return num_eliminados;
}

int get_tope_ejercito( Ejercito e ){
    return e->tope;
}



