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

/*=====[Definitions of public data types]====================================*/

/*=====[Prototypes (declarations) of public functions]=======================*/

/* encender un led en particular */
bool_t encenderLed( gpioMap_t ledx );

/* apagar todos los leds */
bool_t  apagarLeds();

/* leer el estado de una tecla.  Devuelve por valor el estado de la tecla pulsada (verdadero) o liberada (falso)*/
bool_t leerTecla (gpioMap_t tecla);

/* Loop infinito para colgar el programa en caso de error*/
bool_t atenderError();

/* psecuencia apunta a una secuencia de leds o arreglo de gpioMap_t */
void activarSecuencia(gpioMap_t * psecuencia);

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __EJERCICIO0_H__ */
