#ifndef __EJERCITO_H__
#define __EJERCITO_H__

#include "rafaga.h"

/**
    \file ejercito.h
    \brief M�dulo para recopilar las funciones asociadas al TDA Ejercito.
*/

/**
    \brief TDA Ejercito
*/

typedef struct EjercitoRep * Ejercito;

/**
    \brief Crea un nuevo ej�rcito de enemigos vac�o.
*/

Ejercito crea_ejercito();

/**
    \brief Libera toda la memoria asociada al ej�rcito e.
    \param e Ejercito del que se quiere liberar la memoria que ocupa.
*/

void libera_ejercito( Ejercito e );

/**
    \brief Crea un nuevo enemigo con datos (x,y,w,h) y lo a�ade al ej�rcito e.
    \param e Ej�rcito al que hay que a�adir el nuevo enemigo.
    \param x Coordenada x de la esquina superior izquierda del nuevo enemigo.
    \param y Coordenada y de la esquina superior izquierda del nuevo enemigo.
    \param w Anchura del nuevo enemigo.
    \param w Altura del nuevo enemigo.
*/

void inserta_enemigo( Ejercito e, double x, double y, double w, double h );

/**
    \brief Mueve cada enemigo del ej�rcito e.
    \param e Ejercito que se quiere mover.
*/

void mueve_ejercito( Ejercito e );

/**
    \brief Dibuja cada enemigo del ej�rcito e.
    \param e Ejercito que se quiere dibujar.
*/

void dibuja_ejercito( Ejercito e );

/**
    \brief Comprueba si alg�n enemigo del ej�rcito e impacta con el rect�ngulo con datos (x,y,w,h) pasados como par�metros.
    \param e Ejercito que contiene a cada uno de los enemigos.
    \param x Coordenada x de la esquina superior izquierda del rect�ngulo.
    \param y Coordenada y de la esquina superior izquierda del rect�ngulo.
    \param w Anchura del rect�ngulo.
    \param h Altura del rect�ngulo.
    \return Devuelve 1 si el rect�ngulo colisiona con alguno de los enemigos del ej�rcito. Devuelve 0 en caso contrario.
*/

int colision_ejercito_objeto( Ejercito e, double x, double y, double w, double h );

/**
    \brief Comprueba si alg�n enemigo del ej�rcito e impacta con la r�faga r y, si es as�, crea otro en otra posici�n.
    \param e Ejercito que contiene a cada uno de los enemigos.
    \param r Rafaga que contiene a cada una de las balas.
    \return Devuelve el n�mero de enemigos que han colisionado con alguna bala de la r�faga.
*/

int colision_ejercito_rafaga( Ejercito e, Rafaga r );

/**
    \brief Devuelve el tope del ej�rcito que se pasa como par�metro.
    \param e Ejercito sobre el cual se quiere conocer el tope.
    \return Devuelve el tope del ej�rcito que se pasa como par�metro.
*/

int get_tope_ejercito ( Ejercito e );

#endif
