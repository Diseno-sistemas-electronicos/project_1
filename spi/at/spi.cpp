//-----------------------------------------------------
#include "systemc.h"

#include <unistd.h>

#include <string>

SC_MODULE (spi) {
    
  //-----------Internal variables-------------------
  sc_uint<32> clock_polarity;
  sc_uint<32> clock_phase;
  sc_uint<32> mode;
  sc_uint<32> slave_selected;
  sc_uint<32> MISO;
  sc_uint<32> MOSI;
  sc_uint<32> data;
  sc_inout<sc_uint<32>> spiData;

  sc_event_queue wr_t, rd_t;
  
  // Constructor for spi controller
  SC_HAS_PROCESS(spi);
    spi(sc_module_name spi) : sc_module(spi) {
      SC_THREAD(wr);
      SC_THREAD(rd);
    }

    void transmit (){
      wr_t.notify(2,SC_NS);
    }
    
    void receive (){
      rd_t.notify(1,SC_NS);

    }
    
    void select_mode(int mode){
      this->mode = mode;
    }
    void select_slave(int slave){
      this->slave_selected = slave; 
    }

    void rd(){
      while(true){
	wait(rd_t.default_event());
	printf("Notify\n");
	cout << "@" << sc_time_stamp() << endl;
        this->spiData = this->data;
      }
    }
    
    void wr(){
      while(true){
	wait(wr_t.default_event());
	printf("Notify\n");
	cout << "@" << sc_time_stamp() << endl;
	this->data = this->spiData.read();
      }
    }

  
}; // End of Module spi
