/*=============================================================================
 * Author: Leandro Arrieta <leandroarrieta@gmail.com>
 * Date: 2021/05/21
 * Version: 1.0
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "Ejercicio0.h"
#include "sapi.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
   	// ----- Setup -----------------------------------
	boardInit();


	uint8_t sentidoSecuencia = 0;
		//TEC1 -> sentidoSecuencia =0 LEDA -> LED1 -> LED2 -> LED3 -> LEDA …
		//TEC4 -> sentidoSecuencia =1 LED3 -> LED2 -> LED1 -> LEDA -> LED3 …

    uint8_t ledTime = 0;
    	//TEC2 -> ledTime = 0 cada led queda encendido 150 ms.
    	//TEC3 -> ledTime = 1 cada led queda encendido 750 ms.

    uint8_t indice=1;
    delay_t myDelay;

    delayConfig( &myDelay, 150 );
    // ----- Repeat for ever -------------------------

    while( true ) {
    	if ( !gpioRead( TEC1 ) ){
    		sentidoSecuencia = 0;
    	}

    	if ( !gpioRead( TEC2 ) ){
    		delayWrite( &myDelay, 150 );
    	}

    	if ( !gpioRead( TEC3 ) ){
    		delayWrite( &myDelay, 750 );
    	}

    	if ( !gpioRead( TEC4 ) ){
    		sentidoSecuencia = 1;
    	}

    	if(delayRead(&myDelay)){

    		if(indice == 1){
    			gpioWrite( LEDB, ON );
    			gpioWrite( LED1, OFF );
    			gpioWrite( LED2, OFF );
    			gpioWrite( LED3, OFF );
    		}
    		if(indice == 2){
    			gpioWrite( LEDB, OFF );
    			gpioWrite( LED1, ON );
    			gpioWrite( LED2, OFF );
    			gpioWrite( LED3, OFF );
    		}
    		if(indice == 3){
    			gpioWrite( LEDB, OFF );
    			gpioWrite( LED1, OFF );
    			gpioWrite( LED2, ON );
    			gpioWrite( LED3, OFF );
    		}
    		if(indice == 4){
    			gpioWrite( LEDB, OFF );
    			gpioWrite( LED1, OFF );
    			gpioWrite( LED2, OFF );
    			gpioWrite( LED3, ON );
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
