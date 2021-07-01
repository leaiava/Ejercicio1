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

//#define encenderLed(ledx)	gpioWrite( ledx, ON )
#define apagarLed(ledx)		gpioWrite( ledx, OFF )
//#define leerTecla(teclax)	!gpioRead( teclax )

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

gpioMap_t secuenciaLeds[4] = { LEDB, LED1, LED2, LED3};

int main( void )
{

	// ----- Setup -----------------------------------
	boardInit();


	bool_t sentidoSecuencia = 0;

		//TEC1 -> sentidoSecuencia =0 LEDA -> LED1 -> LED2 -> LED3 -> LEDA …
		//TEC4 -> sentidoSecuencia =1 LED3 -> LED2 -> LED1 -> LEDA -> LED3 …
    	//TEC2 -> ledTime = 0 cada led queda encendido 150 ms.
    	//TEC3 -> ledTime = 1 cada led queda encendido 750 ms.

    uint8_t indice=1;
    delay_t myDelay;

    delayConfig( &myDelay, 150 );
    // ----- Repeat for ever -------------------------

    while( true ) {
    	if ( leerTecla( TEC1 ) ){
    		sentidoSecuencia = 0;
    	}

    	if ( leerTecla( TEC2 ) ){
    		delayWrite( &myDelay, 150 );
    	}

    	if ( leerTecla( TEC3 ) ){
    		delayWrite( &myDelay, 750 );
    	}

    	if ( leerTecla( TEC4 ) ){
    		sentidoSecuencia = 1;
    	}

    	if(delayRead(&myDelay)){

    		if(indice == 1){
    			if( !apagarLeds() )
    				atenderError();
    			if ( !encenderLed(LEDB) )
    				atenderError();
    		}
    		if(indice == 2){
    			if( !apagarLeds() )
					atenderError();
				if ( !encenderLed(LED1) )
					atenderError();
    		}
    		if(indice == 3){
    			if( !apagarLeds() )
					atenderError();
				if ( !encenderLed(LED2) )
					atenderError();
    		}
    		if(indice == 4){
    			if( !apagarLeds() )
					atenderError();
				if ( !encenderLed(LED3) )
					atenderError();
    		}

    		if( sentidoSecuencia == 0)
    			indice++;
    		else
    			indice--;

    		if (indice >= 5)
    			indice = 1;

			if (indice <= 0)
				indice = 4;
    	}
   }

   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}

bool_t encenderLed( gpioMap_t ledx )
{

	//verifico que el led elegido sea un led válido
	if ( !( (ledx== LED1) || (ledx== LED2) || (ledx== LED3) || (ledx== LEDB) ) )
		return 0;
	else
		return gpioWrite( ledx, ON );
}

bool_t  apagarLeds()
{
	bool_t resp = FALSE;
	resp =  apagarLed( LEDB );
	resp &= apagarLed( LED1 );
	resp &= apagarLed( LED2 );
	resp &= apagarLed( LED3 );

	// Leo todos los leds para verificar que están apagados. devuelve VERDADERO si estan todos apagados.
	resp &= !gpioRead( LEDB );
	resp &= !gpioRead( LED1 );
	resp &= !gpioRead( LED2 );
	resp &= !gpioRead( LED3 );

	return(resp);
}

bool_t leerTecla (gpioMap_t teclax)
{
	return !gpioRead( teclax );
}

bool_t atenderError()
{
	while(1);
	return 0;
}

void activarSecuencia(gpioMap_t *psecuencia)
{

}
