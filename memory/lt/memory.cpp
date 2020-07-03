//-----------------------------------------------------
#include "systemc.h"

SC_MODULE (ram) {
 
  //-----------Internal variables-------------------
  int * mem;
  sc_fifo<int> data;
  sc_fifo<int> address;
  sc_event_queue wr_t;
  
  // Constructor for memory
  //SC_CTOR(ram) {
  SC_HAS_PROCESS(ram);
    ram(sc_module_name ram, int size=8) {
    mem = new int [size];
    sc_fifo<int> data (10);
    sc_fifo<int> address (10);
    SC_THREAD(wr);
         
  } // End of Constructor

   //------------Code Starts Here-------------------------
  void write(int addr, int dat) {
    data.write(dat);
    address.write(addr);
    wr_t.notify(2, SC_NS);
  }  
  
  int read(int address) {
    data = mem [address];
    return data;
  }  

  void wr() {
    while(true) {
      wait(wr_t.default_event());
      printf("Notify\n");
      cout << "@" << sc_time_stamp() << endl;
      mem [address.read()] = data.read();
    }  
  }

  
}; // End of Module memory
