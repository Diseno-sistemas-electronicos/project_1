//-----------------------------------------------------
#include "systemc.h"

#include <unistd.h>

#include <string>

SC_MODULE (spi) {
    
  //-----------Internal variables-------------------
  int clock_polarity;
  int clock_phase;
  int mode;
  int slave_selected;
  int MISO;
  int MOSI;
  int spiData;
  
  
  // Constructor for spi controller
  SC_HAS_PROCESS(spi);
    spi(sc_module_name spi) : sc_module(spi) {
    }

    void transmit (int  message){
      this->spiData = message;
    }
    
    int receive (){
      return this->spiData;
    }
    
    void select_mode(int mode){
      this->mode = mode;
    }
    void select_slave(int slave){
      this->slave_selected = slave; 
    }

  
}; // End of Module spi
