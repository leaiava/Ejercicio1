# Ejercicio1

## Autores ✒️

_Este firmware tiene dos integrantes:_

* **L.Arrieta** - (https://github.com/leaiava)
* **J.Cagua** - (https://github.com/jonathancagua)

### Pre-requisitos 📋
- [Firmware V3](https://github.com/epernia/firmware_v3).
- [Utilización básica de firmware_v3](https://github.com/epernia/firmware_v3/blob/master/documentation/firmware/usage/usage-es.md).

## Objetivo:
Realizar modificaciones al ejercicio 0 para incorporar buenas prácticas de programación.

### 1. Utilizar funciones que encapsulen el código y hagan el programa más legible, como por ejemplo:

	/* encender un led en particular */
	bool_t  encenderLed(gpioMap_t led);
	
	/* apagar todos los leds */
	bool_t  apagarLeds();  
	
	/* leer el estado de una tecla.  Devuelve por valor el estado de la tecla pulsada (verdadero) o liberada (falso)*/
	bool_t leerTecla (gpioMap_t tecla);  
	
	/* psecuencia apunta a una secuencia de leds o arreglo de gpioMap_t */
	void activarSecuencia(gpioMap_t * psecuencia); 
	
**Las funciones deben devolver verdadero o falso en función de si pudieron realizar su tarea correctamente o no o si la tecla está presionada o no, según corresponda.**

### 2. Incorporar conceptos de programación defensiva al código:

Limitar la visibilidad de la información al mínimo: 
	Uso de variables locales en lugar de globales, preferentemente.
	Uso de modificador static donde corresponda.
	Verificar los valores de retorno de las funciones.
	Verificar los parámetros/argumentos antes de utilizarlos.

### 3. [OPCIONAL] Utilizar arreglos para hacer la implementación reutilizable y escalable, por ejemplo:.

	bool_t flagsControl[] = {FALSE, FALSE, FALSE, FALSE};

	const gpioMap_t secuencia[]={LEDB, LED1, LED2, LED3};

	const uint8_t ultimoLed = sizeof(secuencia)/sizeof(gpioMap_t);
 
### 4. [OPCIONAL] Utilizar estructuras y punteros para hacer la implementación más genérica y definir dos secuencias de leds distintas y que puedan funcionar en simultáneo, una con el led RGB y otra con los leds LED1, LED2 y LED3.

Una estructura posible puede ser la siguiente:


	typedef struct {
		const gpioMap_t * ptrLed;	
		const gpioMap_t const* ptrPrimerLed;
		const uint8_t const* ptrUltimoLed;
		} controlSecuencia_t;

Ustedes pueden definir la estructura que crean más conveniente con la debida documentación en el código (comentarios)

## Expresiones de Gratitud 🎁

* Comenta a otros sobre este proyecto 📢
* Invita una cerveza 🍺 o un café ☕ a alguien del equipo. 
* etc.
