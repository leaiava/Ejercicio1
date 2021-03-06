# Ejercicio1

## Autores 鉁掞笍

_Este firmware tiene dos integrantes:_

* **L.Arrieta** - (https://github.com/leaiava)
* **J.Cagua** - (https://github.com/jonathancagua)

### Pre-requisitos 馃搵
- [Firmware V3](https://github.com/epernia/firmware_v3).
- [Utilizaci贸n b谩sica de firmware_v3](https://github.com/epernia/firmware_v3/blob/master/documentation/firmware/usage/usage-es.md).

## Objetivo:
Realizar modificaciones al ejercicio 0 para incorporar buenas pr谩cticas de programaci贸n.

### 1. Utilizar funciones que encapsulen el c贸digo y hagan el programa m谩s legible, como por ejemplo:

	/* encender un led en particular */
	bool_t  encenderLed(gpioMap_t led);
	
	/* apagar todos los leds */
	bool_t  apagarLeds();  
	
	/* leer el estado de una tecla.  Devuelve por valor el estado de la tecla pulsada (verdadero) o liberada (falso)*/
	bool_t leerTecla (gpioMap_t tecla);  
	
	/* psecuencia apunta a una secuencia de leds o arreglo de gpioMap_t */
	void activarSecuencia(gpioMap_t * psecuencia); 
	
**Las funciones deben devolver verdadero o falso en funci贸n de si pudieron realizar su tarea correctamente o no o si la tecla est谩 presionada o no, seg煤n corresponda.**

### 2. Incorporar conceptos de programaci贸n defensiva al c贸digo:

Limitar la visibilidad de la informaci贸n al m铆nimo: 
	Uso de variables locales en lugar de globales, preferentemente.
	Uso de modificador static donde corresponda.
	Verificar los valores de retorno de las funciones.
	Verificar los par谩metros/argumentos antes de utilizarlos.

### 3. [OPCIONAL] Utilizar arreglos para hacer la implementaci贸n reutilizable y escalable, por ejemplo:.

	bool_t flagsControl[] = {FALSE, FALSE, FALSE, FALSE};

	const gpioMap_t secuencia[]={LEDB, LED1, LED2, LED3};

	const uint8_t ultimoLed = sizeof(secuencia)/sizeof(gpioMap_t);
 
### 4. [OPCIONAL] Utilizar estructuras y punteros para hacer la implementaci贸n m谩s gen茅rica y definir dos secuencias de leds distintas y que puedan funcionar en simult谩neo, una con el led RGB y otra con los leds LED1, LED2 y LED3.

Una estructura posible puede ser la siguiente:


	typedef struct {
		const gpioMap_t * ptrLed;	
		const gpioMap_t const* ptrPrimerLed;
		const uint8_t const* ptrUltimoLed;
		} controlSecuencia_t;

Ustedes pueden definir la estructura que crean m谩s conveniente con la debida documentaci贸n en el c贸digo (comentarios)

## Expresiones de Gratitud 馃巵

* Comenta a otros sobre este proyecto 馃摙
* Invita una cerveza 馃嵑 o un caf茅 鈽? a alguien del equipo. 
* etc.
