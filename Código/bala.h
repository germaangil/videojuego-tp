#ifndef __BALA_H__
#define __BALA_H__

/**
    \file bala.h
    \brief M�dulo para controlar por separado las acciones de una bala.
*/

/**
    \brief TDA Bala
*/

typedef struct BalaRep * Bala;

/**
    \brief Crea una nueva bala con los datos que se pasan como par�metros.
    \param x Coordenada x de la esquina superior izquierda del dibujo de la bala.
    \param y Coordenada y de la esquina superior izquierda del dibujo de la bala.
    \param vx Coordenada x del vector velocidad de la bala.
    \param vy Coordenada y del vector velocidad de la bala.
    \return Una bala con los datos precisados.
*/

Bala crea_bala ( double x, double y, double vx, double vy );

/**
    \brief Libera el espacio de memoria que ocupaba la bala que se pasa como par�metro.
    \param b Bala cuyo espacio de memoria se quiere liberar.
*/

void libera_bala( Bala b );

/**
    \brief Mueve la bala que se pasa como par�metro.
    \param b Bala que se quiere mover.
*/

void mueve_bala( Bala b );

/**
    \brief Dibuja la bala que se pasa como par�metro.
    \param b Bala que se quiere dibujar.
*/

void dibuja_bala( Bala b );

/**
    \brief Devuelve la coordenada x de la bala que se pasa como par�metro.
    \param b Bala sobre la cual se quiere conocer la coordenada x.
    \return Devuelve la coordenada x de la bala que se pasa como par�metro.
*/

double get_x_bala ( Bala b );

/**
    \brief Devuelve la coordenada y de la bala que se pasa como par�metro.
    \param b Bala sobre la cual se quiere conocer la coordenada y.
    \return Devuelve la coordenada y de la bala que se pasa como par�metro.
*/

double get_y_bala ( Bala b );

/**
    \brief Comprueba si ha habido colisi�n entre la bala y el rect�ngulo con datos (x,y,w,h) que se pasan como par�metros.
    \param b Bala que se comprueba si ha impactado con el rect�ngulo.
    \param x Coordenada x de la esquina superior izquierda del rect�ngulo.
    \param y Coordenada y de la esquina superior izquierda del rect�ngulo.
    \param w Anchura del rect�ngulo.
    \param h Altura del rect�ngulo.
    \return Devuelve 1 si la bala ha impactado con el rect�ngulo. Devuelve 0 en caso contrario.
*/

int colision_bala( Bala b, double x, double y, double w, double h );

#endif // __BALA_H__
