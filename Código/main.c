#include "Pantalla.h"
#include "ejercito.h"
#include "colisiones.h"
#include "heroe.h"
#include <stdlib.h>
#include <stdio.h>

/**
    \mainpage Videojuego

El juego contiene a un personaje principal, manejado por el usuario, que intentar� derribar a los enemigos
disparando balas.
Por cada enemigo que derribe, el personaje conseguir� un punto.
Si un enemigo colisiona con el personaje, el personaje perder� una vida, pero se volver� invulnerable por un tiempo.
El personaje puede quedarse sin balas para disparar. Estas se ir�n regenerando conforme desaparezcan de la pantalla.
*/

/**
    \file main.c
    \brief C�digo principal del programa.
*/

/**
    \brief Reproduce el men� del juego.
    \return 1 para salir del men�. Posteriormente, se acceder� a jugar().
    \return 2 para salir del men�. Posteriormente, se acceder� a ayuda().
    \return 3 para salir del men�. Posteriormente, finalizar� el programa.
*/

int menu(){

    int salida = 0;

    char string_jugar[7];
    char string_ayuda[7];
    char string_salir[7];
    double mouse_x;
    double mouse_y;

    while ( Pantalla_Activa() && salida == 0 ){

        Pantalla_DibujaRellenoFondo( 0, 128, 128, 255 );

        Pantalla_RatonCoordenadas( &mouse_x, &mouse_y );
        if( Pantalla_RatonBotonPulsado( SDL_BUTTON_LEFT )==1 && dentro_rectangulo( 225, 200, 150, 50, mouse_x, mouse_y )==1 ){
            salida = 1;
        }
        if(Pantalla_RatonBotonPulsado( SDL_BUTTON_LEFT )==1 && dentro_rectangulo( 225, 275, 150, 50, mouse_x, mouse_y )==1 ){
            salida = 2;
        }
        if(Pantalla_RatonBotonPulsado( SDL_BUTTON_LEFT )==1 && dentro_rectangulo( 225, 350, 150, 50, mouse_x, mouse_y )==1 ){
            salida = 3;
        }

        Pantalla_ColorRelleno( 255, 255, 255, 255 );
        Pantalla_DibujaRectangulo( 225, 200, 150, 50 );
        Pantalla_DibujaRectangulo( 225, 275, 150, 50 );
        Pantalla_DibujaRectangulo( 225, 350, 150, 50 );

        Pantalla_ColorTrazo( 0, 0, 0 , 255 );
        sprintf( string_jugar, "Jugar" );
        Pantalla_DibujaTexto( string_jugar, 280, 218 );

        sprintf( string_ayuda, "Ayuda" );
        Pantalla_DibujaTexto( string_ayuda, 280, 293 );

        sprintf( string_salir, "Salir" );
        Pantalla_DibujaTexto( string_salir, 280, 368 );

        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }
    return salida;
}

/**
    \brief Reproduce la pantalla de ayuda y muestra los controles y una breve explicaci�n del juego.
    \return 2 para volver al men�.
*/

int ayuda(){

    int salida = 2;

    Imagen imagen_ayuda = Pantalla_ImagenLee("ayuda.bmp", 1);
    Imagen aspa_blanca = Pantalla_ImagenLee("aspa_blanca.bmp", 1);
    Imagen aspa_roja = Pantalla_ImagenLee("aspa_roja.bmp", 1);
    double mouse_x;
    double mouse_y;

    while ( Pantalla_Activa() && salida == 2 ){

        Pantalla_DibujaRellenoFondo( 255, 255, 255, 255 );

        Pantalla_DibujaImagen( imagen_ayuda, 50, 50, 500, 500 );

        Pantalla_ColorTrazo( 205, 205, 205, 255 );
        Pantalla_ColorRelleno( 255, 255, 255 , 255 );
        Pantalla_DibujaRectangulo( 515, 110, 60, 30 );
        Pantalla_DibujaImagen( aspa_blanca, 495, 100, 100, 50 );

        Pantalla_RatonCoordenadas( &mouse_x, &mouse_y );
        if( dentro_rectangulo( 515, 110, 60, 30, mouse_x, mouse_y )==1 ){
            Pantalla_DibujaImagen( aspa_roja, 495, 100, 100, 50 );
            Pantalla_ColorTrazo( 255, 255, 255, 255 );
            Pantalla_ColorRelleno( 200, 0, 0 , 255 );
            Pantalla_DibujaRectangulo( 515, 110, 60, 30 );
            Pantalla_DibujaImagen( aspa_blanca, 495, 100, 100, 50 );
            if( Pantalla_RatonBotonPulsado( SDL_BUTTON_LEFT )==1 ){
                salida = 0;
            }
        }
        Pantalla_Actualiza();
        Pantalla_Espera(40);
   }

    Pantalla_ImagenLibera(aspa_roja);
    Pantalla_ImagenLibera(aspa_blanca);
    Pantalla_ImagenLibera(imagen_ayuda);

    return salida;
}

/**
    \brief Reproduce el juego en s�.
    \return 0 para volver al men�.
*/

int jugar(){

    int salida = 1;

    Ejercito e = crea_ejercito();
    heroe h = crea_heroe( 285, 540, 60, 60, 20, 0 );
    Rafaga rafaga = crea_rafaga();

    Imagen corazon1 = Pantalla_ImagenLee("vida.bmp", 1);
    Imagen corazon2 = Pantalla_ImagenLee("vida.bmp", 1);
    Imagen corazon3 = Pantalla_ImagenLee("vida.bmp", 1);
    Imagen icono_balas = Pantalla_ImagenLee("flor_fuego.bmp", 1);
    Imagen fondo_windows = Pantalla_ImagenLee("fondo_mario.bmp", 1);
    Imagen escudo = Pantalla_ImagenLee("escudo.bmp", 1);
    Imagen gafas = Pantalla_ImagenLee("gafas.bmp", 1);
    Imagen fuego = Pantalla_ImagenLee("fuego.bmp", 1);

    int puntos = 0;
    int vidas = 3;
    int meter_enemigo = 0;
    int invulnerabilidad = 0;
    int permiso_disparar = 0;
    char string_vidas[9];
    char string_score[11];
    char string_invulnerabilidad[27];
    char string_balas[11];

    while ( Pantalla_Activa() && salida == 1 ){
        Pantalla_DibujaImagen( fondo_windows, -40, 0, 640, 600 );

        Pantalla_DibujaImagen( corazon1, 545 , 45 , 35, 35 );
        if ( vidas > 1 ){
            Pantalla_DibujaImagen( corazon2, 515, 45 , 35, 35 );
        }
        if ( vidas > 2 ){
            Pantalla_DibujaImagen( corazon3, 485, 45 , 35, 35 );
        }

        Pantalla_ColorTrazo( 255, 0, 0, 255 );
        sprintf( string_vidas, "Vidas: %d", vidas );
        Pantalla_ColorTrazo( 255, 0, 0, 255 );
        Pantalla_ColorRelleno( 255, 255, 255, 255 );
        Pantalla_DibujaRectangulo( 502.5, 17.5, 77.5, 20 );
        Pantalla_DibujaTexto( string_vidas, 505, 20 );

        Pantalla_ColorTrazo( 0, 0, 0, 255 );
        sprintf( string_score, "Score: %d", puntos );
        Pantalla_DibujaTexto( string_score, 20, 15 );

        Pantalla_DibujaImagen( icono_balas, 10, 35, 30, 30 );
        Pantalla_ColorRelleno( 0, 0, 0, 0 );
        Pantalla_DibujaRectangulo( 42.5, 42.5, 80, 12.5 );
        Pantalla_ColorRelleno( 255, 206, 50, 255 );
        Pantalla_DibujaRectangulo( 42.5, 42.5, 80-10*(longitud_rafaga( rafaga )), 12.5 );
        if( longitud_rafaga( rafaga ) == 8 ){
            Pantalla_ColorRelleno( 255, 255, 255, 255 );
            Pantalla_ColorTrazo( 255, 206, 50, 255 );
            Pantalla_DibujaRectangulo( 265, 65, 90, 25 );
            sprintf( string_balas, "SIN BALAS" );
            Pantalla_DibujaTexto( string_balas, 270, 70 );
        }

        if( meter_enemigo == 0 ){
            inserta_enemigo( e, rand()%600, rand()%300, 60, 60 );
            meter_enemigo = 50;
        }

        dibuja_heroe( h );
        if( ( get_tope_ejercito( e ) == -1 && puntos != 0 ) || puntos >= 50 ){
            Pantalla_DibujaImagen( fuego,  get_x_heroe(h)+7.5, get_y_heroe(h)-10, 30, 30 );
            Pantalla_DibujaImagen( fuego,  get_x_heroe(h)+22.5, get_y_heroe(h)-10, 30, 30 );
        }
        if( invulnerabilidad > 0 ){
            Pantalla_DibujaImagen( gafas, get_x_heroe(h)+7.5, get_y_heroe(h)-5, 50, 25 );
        }
        mueve_heroe ( h );
        dibuja_ejercito( e );
        mueve_ejercito( e );

        if( Pantalla_TeclaPulsada( SDL_SCANCODE_SPACE ) && longitud_rafaga( rafaga ) < 8 && permiso_disparar == 0 ){
            inserta_rafaga( rafaga, crea_bala( get_x_heroe(h) + 20, get_y_heroe(h), 0, -10 ) );
            permiso_disparar = 3;
        }
        mueve_rafaga( rafaga );
        dibuja_rafaga( rafaga );

        puntos = puntos + colision_ejercito_rafaga( e, rafaga );

        if( colision_ejercito_objeto( e, get_x_heroe(h), get_y_heroe(h), get_w_heroe(h), get_h_heroe(h) ) == 1 && invulnerabilidad == 0 ){
            vidas = vidas - 1;
            invulnerabilidad = 50;
        }

        if( invulnerabilidad > 0 ){
            invulnerabilidad = invulnerabilidad - 1;

            Pantalla_DibujaImagen( escudo,  get_x_heroe(h)+10, get_y_heroe(h)+20, 40, 40 );

            sprintf( string_invulnerabilidad, "Invulnerabilidad activada" );
            Pantalla_ColorTrazo( 0, 0, 255, 255 );
            Pantalla_ColorRelleno( 255, 255, 255, 255 );
            Pantalla_DibujaRectangulo( 195, 25, 240, 25 );
            Pantalla_DibujaTexto( string_invulnerabilidad, 200, 30 );
        }

        if( meter_enemigo > 0 ){
            meter_enemigo = meter_enemigo - 1;
        }

        if( permiso_disparar > 0 ){
            permiso_disparar = permiso_disparar - 1;
        }
        Pantalla_Actualiza();
        Pantalla_Espera(40);

        if( vidas == 0 ){
            salida = 0;
        }
    }

    libera_rafaga ( rafaga );
    libera_heroe( h );
    libera_ejercito( e );
    Pantalla_ImagenLibera(fondo_windows);
    Pantalla_ImagenLibera(corazon1);
    Pantalla_ImagenLibera(corazon2);
    Pantalla_ImagenLibera(corazon3);
    Pantalla_ImagenLibera( icono_balas );
    Pantalla_ImagenLibera(fuego);
    Pantalla_ImagenLibera(gafas);
    Pantalla_ImagenLibera(escudo);

    FILE * fp = NULL;
        char record[10];
        int puntuacion_maxima;
        fp = fopen( "record.txt", "r" );
        if( fp == NULL ){
            printf(	"El	fichero	record.txt	no	existe\n" );
        }
        int	res	= fscanf( fp, "%s%d", record, &puntuacion_maxima );
        if( res	!=	2 )	{
            printf("Error leyendo el fichero record.txt\n" );
        }
        fclose(	fp );

        if( puntos > puntuacion_maxima ){
            printf ("Has alcanzado un nuevo record. Ahora la maxima puntuacion es %d\n", puntos );
            fp = fopen( "record.txt", "w" );
            fprintf ( fp, "Record: %d", puntos );
            fclose(	fp );
        }

    return salida;
}

int main( int argc, char *argv[] ){

    Pantalla_Crea("Game", 600, 600);

    int var_menu = 0;

    while ( Pantalla_Activa() && var_menu != 3 ){

        if ( var_menu == 0 ){
            var_menu = menu();
        }

        if ( var_menu == 1 ){
            var_menu = jugar();
        }

        if ( var_menu == 2 ){
            var_menu = ayuda();
        }
    }

    Pantalla_Libera();
    return 0;
}
