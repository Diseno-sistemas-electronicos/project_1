//-----------------------------------------------------
#include "systemc.h"

#include <unistd.h>
#include <string>

SC_MODULE (uart) {
    
  //-----------Internal variables-------------------
  int tx_port;
	int rx_port;
  int tx_buffer_size;
  int baudrate;

  std::string tx_data;
  std::string rx_data;

  // Constructor for memory
  //SC_CTOR(uart) {
  SC_HAS_PROCESS(uart);
    uart(sc_module_name uart, int size=8) : sc_module(uart) {
  } // End of Constructor

   //------------Code Starts Here-------------------------
  void write(std::string data) {
    this->tx_data = data;
  }  
  
  std::string read() {
    return this->rx_data;
  }
  
}; // End of UART Module
