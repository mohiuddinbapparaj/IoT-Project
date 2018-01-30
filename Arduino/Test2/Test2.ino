#define F_CPU 8000000UL // define clock frequency
#include <avr/io.h>//port mapping defined in this library
#include <util/delay.h>

int main(void)

{   
  DDRC &= (0 << PC0);
  DDRD |= (1 << PD0);// Data Direction Register; Or given for left shifting 1
  uint8_t inputTemp = 0;
  
  
  while (1)            // Infinite loop for micro controller; 1 for true condition
  
  {
    inputTemp = PINC & 0x01; //High Check
                  // pin is pulled up
      if(inputTemp == 0x00)
      {
        PORTD |= (1<<PD0);
      }
      else
      {
        PORTD &=~ (1<<PD0);
      }
    
  }
  return 0;
}

