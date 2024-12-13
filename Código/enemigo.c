#include "enemigo.h"
#include "pantalla.h"
#include <stdlib.h>

struct enemigoRep{
    double x;
    double y;
    double w;
    double h;
    int vx;
    int vy;
    Imagen ene_img;
};

enemigo crea_enemigo( double x, double y, double w, double h, int vx, int vy ){
        enemigo nuevo_enemigo = malloc( sizeof( struct enemigoRep ) );
        nuevo_enemigo->x = x;
        nuevo_enemigo->y = y;
        nuevo_enemigo->vx = vx;
        nuevo_enemigo->vy = vy;
        nuevo_enemigo->w = w;
        nuevo_enemigo->h = h;
        nuevo_enemigo->ene_img = Pantalla_ImagenLee("calamar.bmp", 1);
        return nuevo_enemigo;
}

void mueve_enemigo ( enemigo nuevo_enemigo ){
        if ( nuevo_enemigo->x > 600-nuevo_enemigo->w ){
            nuevo_enemigo->x = 600-nuevo_enemigo->w;
            nuevo_enemigo->vx = nuevo_enemigo->vx * -1;
        }

        if ( nuevo_enemigo->x < 0 ){
            nuevo_enemigo->x = 0;
            nuevo_enemigo->vx = nuevo_enemigo->vx * -1;
        }

        if ( nuevo_enemigo->y > 600 - nuevo_enemigo->h ){
            nuevo_enemigo->y = 600 - nuevo_enemigo->h;
            nuevo_enemigo->vy = nuevo_enemigo->vy * -1;
        }

        if ( nuevo_enemigo->y < 0 ){
            nuevo_enemigo->y = 0;
            nuevo_enemigo->vy = nuevo_enemigo->vy * -1;
        }
        nuevo_enemigo->x = nuevo_enemigo->x + nuevo_enemigo->vx;
        nuevo_enemigo->y = nuevo_enemigo->y + nuevo_enemigo->vy;
}

void dibuja_enemigo ( enemigo nuevo_enemigo ){
        Pantalla_DibujaImagen(nuevo_enemigo->ene_img, nuevo_enemigo->x, nuevo_enemigo->y, nuevo_enemigo->w, nuevo_enemigo->h);
}

void libera_enemigo( enemigo e ){
    Pantalla_ImagenLibera( e->ene_img );
    free( e );
}

double get_x_enemigo ( enemigo e ){
    return e->x;
}

double get_y_enemigo ( enemigo e ){
    return e->y;
}

double get_w_enemigo ( enemigo e ){
    return e->w;
}

double get_h_enemigo ( enemigo e ){
    return e->h;
}
