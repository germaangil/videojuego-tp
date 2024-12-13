#include "heroe.h"
#include "pantalla.h"
#include <stdlib.h>

struct heroeRep{
    double x;
    double y;
    double w;
    double h;
    double vx;
    double vy;
    Imagen her_img;
};

heroe crea_heroe ( double x, double y, double w, double h, double vx, double vy ){
        heroe nuevo_heroe = malloc( sizeof( struct heroeRep ) );

        nuevo_heroe->x = x;
        nuevo_heroe->y = y;
        nuevo_heroe->w = w;
        nuevo_heroe->h = h;
        nuevo_heroe->vx = vx;
        nuevo_heroe->vy = vy;
        nuevo_heroe->her_img = Pantalla_ImagenLee("tux.bmp", 1);
        return nuevo_heroe;
}

void mueve_heroe ( heroe nuevo_heroe ){

    if ( Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT) ){
            nuevo_heroe->x = nuevo_heroe->x + nuevo_heroe->vx;
        }
        if ( Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT) ){
            nuevo_heroe->x = nuevo_heroe->x - nuevo_heroe->vx;
        }

        if ( nuevo_heroe->x > 600-nuevo_heroe->w ){
            nuevo_heroe->x = 600-nuevo_heroe->w;
        }

        if ( nuevo_heroe->x < 0 ){
            nuevo_heroe->x = 0;
        }
}

void dibuja_heroe ( heroe nuevo_heroe ){
        Pantalla_DibujaImagen( nuevo_heroe->her_img, nuevo_heroe->x, nuevo_heroe->y, nuevo_heroe->w, nuevo_heroe->h);
}

void libera_heroe( heroe h ){
    Pantalla_ImagenLibera( h->her_img );
    free( h );
}

double get_x_heroe ( heroe h ){
    return h->x;
}

double get_y_heroe ( heroe h ){
    return h->y;
}

double get_w_heroe ( heroe h ){
    return h->w;
}

double get_h_heroe ( heroe h ){
    return h->h;
}
