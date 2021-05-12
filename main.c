// ************************************************************************
// Camila Lemus Lone
// 18272
// ************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"

#define DELAY 10000000

#define RED GPIO_PIN_1
#define GREEN GPIO_PIN_3
#define YELLOW GPIO_PIN_1|GPIO_PIN_3 //Combinación para hacer amarillo
#define OFF 0x00000000

//*************************************************************************

/**
 * main.c
 */
int main(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN); //Config CLK
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); //Peripheral Enable puerto F
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3); //Config salidas
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4); //Config entradas
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU); //Pullup

    while (1)
    {
        if ( !GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4) )
        {

            //Verde
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GREEN);
            SysCtlDelay(DELAY);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, OFF);
            SysCtlDelay(DELAY/2);

            //Parpadeo
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GREEN);
            SysCtlDelay(DELAY/4);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, OFF);
            SysCtlDelay(DELAY/4);

            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GREEN);
            SysCtlDelay(DELAY/4);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, OFF);
            SysCtlDelay(DELAY/4);

            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GREEN);
            SysCtlDelay(DELAY/4);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, OFF);
            SysCtlDelay(DELAY/4);

            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GREEN);
            SysCtlDelay(DELAY/4);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, OFF);
            SysCtlDelay(DELAY/4);


            //Amarillo
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, YELLOW);
            SysCtlDelay(DELAY);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, OFF);
            SysCtlDelay(DELAY/2);

            //Rojo
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, RED);
            SysCtlDelay(DELAY);
          //  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, OFF);
         //   SysCtlDelay(DELAY/2);
        }

    }
}
