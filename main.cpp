/*

JUEGO ARKANOID REMASTERED
PROYECTO FINAL JOSE PIEDRA

FALTA

         *AGREGAR LOS CREDITOS
         *IMPLEMENTAR SECUENCIA DE EL BOOS FINAL


*/


/************************************************

                LIBRERIAS

*************************************************/

#define _WIN32_WINNT 0X0500 //getConsoleWindows()
#include <allegro.h>
#include <string>
#include <conio.h>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <winalleg.h>
#include <fstream>
#include <windows.h>

using namespace std;

#define ancho 1100
#define alto 680
#define WHITE makecol(255, 255, 255)
#define version 1.2.81220



/***************************************************************************

         DEFINICION DE LOS PUNTEROS DE SONIDO

*****************************************************************************/

MIDI   *musicaInicio;                  //VARIABLE EN LA QUE CARGAREMOS LA MUSICA DE INCIO
MIDI   *musicaJuego;                   //VARIABLE EN LA QUE CARGAREMOS LA MUSICA DEL JUEGO
SAMPLE *sonido_InicioJuego;            //VARIABLE EN LA QUE CARGAREMOS LA MUSICA DE INCIO  DEL JUEGO
SAMPLE *sonido_InicioNivel;            //VARIABLE EN LA QUE CARGAREMOS LA MUSICA DE INCIO NIVEL
SAMPLE *sonido_LadrilloRoto;           //VARIABLE EN LA QUE CARGAREMOS LA MUSICA DE LADRILLO ROTO
SAMPLE *sonido_RebotePelota;           //VARIABLE EN LA QUE CARGAREMOS LA MUSICA DE REBOTE PELOTA
SAMPLE *sonido_Revivir;                //VARIABLE EN LA QUE CARGAREMOS LA MUSICA DE  REVIVIR
SAMPLE *sonido_VidaExtra;              //VARIABLE EN LA QUE CARGAREMOS LA MUSICA DE  VIDA EXTRA
SAMPLE *sonido_rebotaParedes;           //VARIABLE EN LA QUE CARGAREMOS LA MUSICA DE REBOTE CON LA PARED
SAMPLE *sonido_rebotaBase;              //VARIABLE EN LA QUE CARGAREMOS LA MUSICA DE REBOTA BASE
SAMPLE *sonido_vidaperdida;             //VARIABLE EN LA QUE CARGAREMOS LA MUSICA DE VIDA PERDIDA
SAMPLE *sonido_gameover;                //VARIABLE EN LA QUE CARGAREMOS LA MUSICA DE JUEGO ACABADO


/*****************************************************************************

            SE DEFINEN LLOS PUNTEROS PARA LAS IMAGENES

******************************************************************************/

//IMAGENES PARA LA JUGABILIDAD
BITMAP *buffer;             //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DEL BUFFER
BITMAP *logo;               //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DEL LOGO
BITMAP *panel;              //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DEL PANEL
BITMAP *recuadro;           //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DEL RECUADRO
BITMAP *fondo1;             //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DEL FONDO 1
BITMAP *fondo2;             //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DEL FONDO 2
BITMAP *fondo3;              //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DEL FONDO 3
BITMAP *fondo4;              //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DEL FONDO 4
BITMAP *fondo5;              //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DEL FONDO 5
BITMAP *gameover;            //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DEL JUEGO TERMINADO
BITMAP *lad1;                //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DEL LADRILLO 1
BITMAP *lad2;                //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DEL LADRILLO 2
BITMAP *lad3;                //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DEL LADRILLO 3
BITMAP *lad4;                //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DEL LADRILLO 4
BITMAP *lad5;                //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DEL LADRILLO 5
BITMAP *lad6;                //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DEL LADRILLO 6
BITMAP *lad7;                //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DEL LADRILLO 7
BITMAP *ladd;                //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DEL LADRILLO DURO
BITMAP *pelota;              //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DE LA PELOTA
BITMAP *base;               //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DE LA PLATAFORMA
BITMAP *base2;              //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DE LA PLATAFORMA PARA LASECUENCIA DE MUERTE
BITMAP *base3;              //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DE LA PLATAFORMA
BITMAP *base4;              //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DE LA PLATAFORMA PARA LASECUENCIA DE MUERTE

//IMAGENES PARA EL MENU
BITMAP *pini1;              //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DE LA PANTALLA DE INICIO
BITMAP *pini2;              //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DE LA PANTALLA DE INICIO 2
BITMAP *pmen1;              //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DE LA PANTALLA DE MENU
BITMAP *pmen;               //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DE LA PANTALLA DE MENU
BITMAP *pmen2;              //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DE LA PANTALLA DE MENU
BITMAP *pmen3;              //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DE LA PANTALLA DE MENU
BITMAP *pmen4;              //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DE LA PANTALLA DE MENU
BITMAP *pmensa;             //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DE LA PANTALLA DE MENU
BITMAP *cursor;             //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DEL MOUSE

//IMAGENES CREDITOS
BITMAP *pcred1;             //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DE LA PANTALLA DE CREDITOS
BITMAP *pcred2;             //VARIABLE EN LA QUE CARGAREMOS LA IMAGEN DE LA PANTALLA DE CREDITOS CON SELECCION

//IMAGENES DE LOS MEJORES PUNTAJES

BITMAP *mpun;               //DECLARACION DEL PUNTERO DE MEMORIA PARA LA IMAGEN DE MEJORES PUNTAJES
BITMAP *imagen;             //DECLARACION DE LA IMAGEN QUE SE TOMARA PARA INGRESAR NOMBRES

//IMAGENES DE LOS CREDITOS


//ARCHIVO DE DATOS
DATAFILE *datfile;

//FUENTES
FONT *arialB;
FONT *arial20;


/************************************************

            SE DEFINEN LAS FUNCIONES DEL JUEGO

*************************************************/

//BASICAS
int inicio_allegro();
int  inicializo();
void inicializo_sonido();
void inicializo_pantalla();

//FUNCIONES DE MENU
void cargoimg_menu();
void menu();
void liberador_de_memoria();
void liberador_de_memoria2();

//FUNCIONES DE JUGABILIDAD
void destruyo_componentes();
void armo_pantalla();
void muestro();
void jugar();
void muestro_ladrillos();
void configura_level();
void inicializo_nivel();
void muevo_bola();
void chequeo_base();
void retoma_juego();
int cuentoLadrillos();
void dibujaMuerte();
void chequeo_teclasSonido();
void cargo_archivo();
void grabo_archivo();
void jugabilidad();

//FUNCIONES PARA EL MANEJO DE ARCHIVOS

void grabo_archivo_PUNTAJES();
void ordenar_puntajes();
void cargo_puntaje();
void muestro_puntajes(int w, int mejores_puntajes_array[], string mejores_nombres_array[]);
void abro_puntaje();
void detecto_tecla();
void registro_nombre();
void cargo_img();
void fin_partida();

//FUNCION PARA LOS CREDITOS
void mostrarcreditos();

/******************************************************************************************


                                    VARIABLES


*******************************************************************************************/

//JUGABILIDAD
int vidas = 3;                  //ENTERO QUE INDICA LA CANTIDAD DE VIDAD
int level = 1;                  //ENTERO QUE INDICA EL NIVEL
int score = 0;                  //ENTERO QUE INDICA EL PUNTAJE DURANTE LA PARTIDA
bool juegoIniciado = false;     //BOOLEANO QUE HACE INICIAR EL JUEGO
bool fin = false;               //BOOLEANO QUE INDICA CUANDO EL JUEGO HA TERMINADO
bool nuevoNivel=false;          //BOOLEANO QUE INDICA SI SE PASA A UN UEVO NIVEL O NO
bool enJuego=false;             //BOOLEANO QUE INDICA SI AUN SE ESTA JUGANDO O NO
int dirY=-1;                    //ENTERO QUE INDICA COORDENADAS EN Y
int dirX=1;                     //ENTERO QUE INDICA COORDENADAS EN X
int velocidad=3;                //ENTERO QUE ESPECIFICA LA VELOCIDAD
int velocidadInicial=3;         //ENTERO QUE DEVUELVE UNA VELOCIDAD INICIAL
int fondoN=1;                   //ENTERO QUE SE USA PARA ELEGIR EL FONDO
bool muerte=false;              //BOOLEANO QUE INDICA SI LAS VIDAS SE ACABARON O NO
int secuenciaMuerte=1;          //ENTERO PARA HACER LA ANIMACION DE DESTRUCCION DE LA PLATAFORMA
bool musica=true;               //BOOLEANO PARA INDICAR SI LA MUSICA SUENA O NO
bool efectos=true;              //BOOLEANO PARA ACTIVAR LOS EFECTOS O NO
bool finJuego=false;            //BOOLEANO QUE INDICA SI SE ACABO EL JUEGO O NO
bool existeArchivo=false;       //BOOLEANO PARA LA VERIFICACION DE LA EXITENCIA DE UN ARCHIVO
int highScore=0;                //ENTERO QUE INDICA EL PUNTAJE MAS ALTO
bool salir2=false;              //BOOLEANO QUE SIRVE PARA SALIR DE UN BUCLE
int cambio2=1;                  //ENTERO QUE SE USA PARA LA SELECCION DE MENU


int baseX=255;                  //COORDENADAS DE LA PLATAFORMA EN X
int bolaX=295;                  //COORDENADAS DE LA PELOTA EN X
int bolaY=650;                  //COORDENADAS DE LA PELOTA EN Y

//NIVELES

int pant1[63]={1,1,1,1,1,1,1,1,1,       //MAPEO DE LOS NIVELES, CADA NUMERO REPRESENTA UN TIPO DE BLOQUE
               2,2,2,2,2,2,2,2,2,       //SE HACE UN VECTOR DE 63 DEBIDO A QUE SE IMPRIMIRA EN UNA MATRIZ DE
               3,3,3,3,3,3,3,3,3,       // SIENTE FILAS Y NUEVE COLUMNAS
               4,4,4,4,4,4,4,4,4,
               5,5,5,5,5,5,5,5,5,
               6,6,6,6,6,6,6,6,6,
               7,7,7,7,7,7,7,7,7};

int pant2[63]={1,0,1,1,0,1,1,0,1,       //MAPEO PARA EL NIVEL 2
               2,2,2,2,0,2,2,2,2,
               5,5,5,5,0,6,6,6,6,
               5,5,5,5,0,6,0,5,6,
               5,4,4,5,0,6,6,6,6,
               5,5,5,5,0,6,6,6,6,
               7,8,8,8,0,8,8,8,7};

int pant3[63]={1,0,0,1,4,1,0,0,1,       //MAPEO PARA EL NIVEL 3
               3,3,3,3,4,3,3,3,3,
               5,5,5,5,4,6,6,6,6,
               5,0,0,5,4,6,0,0,6,
               5,0,0,5,4,6,0,0,6,
               5,0,0,5,4,6,0,0,6,
               7,8,8,8,8,8,8,8,7};

int mapa[63];                           //VECTOR MAPA DONDE SE GUARDAN LA IMPRESION DE LOS LADRILLOS

int puntaIzq;                           //ENTERO PARA LA PUNTA IZQUIERDA
int puntaDer;                           //ENTERO PARA LA PUNTA DERECHA

int colBola;                            //ENTERO PARA LA COLUMNA  DE BOLA
int filaBola;                           //ENTERO PARA LA FILA DE BOLA
int elemento;                           //ENTERO PARA ELEMENTO

int fila[]={20,50,80,110,140,170,200};  //VECTOR DE FILA QUE DICE EN QUE PARTE DE LA PANTALLA SE IMPRIMIRAN LOS BLOQUES


//VARIABLES DEL MANEJO DE ARCHIVOS

//int highScore;                        //PUNTAJE MAXIMO OBTENIDO EN PARTIDA
//bool existeArchivo;                   //BOOLEANO DE VERIFICACION DE ARCHIVO
int temporal;                           //ENTERO TEMPORAL PARA HACER EL ORDENAMIENTO DEL ARRAY DE PUNTAJES PARA GUARDARLOS
int const DIM= 11;                      //CONSTANTE DE VALOR ENTERO PARA LA DIMENSION DE LOS ARRAYS
int mejores;                       //ARRAY DONDE SE GUARDAN LOS PUNTAJES
int mejores2[DIM];                      //ARRAY PARA GUARDAR LOS PUNTAJES DE EL ARCHIVO Y PODER MONTRARLOS EN EL ENTORNO GRAFICO
int p=0,w=0;                            //VARIABLES QUE VAN A SERVIR PARA CONTADORES
int score2;
bool volvermenu=false,finaldearmarpuntajes=false;                  //VARIABLE PARA VOLVER AL MENU

string nommejor;                        //STRING PARA GUARDAR EL NOMBRE
string temporal2;                       //TEMPORAL STRING PARA PODER HACER EL ORDENAMIENTO DEL NOMBRE
string mejores3[DIM];                   //ARRAY DE STRING PARA GUARDAR LOS NOMBRES AL SALIR DEL ARCHIVO Y PODER MONTRARLOS POR PANTALLA

//VARIABLES PARA INTRODUCIR POR TECLADO
string  edittext;                         // UN STRING VACIO PARA METER LOS DATOS
string::iterator iter = edittext.begin(); // STRING ITERADOR
int     caret  = 0;                       // VARIABLE PARA EL SIGNO DE INTERCALACION
bool    insert = true;                    // DETECTA SI UNA TECLA ESTA SIENDO INTRODUCIDA O NO
string nombre;


/************************************************************************************************************

    FUNCION PRINCIPAL


*********************************************************************************************************/

int main()
{
    inicio_allegro();

    menu();

   return 0;
}
END_OF_MAIN();

/******************************************************************


        FUNCIONES DE LA JUGABILIDAD

 EL NUCLEO DEL JUEGO EN SI AQUI ESTAN TODAS LA FUNCIONES QUE PERMITEN AL JUEGO FUNCIONAR

*********************************************************************/
int inicializo(){                        //FUNCION QUE ME INICIA Y CARGA TODAS LAS FUNCIONES DE LA JUGABILIDAD

    inicializo_sonido();
    inicializo_pantalla();

    datfile=load_datafile("recursos.dat");
    arialB=(FONT*)datfile[1].dat;
    arial20=(FONT*)datfile[0].dat;

    /*HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd,0);*/

    play_midi(musicaInicio,0);
	return 0;
}

void inicializo_sonido(){                // FUNCION QUE ME CARGA EN MEMORIA TODOS LOS SONIDOS DEL JUEGO

    set_volume(230, 200);

	musicaInicio  = load_midi("recursos/sonidos/ark.mid");
    musicaJuego   = load_midi("recursos/sonidos/Arkanoid.mid");
	sonido_InicioJuego = load_wav("recursos/sonidos/InicioJuego.wav");
    sonido_InicioNivel = load_wav("recursos/sonidos/InicioNivel.wav");
	sonido_LadrilloRoto = load_wav("recursos/sonidos/LadrilloRoto.wav");
	sonido_RebotePelota = load_wav("recursos/sonidos/RebotePelota.wav");
	sonido_VidaExtra = load_wav("recursos/sonidos/VidaExtra.wav");
	sonido_rebotaParedes = load_wav("recursos/sonidos/rebotaParedes.wav");
	sonido_rebotaBase = load_wav("recursos/sonidos/reboteBase.wav");
    sonido_vidaperdida = load_wav("recursos/sonidos/fallo.wav");
    sonido_gameover = load_wav("recursos/sonidos/game-over.wav");

}


void destruyo_componentes(){             //FUNCION UTILIZADA PARA QUE AL TERMINAR EL JUEGO DESTRUYA TODOS LOS
                                        //COMPONENTES CARGADOS EN MEMORIA

    destroy_midi(musicaJuego);
    destroy_sample(sonido_InicioJuego);
    destroy_sample(sonido_InicioNivel);
    destroy_sample(sonido_LadrilloRoto);
    destroy_sample(sonido_RebotePelota);
    destroy_sample(sonido_rebotaBase);
    destroy_sample(sonido_rebotaParedes);
    destroy_sample(sonido_VidaExtra);
    destroy_sample(sonido_vidaperdida);
    destroy_sample(sonido_gameover);
	destroy_bitmap(buffer);
}


void inicializo_pantalla(){            // FUNCION QUE ME CARGA EN MEMORIA TODAS LA IMAGENES QUE SE USAN EN LA JUAGBILIDAD


    panel = load_bitmap("recursos/img/panel.bmp",NULL);
    recuadro=load_bitmap("recursos/img/recuadro.bmp",NULL);
    fondo1=load_bitmap("recursos/img/fondo1.bmp",NULL);
    fondo2=load_bitmap("recursos/img/fondo2.bmp",NULL);
    fondo3=load_bitmap("recursos/img/fondo3.bmp",NULL);
    fondo4=load_bitmap("recursos/img/fondo4.bmp",NULL);
    fondo5=load_bitmap("recursos/img/fondo5.bmp",NULL);
    lad1=load_bitmap("recursos/img/ladrillo1.bmp",NULL);
    lad2=load_bitmap("recursos/img/ladrillo2.bmp",NULL);
    lad3=load_bitmap("recursos/img/ladrillo3.bmp",NULL);
    lad4=load_bitmap("recursos/img/ladrillo4.bmp",NULL);
    lad5=load_bitmap("recursos/img/ladrillo5.bmp",NULL);
    lad6=load_bitmap("recursos/img/ladrillo6.bmp",NULL);
    lad7=load_bitmap("recursos/img/ladrillo7.bmp",NULL);
    ladd=load_bitmap("recursos/img/ladrilloduro.bmp",NULL);
    gameover=load_bitmap("recursos/img/gameover.bmp",NULL);
    pelota=load_bitmap("recursos/img/pelota.bmp",NULL);
    base=load_bitmap("recursos/img/base.bmp",NULL);
    base2=load_bitmap("recursos/img/base2.bmp",NULL);
    base3=load_bitmap("recursos/img/base3.bmp",NULL);
    base4=load_bitmap("recursos/img/base4.bmp",NULL);
}


void armo_pantalla(){  //FUNCION QUE ME ARMA LA PANTALLA DE LA JUGABILIDAD

    try             //EL TRY ES UTILIZADO PARA EN EL CASO DE QUE HAYA ERRORES MANEJARLOS Y SABER EL PORQUE
    {

       clear_to_color(buffer, 0x000000);         //ESTO FUNCIONA PARA LIMPIAR EL BUFFER

       draw_sprite(buffer,panel,560,0);          /*ESTO FUNCIONA PARA DIBUJAR EN LAS COORDENADAS QUE SE LE PASEN EN ESTE CASO
                                                 * EN X =560 EN Y=0*/

       textprintf_ex(panel, arialB, 230, 171, makecol(0,0,0),makecol(0,0,0), "          "); //AQUI SE IMPRIME UN ESPACIO EN EL PANEL DONDE
       textprintf_ex(panel, arialB, 230, 230, makecol(0,0,0),makecol(0,0,0), "         ");  //SE ESCRIBIRA ALGO POR ENCIMA
       textprintf_ex(panel, arialB, 295, 290, makecol(0,0,0),makecol(0,0,0), "        ");   //ESTO PARA QUE NO SE VEA SUPER PUESTAS LAS VARIABLES CUANDO CAMBIES DE VALOR

       textprintf_ex(panel, arialB, 230, 171, makecol(255,0,0),makecol(0,0,0), "%d", vidas);   //SE UTILIZA LA MISMA FUNCION PERO EN CAMBIO SE IMPRIMEN
       textprintf_ex(panel, arialB, 230, 230, makecol(255,0,0),makecol(0,0,0), "%d", level);   //VARIABLES NUMERICAS QUE INDICAN PARAMENTROS DENTRO DEL JUEGO
       textprintf_ex(panel, arialB, 295, 290, makecol(255,0,0),makecol(0,0,0), "%d", score);   //SE COLOCAN CON UN PREFIJO % PORQUE LA FUNCION ES UN DERIVADO DE PRINTF

       textprintf_ex(panel, arial20, 175, 120, makecol(255,255,255),makecol(0,0,0), "Highscore : %i", highScore); //AQUI SE IMPRIME EL PUNTAJE MAS ALTO OBTENIDO


       switch(fondoN)
       {
            case 1: draw_sprite(buffer,fondo1,0,0);     //ESTE SWITCH FUNCIONA PARA CAMBIAR DE FONDO EN EL JUEGO
                    break;                              //DEPENDIENDO DEL VALOR DE FONDO ESTE CAMBIA Y SE DIBUJA EN EL BUFFER
            case 2: draw_sprite(buffer,fondo2,0,0);     //DRAW_SPRITE ES UNA FUNCION PARA DIBUJAR O IMPRIMIR UN PUNTERO QUE CONTIENE
                    break;                              //UNA IMAGEN EN EL BITMAP BUFFER
            case 3: draw_sprite(buffer,fondo3,0,0);
                    break;
            case 4: draw_sprite(buffer,fondo4,0,0);
                    break;
            case 5: draw_sprite(buffer,fondo5,0,0);
                    break;
        }

        if (!muerte) {                                      //ESTA SECUENCIA FUNCIONA PARA DIBUJAR LA PLATAFORMA MIENTRAS
           draw_sprite(buffer,base,baseX,650);              //EL VALOR BOOLEANO DE MUERTE SEA DIFERENTE A TRUE ESTA DIBUJA
        } else {                                            //LA PLATAFORMA QUE ESTA EN JUEGO SI EL VALOR DE MUERTE SE CONVIERTE EN
           switch(secuenciaMuerte)                          //TRUE SE HACE UNA SECUENCIA DE MUERTE LA CUAL SE BASA EN SWITCH
           {                                                //Y DE IGUAL MANERA DIBUJA EN EL BUFFER ESTA SECUENCIA
           case 1: draw_sprite(buffer,base2,baseX,655);
                   break;
           case 2: draw_sprite(buffer,base3,baseX,650);
                   break;
           case 3: draw_sprite(buffer,base4,baseX,645);
                   break;
           }
        }

        if(enJuego){                                                    //UN IF QUE VERIFICA SI SE ESTA EN JUEGO PARA DIBUJAR
           circlefill(buffer, bolaX,bolaY, 10, makecol(124,250,16));    //UN CIRCULO QUE ES EL ACTOR DE NUESTRO JUEGO
        } else {
           bolaX=baseX+50;
           circlefill(buffer, bolaX, bolaY, 10, makecol(124,250,16));
        }

        muestro_ladrillos();                                            //FUNCION PARA DIBUJAR LOS LADRILLOS
        if(vidas==0) draw_sprite(buffer,gameover,150,300);              //SI YA NO TE HAY VIDAS DIBUJA LA IMAGEN DE JUEGO TERINADO

        blit(buffer, screen, 0,0,0,0,ancho, alto);                      //UNA VEZ CARGADO TODO EN EL BUFFER SE NECESITA IMPRIMIRLO
    }                                                                   //PARA QUE ASI SE PUEDA VER PARA ESO ES LA FUNCION BLIT CON ELLA
                                                                        //TODO LO QUE SE CARGA EN MEMORIA SE IMPRIME EN LA VENTANA Y SE MUESTRA
    catch (exception& e)                                                //EL FINAL DE LA FUNCION TRY DONDE MANEJO LOS ERRORES QUE PUEDEN HABER
       {
        cout << e.what() << endl;
    }
}


void jugar(){        //BUCLE QUE PERMITE JUGAR DONDE SE EJECUTA LA RUTINA BASICA DEL JUEGO
    try     //FUNCION TRY
    {
        level=1;                            //SE DEFINE EL PRIMER NIVEL
        finJuego=false;                     //SE VUELVEN A ESPECIFICAR ESTAS DOS VARIABLES PARA EVITAR QUE CUANDO SE SALGA Y SE VUELVA A ENTRAR NO ME EJECUTE ESTA FUNCION
        enJuego=false;                      //Y ASI PODER JUGAR LAS VECES QUE SEA

        while (!key[KEY_ESC] && !finJuego){ //BUCLE WHILE QUE SE CUMPLE MIENTRAS NO SEA EL FIN DLE JUEGO O SE PRESIONE LA TECLA ESC

            midi_pause();                   //FUNCION QUE PAUSA LA MUSICA
            inicializo_nivel();             //FUNCION QUE INICIALIZA NIVEL

            while (!nuevoNivel && !key[KEY_ESC] && vidas>0){//BUCLE PARA EL INICIO DE LA JUGABILIDAD
               if(key[KEY_SPACE] && enJuego==false)         //ESTEIF FUNCIONA PARA INICIA EL JUEGO CUANDO SE LE DE A TECLA ESPACIO
               {
                 if(efectos) stop_sample(sonido_InicioNivel); //IF PARA DETENER  LA MUSICA DEL JUEGO CUANDO SE INICICIO DEL NIVEL
                 if (musica) play_midi(musicaJuego,1);        //IF PARA INICIAR LA MUSICA DEL JUEGO
                 enJuego=true;                                //AQUI SE DICE QUE ESTAMOS EN JUEGO
               }
               chequeo_base();                                  //FUNCION PARA EL MOVIMIENTO DE LA BASE

               if (enJuego) {                                   //IF PARA LA GRAFICACION DE LA PELOTA Y VERIFICARCUANDO DESAPARECE UN LADRILLO
                  muestro_ladrillos();                          //FUNCION PARA MOSTRAR LADRILLOS
                  muevo_bola();                                 //FUNCION PARA EL MOVIMIENTO DE LA PELOTA
               }
              if(cuentoLadrillos()==0){                         //IF QUE SIRVE PARA VERIFICAR CUANDO YA NO HAYA LADRILLOS CAMBIAR DE NIVEL
                level++;                                        //AUMENTA LEVEL EN 1 CADA VEZ QUE SE ACABAN LOS LADRILLOS
                nuevoNivel=true;                                //SE CAMBIO EL VALOR PARA QUE EMPIECE LA CONFIGURACION
                fondoN++;                                       //PARA HACER AL CAMBIO DE FONDO
                inicializo_nivel();
              }
              chequeo_teclasSonido();                           //FUNCION PARA PREDER O APAGAR LA MUSICA
              armo_pantalla();                                  //LLAMA A ARMO PANTALLA

              if (vidas==0) finJuego=true;                      //HACE LA RUTINA DE ACABAR EL JUEGO CUANDO TE QUEDAS SIN VIDAS
              if (level>3) finJuego=true;                       //HACE LA RUTINA DE SI LLEGASTE AL NIVEL 3 EL JUEGO SE ACABA
            }
          }

        }
     catch (exception& e)
       {
        cout << e.what() << endl;
       }
}


void inicializo_nivel(){                         //FUNCION QUE INICIA EL NIVEL

    configura_level();                          //LLAMA A LA FUNCION QUE CONFIGURA EL NIVEL
    retoma_juego();                             //LLAMA A LA FUNCION QUE RETOMA EL JUEGO

    if(efectos) play_sample(sonido_InicioNivel,200,150,1000,0); //COLOCA LA CANCION DE INICIO DE NIVEL

}


void retoma_juego(){ //ESTA FUNCION ES PARA RETOMAR EL JUEGO EN UNA POSICION ESPECIFICA
    baseX=255;
    bolaX=295;
    bolaY=650;
    enJuego=false;
    nuevoNivel=false;
    armo_pantalla();
    velocidad = 1+((int)level/5);
}


void configura_level(){ //FUNCION QUE ARMA LA PANTALLA DONDE ESTAN LOS BLOQUES
   for (int i = 0;i<63;i++){
      if(level==1) mapa[i]=pant1[i];
      if(level==2) mapa[i]=pant2[i];
      if(level==3) mapa[i]=pant3[i];
   }
}


void muestro_ladrillos(){ //DEPENDIENDO EL MAPA EMPIEZA A ARMAR LOS BLOQUES POR COLOR
   int x, y, col;
   int lad;

   int fila[7]={20,50,80,110,140,170,200};
   for(int i=0;i<63;i++){

     if(mapa[i]>0){
         lad=mapa[i];
         y=fila[int(i/9)];
         col=i-(((int)(i/9))*9)+1;
         x=1+((col-1)*65);

         switch(lad)
            {
              case 1:
                  draw_sprite(buffer,lad1,x,y);
                  break;
              case 2:
                  draw_sprite(buffer,lad2,x,y);
                  break;
              case 3:
                  draw_sprite(buffer,lad3,x,y);
                  break;
              case 4:
                  draw_sprite(buffer,lad4,x,y);
                  break;
              case 5:
                  draw_sprite(buffer,lad5,x,y);
                  break;
              case 6:
                  draw_sprite(buffer,lad6,x,y);
                  break;
              case 7:
                  draw_sprite(buffer,lad7,x,y);
                  break;
              case 8:
                  draw_sprite(buffer,ladd,x,y);
                  break;
            }
      }
   }
}


void muevo_bola(){ //FUNCION PARA EL MOVIMIENTO DE LA PELOTA
 puntaIzq=baseX+20;
 puntaDer=baseX+100;


 if(bolaY<225){
    filaBola=((int)(((bolaY-20)/30))+1);
    colBola=((int)(bolaX-13)/64)+1;
    elemento=(((filaBola-1)*9)+colBola)-1;

    if(mapa[elemento]!=0) {
          if (dirY==1) {
              dirY=-1;
          } else {
              dirY=1;
          }

          if(mapa[elemento] !=8)
          {
             if(efectos) play_sample(sonido_LadrilloRoto,200,150,1000,0);
             mapa[elemento]=0;
             score=score+rand() % 100;
             muestro_ladrillos();
          } else {

             if(efectos) play_sample(sonido_RebotePelota,200,150,1000,0);

          }
    }

 } else {
     if (bolaY>650 && dirY==1) {
         if (bolaX>=baseX && bolaX<=baseX+120) {

             if(efectos) play_sample(sonido_rebotaBase,200,150,1000,0);

             if(bolaX<=puntaIzq) dirX=-1;
             if(bolaX>=puntaDer) dirX=1;

             dirY=-1;
             return;

         } else {

             if(efectos) play_sample(sonido_vidaperdida,200,150,1000,0);
             vidas--;
             dibujaMuerte();
             if (vidas>0) retoma_juego();
             return;
         }
     }
  }

  if (bolaX>550) dirX=-1;
  if (bolaX<15) dirX=1;
  if (bolaY<15) dirY=1;

  if (bolaX>550 || bolaX<15 || bolaY<15) {
     if(efectos) play_sample(sonido_RebotePelota,200,150,1000,0);
  }

  if (dirX==1) bolaX=bolaX+velocidad;
  if (dirX==-1) bolaX=bolaX-velocidad;
  if (dirY==1) bolaY=bolaY+velocidad;
  if (dirY==-1) bolaY=bolaY-velocidad;

  armo_pantalla();
}


void chequeo_base(){ //DEPENDIENDO DE LA TECLA QUE SE TOQUE HACE Y MUESTRA EL MOVIMIENTO
     if(key[KEY_RIGHT]) {
         if (baseX<476) baseX=baseX+velocidad;
     }

     if(key[KEY_LEFT]) {
        if (baseX>10) baseX=baseX-velocidad;
     }
}


int cuentoLadrillos(){ //FUNCION QUE ME DEVUELVE EL NUMEROS DE LADRILLOS TENIENDO EN CUENTA SI LA PELOTA HA CHOCADO CON UN LADRILLO
   for(int i=0;i<63;i++) {
     if(mapa[i]!=8 && mapa[i]>0) return 1;
   }
   return 0;
}


void dibujaMuerte(){ //MUESTRA LA DESTRUCCION DE LA PLATAFORMA CUANDO SE QUEDA SIN VIDAS
  muerte=true;
  for (secuenciaMuerte=1;secuenciaMuerte<5;secuenciaMuerte++)
  {
     armo_pantalla();
     Sleep(200);
  }
  muerte=false;
  armo_pantalla();
}


void chequeo_teclasSonido(){ //PARA DETENER O DARLE PLAY A LA MUSICA
    if(key[KEY_DEL]) {
       if(musica) {
          musica=false;
          midi_pause();
       } else {
          midi_resume();
          musica=true;
       }
    }

    if(key[KEY_TAB]){
        if(efectos) {
            efectos=false;
        } else {
            efectos=true;
        }
    }
}


void jugabilidad(){ //FUNCION BASICA PARA LA JUGABILIDAD LA QUE LLAMA Y EJECUTA LAS FUNCIONES DE LA JUGABILIDAD

 try
      {
        fin=false;
        while ( !fin )
        {

           armo_pantalla();

           if ( key[KEY_ESC] ) fin=true;

           if ( key[KEY_ENTER] && juegoIniciado==false){

              jugar();
              midi_pause();
              if(efectos) play_sample(sonido_gameover,200,150,1000,0);

              if(score>highScore){
                highScore=score;

              }

                score2=score;

              cout<<score2;
              while(!key[KEY_ESC] && !key[KEY_ENTER]){

              }
              vidas=3;
              level=1;
              velocidad=velocidadInicial;
              score=0;

           }
         }
         fin_partida();
      }
    catch (exception& e)
        {
         cout << e.what() << '\n';
        }



}


/*******************************************************************************

                                    MENU

        AQUI ESTAN LAS FUNCIONES QUE HACEN QUE SE MUESTRE EL MENU

********************************************************************************/
void cargoimg_menu(){ //CUNCION PARA QUE ME CARGA EN CACHE TODAS LA IMAGENES QUE HACEN QUE SEA MUCHO MAS FACIL EL LLAMADO A LOS MISMO


            pini1 = load_bitmap("recursos/img/PANTALLAINICIO1.bmp",NULL);
            pini2 = load_bitmap("recursos/img/PANTALLAINICIO2.bmp",NULL);
            pmen1 = load_bitmap("recursos/img/menuseleccion1.bmp",NULL);
            pmen  = load_bitmap("recursos/img/menusinseleccion.bmp",NULL);
            pmen2 = load_bitmap("recursos/img/menuseleccion2.bmp",NULL);
            pmen3 = load_bitmap("recursos/img/menuseleccion3.bmp",NULL);
            pmen4 = load_bitmap("recursos/img/menuseleccion4.bmp",NULL);
            pmensa = load_bitmap("recursos/img/menuseleccionsalir.bmp",NULL);
            cursor = load_bitmap("recursos/img/cursor.bmp",NULL);
            pcred1 = load_bitmap("recursos/img/creditosvolver.bmp",NULL);
            pcred2 = load_bitmap("recursos/img/creditossinseleccion.bmp",NULL);
}


int inicio_allegro(){ //INCIO ALLEGRO PARA PODER HACER LAS FUNCIONES BASICAS


            allegro_init();
            install_keyboard();
            install_mouse();

            set_color_depth(32);
            set_gfx_mode(GFX_AUTODETECT_WINDOWED, ancho, alto, 0, 0);

            if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {

                allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
                return 1;

            }

            buffer = create_bitmap(ancho, alto);
            inicializo();
}


void menu(){ //FUNCION QUE MUESTRA EL MENU

            int cambio=1;
            bool salir=false;

            cargoimg_menu();

                    while ( !salir ){

                                    switch(cambio){
                                           case 1: draw_sprite(buffer,pini1,0,0);

                                                   cambio=2;
                                                   if (key[KEY_ENTER]){
                                                            cambio=3;
                                                        }
                                                   break;
                                           case 2: draw_sprite(buffer,pini2,0,0);

                                                    cambio=1;
                                                    if (key[KEY_ENTER]){
                                                            cambio=3;
                                                        }
                                                   break;
                                                  break;
                                           case 3:

                                                     if (mouse_x>112 && mouse_x<619 && mouse_y>250 && mouse_y<291){

                                                        blit(pmen1,buffer,0,0,0,0,1080,640);/*seleccion nueva partida*/

                                                        if (mouse_b & 1){

                                                            liberador_de_memoria2();

                                                            jugabilidad();

                                                            cargoimg_menu();
                                                        }
                                                    }
                                                    else if (mouse_x>110 && mouse_x<739 && mouse_y>333 && mouse_y<370){

                                                        blit(pmen2,buffer,0,0,0,0,1080,640);//MEJORES PUNTAJES
                                                        if (mouse_b & 1){

                                                            abro_puntaje();
                                                        }
                                                    }
                                                    else if (mouse_x>102 && mouse_x<429 && mouse_y>392 && mouse_y<451){

                                                        blit(pmen3,buffer,0,0,0,0,1080,640);//CREDITOS
                                                        if (mouse_b & 1){

                                                            mostrarcreditos();

                                                        }


                                                    }
                                                    else if (mouse_x>108 && mouse_x<309 && mouse_y>474 && mouse_y<513){

                                                        blit(pmen4,buffer,0,0,0,0,1080,640);//SALIR

                                                                 if (mouse_b & 1){

                                                                   salir=true;
                                                                   liberador_de_memoria();
                                                                   liberador_de_memoria2();
                                                                   exit(0);
                                                                }

                                                            break;

                                                    }
                                                    else blit(pmen,buffer,0,0,0,0,ancho,alto);//pantalla sin seleccion

                                                    if (key[KEY_P]){
                                                            cambio=1;
                                                        }

                                            masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,25,25);

                                            blit(buffer,screen,0,0,0,0,ancho,alto);

                                                    break;
                                           }

                                    blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                                    if(key[KEY_ENTER]){

                                        //cambio=3;

                                    }



                                }







}


void liberador_de_memoria(){ //LIBERADORES DE MEMORIA, (NO SE UTILIZAN PORQUE HACE QUE EL PROGRAMA SEA MAS LENTO)

    clear_bitmap(fondo1);
    clear_bitmap(fondo2);
    clear_bitmap(fondo3);
    clear_bitmap(fondo4);
    clear_bitmap(fondo5);
    clear_bitmap(panel);
    clear_bitmap(base2);
    clear_bitmap(base3);
    clear_bitmap(base4);
    clear_bitmap(base);

    clear_bitmap(lad1);
    clear_bitmap(lad2);
    clear_bitmap(lad3);
    clear_bitmap(lad4);
    clear_bitmap(lad5);
    clear_bitmap(lad6);
    clear_bitmap(lad7);
    clear_bitmap(ladd);
    clear_bitmap(base4);
    clear_bitmap(base);

    clear_bitmap(gameover);

    clear_bitmap(pelota);

}


void liberador_de_memoria2(){ //LIBERADORES DE MEMORIA, (NO SE UTILIZAN PORQUE HACE QUE EL PROGRAMA SEA MAS LENTO)

    clear_bitmap(pmen1);
    clear_bitmap(pmen2);
    clear_bitmap(pmen3);
    clear_bitmap(pmen4);
    clear_bitmap(pmen);
    clear_bitmap(pini1);
    clear_bitmap(pini2);


    clear_bitmap(pmensa);
    clear_bitmap(cursor);




}


/************************************************************************************************


                                                ARCHIVOS

    FUNCIONES QUE USAN EL  MANEJO DE ARCHOS PARA GUARDAR EL PUNTAJE Y LOS NOMBRES DE LOS JUGADORES

**********************************************************************************************/

void cargo_puntaje(){


    mejores=score2;

    registro_nombre();

    nommejor=nombre;

    grabo_archivo_PUNTAJES();
}



void registro_nombre(){

    do{

        detecto_tecla();

        //MUESTRA EL TEXTO QUE SE ESTA INGRESANDO EN PANTALLA
        textprintf_ex(imagen, arial20, 319,380, makecol(255,255,255),makecol(0,0,0),"INGRESE NOMBRE, SU PUNTAJE ES: %i", score2);
        textout(imagen, arialB, edittext.c_str(), 459, 450, WHITE);

        draw_sprite(buffer,imagen,0,0);
        blit(buffer, screen, 0, 0, 0, 0, ancho, alto);


    }while(!key[KEY_ENTER]); //FIN DEL LOOP PARA PODER ESCRIBIR EN PANTALLA


    nombre=edittext;
}


void grabo_archivo_PUNTAJES(){

    ofstream puntaje;
    ofstream nombres;

    puntaje.open("puntaje.dat",std::fstream::app);
    nombres.open("nombre.dat",std::fstream::app);

    puntaje<<mejores<< endl;
    nombres<<nommejor<< endl;

    puntaje.close();
    nombres.close();
}


void abro_puntaje(){

    //variables que nada mas se van a utilizar aqui en esta funcion
    int mejores_puntajes_array[200];
    string mejores_nombres_array[200];
    char textonombres[100];
    char textoPuntaje[100];
    int w=0;

    //temporales para aplicar el metodo burbuja
    int temporal_puntaje;
    string temporal_nombre;

    ifstream puntajes;
    ifstream nombres;

    puntajes.open("puntaje.dat");
    nombres.open("nombre.dat");

    while( !puntajes.eof() && !nombres.eof() ){

        //VOLCADO DE LA INFORMACION DE LOS PUNTAJES EN UN ARRAY PARA SU MANEJO POSTERIOR
        puntajes.getline(textoPuntaje, sizeof(puntajes));
        string s=string (textoPuntaje);
        mejores_puntajes_array[w]=atoi(s.c_str());


        //VOLCADO DE LOS NOMBRES EN UN ARRAY PARA SU MANEJO POSTERIOR
        nombres.getline(textonombres, sizeof(nombres));
        string n = string (textonombres);
        mejores_nombres_array[w]= n;

        w++;

    }


    puntajes.close();
    nombres.close();

    for (int i=0; i<w;i++){

        for (int j=0; j<w-1;j++){

            if ( mejores_puntajes_array[j] < mejores_puntajes_array[j+1] ){
                    //METODO DE ORDENAMIENTO USANDO UNA TERCERA VARIABLE PARA LOS PUNTAJES
                    temporal_puntaje=mejores_puntajes_array[j];
                    mejores_puntajes_array[j]=mejores_puntajes_array[j+1];
                    mejores_puntajes_array[j+1]=temporal_puntaje;

                    //METODO DE ORDENAMIENTO USANDO UNA TERCERA VARIABLE PARA LOS NOMBRES
                    temporal_nombre=mejores_nombres_array[j];
                    mejores_nombres_array[j]=mejores_nombres_array[j+1];
                    mejores_nombres_array[j+1]=temporal_nombre;
            }
        }
    }

    muestro_puntajes(w,mejores_puntajes_array,mejores_nombres_array);


}


void cargo_img(){

    imagen=load_bitmap("recursos/img/juegoterminado1.bmp",NULL);
    mpun=load_bitmap("recursos/img/mejores_puntajes.bmp",NULL);
}


void detecto_tecla(){

    while(keypressed())
      {
         int  newkey   = readkey();
         char ASCII    = newkey & 0xff;
         char scancode = newkey >> 8;

         // a character key was pressed; add it to the string
         if(ASCII >= 32 && ASCII <= 126)
         {
            // add the new char, inserting or replacing as need be
            if(insert || iter == edittext.end())

               iter = edittext.insert(iter, ASCII);

            else

               edittext.replace(caret, 1, 1, ASCII);

            // increment both the caret and the iterator
            caret++;
            iter++;
         }
            else
            switch(scancode)
            {
               case KEY_DEL:
                  if(iter != edittext.end()) iter = edittext.erase(iter);
               break;

               case KEY_BACKSPACE:
                  if(iter != edittext.begin())
                  {
                     caret--;
                     iter--;
                     iter = edittext.erase(iter);
                     clear(buffer);
                     clear(imagen);

                  }
               break;

               case KEY_RIGHT:
                  if(iter != edittext.end())   caret++, iter++;
               break;

               case KEY_LEFT:
                  if(iter != edittext.begin()) caret--, iter--;
               break;

               case KEY_INSERT:
                  if(insert) insert = 0; else insert = 1;
               break;

               default:

               break;
            }
      }



}


void muestro_puntajes(int w, int mejores_puntajes_array[], string mejores_nombres_array[]){

        cargo_img();

        int cordx=290,cordx2=470,cordy = 150;

        volvermenu = false;
        finaldearmarpuntajes = false;

        while (!volvermenu){

            while(!finaldearmarpuntajes){

                for(int l=0; l<10;l++){

                    cordy = cordy+40;

                    textprintf_ex(mpun, arial20, cordx, cordy, makecol(255,255,255),makecol(0,0,0),"%i- : %i",l+1,mejores_puntajes_array[l]);
                    textout(mpun, arial20, mejores_nombres_array[l].c_str(), cordx2, cordy,makecol(255,255,255) );


                }
                finaldearmarpuntajes = true;
            }


            draw_sprite(buffer,mpun,0,0);

            masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,30,30);

            blit(buffer, screen, 0,0,0,0,ancho, alto);


            if (mouse_x>813 && mouse_x<1056 && mouse_y>623 && mouse_y<651){

                if (mouse_b & 1){

                    volvermenu=true;

                }
            }
        }


}


void fin_partida(){

        cargo_img();
        cargo_puntaje();

}


/***********************************************************************************************************


                                CREDITOS




*************************************************************************************************************/


void mostrarcreditos(){

    volvermenu = false;

    while (!volvermenu){


        draw_sprite(buffer,pcred2,0,0);


        if(mouse_x>744 && mouse_x<1067 && mouse_y>594 && mouse_y<654){

            draw_sprite(buffer,pcred1,0,0);

            if (mouse_b & 1){

                    volvermenu=true;

            }

        }

        masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,30,30);

        blit(buffer, screen, 0,0,0,0,ancho, alto);





    }
}


