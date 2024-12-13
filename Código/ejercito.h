#ifndef __EJERCITO_H__
#define __EJERCITO_H__

#include "rafaga.h"

/**
    \file ejercito.h
    \brief Módulo para recopilar las funciones asociadas al TDA Ejercito.
*/

/**
    \brief TDA Ejercito
*/

typedef struct EjercitoRep * Ejercito;

/**
    \brief Crea un nuevo ejército de enemigos vacío.
*/

Ejercito crea_ejercito();

/**
    \brief Libera toda la memoria asociada al ejército e.
    \param e Ejercito del que se quiere liberar la memoria que ocupa.
*/

void libera_ejercito( Ejercito e );

/**
    \brief Crea un nuevo enemigo con datos (x,y,w,h) y lo añade al ejército e.
    \param e Ejército al que hay que añadir el nuevo enemigo.
    \param x Coordenada x de la esquina superior izquierda del nuevo enemigo.
    \param y Coordenada y de la esquina superior izquierda del nuevo enemigo.
    \param w Anchura del nuevo enemigo.
    \param w Altura del nuevo enemigo.
*/

void inserta_enemigo( Ejercito e, double x, double y, double w, double h );

/**
    \brief Mueve cada enemigo del ejército e.
    \param e Ejercito que se quiere mover.
*/

void mueve_ejercito( Ejercito e );

/**
    \brief Dibuja cada enemigo del ejército e.
    \param e Ejercito que se quiere dibujar.
*/

void dibuja_ejercito( Ejercito e );

/**
    \brief Comprueba si algún enemigo del ejército e impacta con el rectángulo con datos (x,y,w,h) pasados como parámetros.
    \param e Ejercito que contiene a cada uno de los enemigos.
    \param x Coordenada x de la esquina superior izquierda del rectángulo.
    \param y Coordenada y de la esquina superior izquierda del rectángulo.
    \param w Anchura del rectángulo.
    \param h Altura del rectángulo.
    \return Devuelve 1 si el rectángulo colisiona con alguno de los enemigos del ejército. Devuelve 0 en caso contrario.
*/

int colision_ejercito_objeto( Ejercito e, double x, double y, double w, double h );

/**
    \brief Comprueba si algún enemigo del ejército e impacta con la ráfaga r y, si es así, crea otro en otra posición.
    \param e Ejercito que contiene a cada uno de los enemigos.
    \param r Rafaga que contiene a cada una de las balas.
    \return Devuelve el número de enemigos que han colisionado con alguna bala de la ráfaga.
*/

int colision_ejercito_rafaga( Ejercito e, Rafaga r );

/**
    \brief Devuelve el tope del ejército que se pasa como parámetro.
    \param e Ejercito sobre el cual se quiere conocer el tope.
    \return Devuelve el tope del ejército que se pasa como parámetro.
*/

int get_tope_ejercito ( Ejercito e );

#endif
