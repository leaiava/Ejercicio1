/*=============================================================================
 * Author: Leandro Arrieta <leandroarrieta@gmail.com>
 * 		   Jonathan Cagua <jonathan.cagua@gmail.com>
 * Date: 2021/06/30
 * Version: 1.0
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "Ejercicio1.h"
#include "sapi.h"

/*=====[Definition macros of private constants]==============================*/
#define encenderLed(ledx)	gpioWrite( ledx, ON )
#define apagarLed(ledx)		gpioWrite( ledx, OFF )


/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/


int main( void )
{
	//bool_t EncendioLed = 0;
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
    			encenderLed(LEDB);
    			apagarLed(LED1);
    			apagarLed(LED2);
    			apagarLed(LED3);
    		}
    		if(indice == 2){
    			apagarLed(LEDB);
    			encenderLed(LED1);
				apagarLed(LED2);
				apagarLed(LED3);
    		}
    		if(indice == 3){
    			apagarLed(LEDB);
    			apagarLed(LED1);
    			encenderLed(LED2);
				apagarLed(LED3);
    		}
    		if(indice == 4){
    			apagarLed(LEDB);
    			apagarLed(LED1);
    			apagarLed(LED2);
    			encenderLed(LED3);
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

