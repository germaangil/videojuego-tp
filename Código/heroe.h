#ifndef __HEROE_H__
#define __HEROE_H__

/**
    \file heroe.h
    \brief M�dulo para tratar por separado al h�roe.
*/

/**
    \brief TDA heroe
*/

typedef struct heroeRep * heroe;

/**
    \brief Crea un nuevo h�roe con los datos que se pasan como par�metros.
    \param x Coordenada x de la esquina superior izquierda del dibujo del h�roe.
    \param y Coordenada y de la esquina superior izquierda del dibujo del h�roe.
    \param w Anchura del h�roe.
    \param h Altura del h�roe.
    \param vx Coordenada x del vector velocidad del h�roe.
    \param vy Coordenada y del vector velocidad del h�roe.
    \return Un h�roe con los datos precisados.
*/

heroe crea_heroe ( double x, double y, double w, double h, double vx, double vy );

/**
    \brief Mueve el h�roe que se pasa como par�metro.
    \param nuevo_heroe H�roe que se quiere mover.
*/

void mueve_heroe ( heroe nuevo_heroe );

/**
    \brief Dibuja el h�roe que se pasa como par�metro.
    \param nuevo_heroe H�roe que se quiere dibujar.
*/

void dibuja_heroe ( heroe nuevo_heroe );

/**
    \brief Libera el espacio de memoria que ocupaba el h�roe que se pasa como par�metro.
    \param h H�roe cuyo espacio de memoria se quiere liberar.
*/

void libera_heroe( heroe h );

/**
    \brief Devuelve la coordenada x del h�roe que se pasa como par�metro.
    \param h H�roe sobre el cual se quiere conocer la coordenada x.
    \return Devuelve la coordenada x del h�roe que se pasa como par�metro.
*/

double get_x_heroe ( heroe h );

/**
    \brief Devuelve la coordenada y del h�roe que se pasa como par�metro.
    \param h H�roe sobre el cual se quiere conocer la coordenada y.
    \return Devuelve la coordenada y del h�roe que se pasa como par�metro.
*/

double get_y_heroe ( heroe h );

/**
    \brief Devuelve la anchura del h�roe que se pasa como par�metro.
    \param h H�roe sobre el cual se quiere conocer la anchura.
    \return Devuelve la anchura del h�roe que se pasa como par�metro.
*/

double get_w_heroe ( heroe h );

/**
    \brief Devuelve la altura del h�roe que se pasa como par�metro.
    \param h H�roe sobre el cual se quiere conocer la altura.
    \return Devuelve la altura del h�roe que se pasa como par�metro.
*/

double get_h_heroe ( heroe h );

#endif // __HEROE_H__
