//-----------------------------------------------------
#include "systemc.h"

#include <unistd.h>

SC_MODULE (uart) {
    
  //-----------Internal variables-------------------
	int * mem;
  int tx_port;
	int rx_port;
  int baudrate;

  // Constructor for memory
  //SC_CTOR(uart) {
  SC_HAS_PROCESS(uart);
    uart(sc_module_name uart, int size=8) : sc_module(uart) {
  } // End of Constructor

   //------------Code Starts Here-------------------------
  void write(int address, int data) {
    // sleep(1); //will not move time stamp either
    mem [address] = data;
  }  
  
  int read(int address) {
    return mem [address];
  }
  

  
}; // End of UART Module
