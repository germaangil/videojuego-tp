#ifndef __COLISIONES_H__
#define __COLISIONES_H__

/**
    \file colisiones.h
    \brief Módulo para comprobar si ha habido colisiones entre objetos.
*/

/**
    \brief Comprueba si un punto (px,py) se encuentra dentro del rectángulo (x,y,w,h) que se pasan como parámetros.
    \param x Coordenada x de la esquina superior izquierda del rectángulo.
    \param y Coordenada y de la esquina superior izquierda del rectángulo.
    \param w Anchura del rectángulo.
    \param h Altura del rectángulo.
    \param px Coordenada x del punto.
    \param py Coordenada y del punto.
    \return Devuelve 1 si el punto está dentro del rectángulo. Devuelve 0 en caso contrario.
*/

int dentro_rectangulo( int x, int y, int w, int h, double px, double py );

/**
    \brief Calcula la distancia entre dos puntos.
    \param x1 Coordenada x del primer punto.
    \param y1 Coordenada y del primer punto.
    \param x2 Coordenada x del segundo punto.
    \param y2 Coordenada y del segundo punto.
    \return Devuelve la distancia entre los dos puntos.
*/

double distancia_punto_punto( double x1, double y1, double x2, double y2 );

/**
    \brief Comprueba si dos circunferencias cuyos datos se pasan como parámetros son secantes.
    \param x1 Coordenada x del centro de la primera circunferencia.
    \param y1 Coordenada y del centro de la primera circunferencia.
    \param r1 Radio de la primera circunferencia.
    \param x2 Coordenada x del centro de la primera circunferencia.
    \param y2 Coordenada y del centro de la primera circunferencia.
    \param r2 Radio de la segunda circunferencia.
    \return Devuelve 1 si las circunferencias se cortan. Devuelve 0 en caso contrario.
*/

int solape_circunferencias( int x1, int y1, int r1, int x2, int y2, int r2 );

/**
    \brief Comprueba si dos rectángulos cuyos datos se pasan como parámetros son secantes.
    \param x1 Coordenada x de la esquina superior izquierda del primer rectángulo.
    \param y1 Coordenada y de la esquina superior izquierda del primer rectángulo.
    \param w1 Anchura del primer rectángulo.
    \param h1 Altura del primer rectángulo.
    \param x2 Coordenada x de la esquina superior izquierda del segundo rectángulo.
    \param y2 Coordenada y de la esquina superior izquierda del segundo rectángulo.
    \param w2 Anchura del segundo rectángulo.
    \param h2 Altura del segundo rectángulo.
    \return Devuelve 1 si los rectángulos se cortan. Devuelve 0 en caso contrario.
*/

int solape_rectangulos( int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2 );

#endif // __COLISIONES_H__
