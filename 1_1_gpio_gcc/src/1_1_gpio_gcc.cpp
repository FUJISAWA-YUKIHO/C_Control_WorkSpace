/***********************************************************************
*
*  FILE        : 1_gpio_gcc.cpp
*  DATE        : 2023-01-31
*  DESCRIPTION : Main Program
*
*  NOTE:THIS IS A TYPICAL EXAMPLE.
*
***********************************************************************/
#ifdef CPPAPP
extern "C" {
#endif
#include "r_smc_entry.h"
#include "common.h"
#include "cpu_board.h"
#include "io_board.h"
#ifdef CPPAPP
}
#endif




#ifdef CPPAPP
//Initialize global constructors
extern void __main()
{
  static int initialized;
  if (! initialized)
    {
      typedef void (*pfunc) ();
      extern pfunc __ctors[];
      extern pfunc __ctors_end[];
      pfunc *p;

      initialized = 1;
      for (p = __ctors_end; p > __ctors; )
    (*--p) ();

    }
}
#endif 

int main(void) {

    while(1) {

	// TODO: add application code here
		LED_R = ~SW1;
		LED_G = ~SW2;
    }
return 0;
}
