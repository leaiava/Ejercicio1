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

/* encender un led en particular */
bool_t led_encender( controlSecuencia* ptrSecuencia );

/* apagar todos los leds */
bool_t led_apagar_todos(controlSecuencia* ptrSecuencia );

/* leer el estado de una tecla.  Devuelve por valor el estado de la tecla pulsada (verdadero) o liberada (falso)*/
bool_t tecla_leer (gpioMap_t tecla);

/* lee las teclas y configura el delay*/
bool_t seteo_delay(delay_t* ptrDelay);

/*lee las teclas y setea el sentido de la secuencia*/
void seteo_sentidoSecuencia( controlSecuencia* ptrSecuencia1);
/* prende el led que cooresponde*/
bool_t secuencia_actualizar(controlSecuencia* ptrSecuencia);

/* atiende los errores*/
void atenderError();
/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __EJERCICIO0_H__ */
