/*=============================================================================
 * Author: Leandro Arrieta <leandroarrieta@gmail.com>
 * 		   Jonathan Cagua <jonathan.cagua@gmail.com>
 * Date: 2021/06/30
 * Version: 1.0
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "sapi.h"
#include "Ejercicio1.h"


/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
	static controlSecuencia Secuencias;
	const gpioMap_t secuenciaLeds[]={LEDB, LED1, LED2, LED3};
	delay_t myDelay;

	// Inicializo mi estructura
	Secuencias.ptrLed = secuenciaLeds;
	Secuencias.LedEncendido = (sizeof(secuenciaLeds)/sizeof(gpioMap_t))-1;
	Secuencias.LedMax = (sizeof(secuenciaLeds)/sizeof(gpioMap_t))-1;
	Secuencias.SentidoSecuencia = false;

	// ----- Setup -----------------------------------
	boardInit();
	delayConfig( &myDelay, 150 );

	//TEC1 -> sentidoSecuencia =0 LEDA -> LED1 -> LED2 -> LED3 -> LEDA …
	//TEC4 -> sentidoSecuencia =1 LED3 -> LED2 -> LED1 -> LEDA -> LED3 …
	//TEC2 -> cada led queda encendido 150 ms.
	//TEC3 -> cada led queda encendido 750 ms.

	// ----- Repeat for ever -------------------------
	while( true ) {

		// seteo_sentido_delay devuelve siempre false hasta que se cumple el tiempo del delay y devuelve true
		if(seteo_sentido_delay(&myDelay ,  &Secuencias)){
			if( !secuencia_actualizar(&Secuencias) )
				atenderError();
			if( !led_apagar_todos(&Secuencias) )
				atenderError();
			if( !led_encender(&Secuencias))
				atenderError();
		}
   }

   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}
/*
bool_t led_encender( gpioMap_t ledx )
{

	//verifico que sea un led válido
	if ( !( (ledx== LED1) || (ledx== LED2) || (ledx== LED3) || (ledx== LEDB) ) )
		return 0;
	else
		return gpioWrite( ledx, ON );
}
*/
bool_t led_encender( controlSecuencia* ptrSecuencia )
{
	if (ptrSecuencia == NULL)
		return (false);
	return gpioWrite( ptrSecuencia->ptrLed[ptrSecuencia->LedEncendido], ON );
}

bool_t led_apagar_todos(controlSecuencia* ptrSecuencia )
{
	if(ptrSecuencia == NULL)
		return(false);
	bool_t resp = true;
	for(int i = 0 ;i <= ptrSecuencia->LedMax; i++){
		resp &= led_apagar( ptrSecuencia->ptrLed[ i ] );	//apago led
		resp &= led_esta_apagado( ptrSecuencia->ptrLed[ i ] );	//verifico que se haya apagado
	}
	return(resp);
}

bool_t tecla_leer (gpioMap_t teclax)
{
	//verifico que sea una tecla válida
	if ( !( (teclax== TEC1) || (teclax== TEC2) || (teclax== TEC3) || (teclax== TEC4) ) )
			return 0;
	return !gpioRead( teclax );
}

bool_t seteo_sentido_delay(delay_t* ptrDelay , controlSecuencia* ptrSecuencia){

	if ( tecla_leer( TEC1 ) ){
		ptrSecuencia->SentidoSecuencia = false;
	}
	if ( tecla_leer( TEC4 ) ){
		ptrSecuencia->SentidoSecuencia = true;
	}
	if ( tecla_leer( TEC2 ) ){
		delayWrite( ptrDelay, 150 );
	}
	if ( tecla_leer( TEC3 ) ){
		delayWrite( ptrDelay, 750 );
	}
	return (delayRead(ptrDelay));
}


bool_t secuencia_actualizar(controlSecuencia* ptrSecuencia)
{
	if(ptrSecuencia == NULL)
		return(false);

	//Antes de prender el led dependiendo de SentidoSecuencia ajusto LedEncendido
	if(ptrSecuencia->SentidoSecuencia){
		if (ptrSecuencia->LedEncendido <= 0)
			ptrSecuencia->LedEncendido = ptrSecuencia->LedMax;
		else
			ptrSecuencia->LedEncendido--;
	}
	else{
		if (ptrSecuencia->LedEncendido >= ptrSecuencia->LedMax)
			ptrSecuencia->LedEncendido = 0;
		else
			ptrSecuencia->LedEncendido++;
	}

	return(true);
}

// No se implementa la atención del error, se deja colgado con el while(1)
void atenderError()
{
	while(1);
}
