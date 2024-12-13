#include "bala.h"
#include "Pantalla.h"
#include <stdlib.h>

struct BalaRep{
    double x ;
    double y ;
    double w ;
    double h ;
    double vx ;
    double vy ;
    Imagen bala_img ;
};

Bala crea_bala ( double x, double y, double vx, double vy ){
    Bala nueva = malloc( sizeof( struct BalaRep ) );
    nueva->x = x;
    nueva->y = y;
    nueva->vx = vx;
    nueva->vy = vy;
    nueva->w = 15;
    nueva->h = 15;
    nueva->bala_img = Pantalla_ImagenLee("bola_fuego.bmp", 1);
    return nueva;
}

void libera_bala( Bala b ){
    Pantalla_ImagenLibera( b->bala_img );
    free( b );
}

void mueve_bala( Bala b )
{
        b->x = b->x + b->vx;
        b->y = b->y + b->vy;
}

void dibuja_bala( Bala b ){
    Pantalla_DibujaImagen( b->bala_img, b->x, b->y, b->w, b->h );
}

double get_x_bala ( Bala b ){
    return b->x;
}

double get_y_bala ( Bala b ){
    return b->y;
}

int colision_bala( Bala b, double x, double y, double w, double h ){
    return b->x<x+w && b->x+b->w>x && b->y<y+h && b->y+b->h>y;
}
