#ifndef __RAFAGA_H__
#define __RAFAGA_H__

#include "bala.h"

/**
    \file rafaga.h
    \brief M�dulo para recopilar todas las funciones asociadas a una r�faga de balas.
*/

/**
    \brief TDA Rafaga
*/

typedef struct Nodo * Rafaga;

/**
    \brief Crea una nueva r�faga de balas vac�a.
*/

Rafaga crea_rafaga ();

/**
    \brief A�ade la bala b a la r�faga r.
    \param r R�faga a la que se a�ade la bala.
    \param b Bala que se a�ade a la r�faga.
*/

void inserta_rafaga( Rafaga r, Bala	b );

/**
    \brief Libera toda la memoria asociada a la r�faga r y las balas que contenga.
    \param r R�faga de la cu�l se quiere liberar la memoria que ocupa.
*/

void libera_rafaga(	Rafaga r );

/**
    \brief Mueve cada bala incluida en la r�faga r.
    \param r R�faga de la cu�l se quieren mover cada una de sus balas.
*/

void mueve_rafaga( Rafaga r );

/**
    \brief Dibuja cada bala incluida en la r�faga r.
    \param r R�faga de la cu�l se quieren dibujar cada una de sus balas.
*/

void dibuja_rafaga( Rafaga r );

/**
    \brief Calcula la cantidad de balas que hay en la r�faga r.
    \param r R�faga de la que se quiere c�lcular el n�mero de balas.
    \return Devuelve el n�mero de balas que hay en la r�faga.
*/

int longitud_rafaga( Rafaga r );

/**
    \brief Comprueba si alguna bala de la r�faga r impacta con el rect�ngulo con datos (x,y,w,h) pasados como par�metros.
    \param r R�faga que contiene cada una de las balas.
    \param x Coordenada x de la esquina superior izquierda del rect�ngulo.
    \param y Coordenada y de la esquina superior izquierda del rect�ngulo.
    \param w Anchura del rect�ngulo.
    \param h Altura del rect�ngulo.
    \return Devuelve 1 si el rect�ngulo colisiona con alguna de las balas de la r�faga. Devuelve 0 en caso contrario.
*/

int	colision_rafaga( Rafaga r, double x, double y, double w, double h );

#endif
