#ifndef __ENEMIGO_H__
#define __ENEMIGO_H__

/**
    \file enemigo.h
    \brief Módulo para tratar por separado a un enemigo.
*/

/**
    \brief TDA enemigo
*/

typedef struct enemigoRep * enemigo;

/**
    \brief Crea un nuevo enemigo con los datos que se pasan como parámetros.
    \param x Coordenada x de la esquina superior izquierda del dibujo del enemigo.
    \param y Coordenada y de la esquina superior izquierda del dibujo del enemigo.
    \param w Anchura del enemigo.
    \param h Altura del enemigo.
    \param vx Coordenada x del vector velocidad del enemigo.
    \param vy Coordenada y del vector velocidad del enemigo.
    \return Un enemigo con los datos precisados.
*/

enemigo crea_enemigo( double x, double y, double w, double h, int vx, int vy );

/**
    \brief Mueve el enemigo que se pasa como parámetro.
    \param nuevo_enemigo Enemigo que se quiere mover.
*/

void mueve_enemigo ( enemigo nuevo_enemigo );

/**
    \brief Dibuja el enemigo que se pasa como parámetro.
    \param nuevo_enemigo Enemigo que se quiere dibujar.
*/

void dibuja_enemigo ( enemigo nuevo_enemigo );

/**
    \brief Libera el espacio de memoria que ocupaba el enemigo que se pasa como parámetro.
    \param e Enemigo cuyo espacio de memoria se quiere liberar.
*/

void libera_enemigo( enemigo e );

/**
    \brief Devuelve la coordenada x del enemigo que se pasa como parámetro.
    \param e Enemigo sobre el cual se quiere conocer la coordenada x.
    \return Devuelve la coordenada x del enemigo que se pasa como parámetro.
*/

double get_x_enemigo ( enemigo e );

/**
    \brief Devuelve la coordenada y del enemigo que se pasa como parámetro.
    \param e Enemigo sobre el cual se quiere conocer la coordenada y.
    \return Devuelve la coordenada y del enemigo que se pasa como parámetro.
*/

double get_y_enemigo ( enemigo e );

/**
    \brief Devuelve la anchura del enemigo que se pasa como parámetro.
    \param e Enemigo sobre el cual se quiere conocer la anchura.
    \return Devuelve la anchura del enemigo que se pasa como parámetro.
*/

double get_w_enemigo ( enemigo e );

/**
    \brief Devuelve la altura del enemigo que se pasa como parámetro.
    \param e Enemigo sobre el cual se quiere conocer la altura.
    \return Devuelve la altura del enemigo que se pasa como parámetro.
*/

double get_h_enemigo ( enemigo e );

#endif // __ENEMIGO_H__
