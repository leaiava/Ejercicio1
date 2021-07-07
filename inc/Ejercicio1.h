/*=============================================================================
 * Author: Leandro Arrieta <leandroarrieta@gmail.com>
 * Date: 2021/05/21
 * Version: 1.0
 *===========================================================================*/

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef __EJERCICIO0_H__
#define __EJERCICIO0_H__

/*=====[Inclusions of public function dependencies]==========================*/

#include <stdint.h>
#include <stddef.h>

/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

#define led_apagar(ledx)	gpioWrite( ledx, OFF )
#define led_esta_apagado(teclax)	!gpioRead( teclax )

/*=====[Definitions of public data types]====================================*/

typedef struct{
	const gpioMap_t* ptrLed;//puntero al arreglo de leds
	uint8_t ledEncendido;//el led encendido en la secuencia
	uint8_t ultimoLed;//numero del último led del array
	bool_t sentidoSecuencia;//el sentido q va la secuencia
}controlSecuencia;

/*=====[Prototypes (declarations) of public functions]=======================*/

/* Funcion encenderLed
 * Sirve para encender un led en particular
 * Recibe un puntero a la estructura controlSecuencia
 * Devuelve 1 si pudo encender el led
 * Devuelve 0 en caso de error */
bool_t encenderLed( controlSecuencia* ptrSecuencia );

/* Funcion apagarLeds
 * Sirve para apagar todos los leds juntos
 * Recibe un puntero a la estructura controlSecuencia
 * Devuelve 1 si pudo apagar todos los leds
 * Devuelve 0 en caso de error */
bool_t apagarLeds(controlSecuencia* ptrSecuencia );

/* Funcion leerTecla
 * Sirve para leer el estado de una tecla.
 * Recibe un puntero a la estructura controlSecuencia
 * Devuelve por valor el estado de la tecla pulsada (verdadero) o liberada (falso)*/
bool_t leerTecla (gpioMap_t tecla);

/* Funcion seteo_delay
 * Funcion para setear el delay y verificar si se cumplió el tiempo. Es un delay no bloqueante
 * TEC2 -> cada led queda encendido 150 ms.
 * TEC3 -> cada led queda encendido 750 ms.
 * Recibe un puntero a la variable tipo delay_t
 * Devuelve 1 si se cumplió el delay
 * Devuelve 0 en caso contrario */
bool_t seteo_delay(delay_t* ptrDelay);

/* Funcion seteo_sentidoSecuencia
 * Sirve para apagar seterar el sentido de la secuencia de leds. Lee las teclas 1 y 4
 * TEC1 -> sentidoSecuencia =0 LEDA -> LED1 -> LED2 -> LED3 -> LEDA …
 * TEC4 -> sentidoSecuencia =1 LED3 -> LED2 -> LED1 -> LEDA -> LED3 …
 * Recibe un puntero a la estructura controlSecuencia
 * No devuelve nada*/
void seteo_sentidoSecuencia( controlSecuencia* ptrSecuencia);

/* Funcion activarSecuencia
 * Funcion que selecciona el Led que se tiene que prender de acuerdo al led que estaba prendido y al sentido de la secuencia
 * Recibe un puntero a la estructura controlSecuencia
 * Devuelve 1 si no hubo error
 * Devuelve 0 en caso de error */
bool_t activarSecuencia(controlSecuencia* ptrSecuencia);

/* Funcion atenderError
 * Funcion para atender errores no implementada
 * Se dejo un while(1) para que se quede en esta función en caso de error*/
void atenderError();

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __EJERCICIO0_H__ */
