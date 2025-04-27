#include <stdio.h>
#include <driver/gpio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"

#define LED_1_PIN 16
 
#define BUT_1_PIN 17
#define BUT_2_PIN 18
#define BUT_3_PIN 19
#define BUT_4_PIN 21

static int getNumber()
//really ugly I know
//4 buttons to make 15 possible values using binary
{
  int v0, v1, v2, v3;
  v0 = v1 = v2 = v3 = 0;

  while( !gpio_get_level(BUT_1_PIN) || !gpio_get_level(BUT_2_PIN) || !gpio_get_level(BUT_3_PIN) || !gpio_get_level(BUT_4_PIN))
  //while at least one of them is still pressed
  {
    gpio_set_level( LED_1_PIN, 1 );
    //this led is just an indicator that you are writing something
    if( !gpio_get_level( BUT_1_PIN ) )
    {
      v0 = 1;
    }
    if( !gpio_get_level( BUT_2_PIN ) )
    {
      v1 = 1;
    }
    if( !gpio_get_level( BUT_3_PIN ) )
    {
      v2 = 1;
    }
    if( !gpio_get_level( BUT_4_PIN ) )
    {
      v3 = 1;
    }
  }
  gpio_set_level( LED_1_PIN, 0 );
  v1 = v1 << 1;
  v2 = v2 << 2;
  v3 = v3 << 3;
  int retValue = v0 | v1 | v2 | v3;
  //basically: 
  //scenario where all buttons were pressed
  //imagine there are more zeros to the left
  // 24 more zeros < 00000001     (v0)
  // 24 more zeros < 00000010     (v1)
  // 24 more zeros < 00000100     (v2)
  // 24 more zeros < 00001000     (v3)
  // when using operator '|' these ones basically add together
  // 24 more zeros < 00001111
  // hence giving number 15
  return retValue;
}


void app_main()
{   

  gpio_reset_pin(LED_1_PIN);
  gpio_reset_pin(BUT_1_PIN);
  gpio_reset_pin(BUT_2_PIN);
  gpio_reset_pin(BUT_3_PIN);
  gpio_reset_pin(BUT_4_PIN);

  gpio_set_direction( LED_1_PIN, GPIO_MODE_OUTPUT );
  gpio_set_direction( BUT_1_PIN, GPIO_MODE_INPUT );
  gpio_set_direction( BUT_2_PIN, GPIO_MODE_INPUT );
  gpio_set_direction( BUT_3_PIN, GPIO_MODE_INPUT );
  gpio_set_direction( BUT_4_PIN, GPIO_MODE_INPUT );

  for(;;)
  {
    int a=0, b=0, c=0;
    while(a == 0)
    {
      vTaskDelay(2); 
      a = getNumber();
    }
    printf( "Got a binary number: %d\n",a);
    while(b == 0)
    {
      vTaskDelay(2); 
      b = getNumber();
    }
    printf( "Got a binary number: %d\n",b);
    c = a + b;
    printf(  "%d + %d = %d\n",a ,b ,c );
  }
}
