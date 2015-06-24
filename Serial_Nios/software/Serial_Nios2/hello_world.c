/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */




#include <stdio.h>
#include <stdint.h>
#include "system.h"

int main(void)
{
   volatile uint32_t *uart = (volatile uint32_t*) UART_0_BASE;
   char *str = "Hello from NIOS II\n";

   while (1)
   {
      char *ptr = str;
      while (*ptr != '\0')
      {
         while ((uart[2] & (1<<6)) == 0);
         uart[1] = *ptr;
         ptr++;
      }

      printf("Hello from Nios II!\n");
   }

   return 0;
}



//int main()
//{
//
//  printf("Hello from Nios II!\n");
//
//  return 0;
//}
