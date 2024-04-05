
# include "../include/STD_TYPES.h"
# include "../include/BIT_MATH.h"

# include "../include/RCC_interface.h"
# include "../include/GPIO_interface.h"
# include "../include/STK_interface.h"
# include "../include/Array.h"

void main(void)
{
	u8 Local_u8InitloopCounter;
    u32 Local_u32loopCounter;

	MRCC_voidInit();
	MSTK_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB_BUS, RCC_AHB_GPIOAEN);

	for(Local_u8InitloopCounter=0; Local_u8InitloopCounter<8; Local_u8InitloopCounter++)
	{
	MGPIO_voidSetPinMode(PORTA, Local_u8InitloopCounter, OUTPUT);
	MGPIO_voidSetPinOutputMode(PORTA, Local_u8InitloopCounter, PUSH_PULL);
	MGPIO_voidSetPinOutputSpeed(PORTA, Local_u8InitloopCounter, LOW_SPEED);
    }

  while (1)
   {
	  for(Local_u32loopCounter=0; Local_u32loopCounter<23344; Local_u32loopCounter++)
	  {
		MGPIO_voidSetPinOutputValue(PORTA, 0, GET_BIT( Musica_raw[Local_u32loopCounter], 0));
		MGPIO_voidSetPinOutputValue(PORTA, 1, GET_BIT( Musica_raw[Local_u32loopCounter], 1));
		MGPIO_voidSetPinOutputValue(PORTA, 2, GET_BIT( Musica_raw[Local_u32loopCounter], 2));
		MGPIO_voidSetPinOutputValue(PORTA, 3, GET_BIT( Musica_raw[Local_u32loopCounter], 3));
		MGPIO_voidSetPinOutputValue(PORTA, 4, GET_BIT( Musica_raw[Local_u32loopCounter], 4));
		MGPIO_voidSetPinOutputValue(PORTA, 5, GET_BIT( Musica_raw[Local_u32loopCounter], 5));
		MGPIO_voidSetPinOutputValue(PORTA, 6, GET_BIT( Musica_raw[Local_u32loopCounter], 6));
		MGPIO_voidSetPinOutputValue(PORTA, 7, GET_BIT( Musica_raw[Local_u32loopCounter], 7));
		MSTK_voidSetBusyWait(97);
	  }
   }
}
