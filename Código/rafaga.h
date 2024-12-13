#ifndef __RAFAGA_H__
#define __RAFAGA_H__

#include "bala.h"

/**
    \file rafaga.h
    \brief Módulo para recopilar todas las funciones asociadas a una ráfaga de balas.
*/

/**
    \brief TDA Rafaga
*/

typedef struct Nodo * Rafaga;

/**
    \brief Crea una nueva ráfaga de balas vacía.
*/

Rafaga crea_rafaga ();

/**
    \brief Añade la bala b a la ráfaga r.
    \param r Ráfaga a la que se añade la bala.
    \param b Bala que se añade a la ráfaga.
*/

void inserta_rafaga( Rafaga r, Bala	b );

/**
    \brief Libera toda la memoria asociada a la ráfaga r y las balas que contenga.
    \param r Ráfaga de la cuál se quiere liberar la memoria que ocupa.
*/

void libera_rafaga(	Rafaga r );

/**
    \brief Mueve cada bala incluida en la ráfaga r.
    \param r Ráfaga de la cuál se quieren mover cada una de sus balas.
*/

void mueve_rafaga( Rafaga r );

/**
    \brief Dibuja cada bala incluida en la ráfaga r.
    \param r Ráfaga de la cuál se quieren dibujar cada una de sus balas.
*/

void dibuja_rafaga( Rafaga r );

/**
    \brief Calcula la cantidad de balas que hay en la ráfaga r.
    \param r Ráfaga de la que se quiere cálcular el número de balas.
    \return Devuelve el número de balas que hay en la ráfaga.
*/

int longitud_rafaga( Rafaga r );

/**
    \brief Comprueba si alguna bala de la ráfaga r impacta con el rectángulo con datos (x,y,w,h) pasados como parámetros.
    \param r Ráfaga que contiene cada una de las balas.
    \param x Coordenada x de la esquina superior izquierda del rectángulo.
    \param y Coordenada y de la esquina superior izquierda del rectángulo.
    \param w Anchura del rectángulo.
    \param h Altura del rectángulo.
    \return Devuelve 1 si el rectángulo colisiona con alguna de las balas de la ráfaga. Devuelve 0 en caso contrario.
*/

int	colision_rafaga( Rafaga r, double x, double y, double w, double h );

#endif
