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
  int data;
  int spiData;

  sc_event_queue wr_t;
  
  // Constructor for spi controller
  SC_HAS_PROCESS(spi);
    spi(sc_module_name spi) : sc_module(spi) {
      SC_THREAD(wr);
    }

    void transmit (int  message){
      this->data = message;
      wr_t.notify(1,SC_NS);
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


    void wr(){
      while(true){
	wait(wr_t.default_event());
	printf("Notify\n");
	cout << "@" << sc_time_stamp() << endl;
	this->spiData = this->data;
      }
    }

  
}; // End of Module spi