#ifndef __HEROE_H__
#define __HEROE_H__

/**
    \file heroe.h
    \brief Módulo para tratar por separado al héroe.
*/

/**
    \brief TDA heroe
*/

typedef struct heroeRep * heroe;

/**
    \brief Crea un nuevo héroe con los datos que se pasan como parámetros.
    \param x Coordenada x de la esquina superior izquierda del dibujo del héroe.
    \param y Coordenada y de la esquina superior izquierda del dibujo del héroe.
    \param w Anchura del héroe.
    \param h Altura del héroe.
    \param vx Coordenada x del vector velocidad del héroe.
    \param vy Coordenada y del vector velocidad del héroe.
    \return Un héroe con los datos precisados.
*/

heroe crea_heroe ( double x, double y, double w, double h, double vx, double vy );

/**
    \brief Mueve el héroe que se pasa como parámetro.
    \param nuevo_heroe Héroe que se quiere mover.
*/

void mueve_heroe ( heroe nuevo_heroe );

/**
    \brief Dibuja el héroe que se pasa como parámetro.
    \param nuevo_heroe Héroe que se quiere dibujar.
*/

void dibuja_heroe ( heroe nuevo_heroe );

/**
    \brief Libera el espacio de memoria que ocupaba el héroe que se pasa como parámetro.
    \param h Héroe cuyo espacio de memoria se quiere liberar.
*/

void libera_heroe( heroe h );

/**
    \brief Devuelve la coordenada x del héroe que se pasa como parámetro.
    \param h Héroe sobre el cual se quiere conocer la coordenada x.
    \return Devuelve la coordenada x del héroe que se pasa como parámetro.
*/

double get_x_heroe ( heroe h );

/**
    \brief Devuelve la coordenada y del héroe que se pasa como parámetro.
    \param h Héroe sobre el cual se quiere conocer la coordenada y.
    \return Devuelve la coordenada y del héroe que se pasa como parámetro.
*/

double get_y_heroe ( heroe h );

/**
    \brief Devuelve la anchura del héroe que se pasa como parámetro.
    \param h Héroe sobre el cual se quiere conocer la anchura.
    \return Devuelve la anchura del héroe que se pasa como parámetro.
*/

double get_w_heroe ( heroe h );

/**
    \brief Devuelve la altura del héroe que se pasa como parámetro.
    \param h Héroe sobre el cual se quiere conocer la altura.
    \return Devuelve la altura del héroe que se pasa como parámetro.
*/

double get_h_heroe ( heroe h );

#endif // __HEROE_H__
