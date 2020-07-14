//-----------------------------------------------------
#include "systemc.h"

SC_MODULE (adc) {
 
  //-----------Internal variables-------------------
  int * mem;
  uint32_t data = 0;
  int address;
  uint32_t offset = 0;
  uint32_t gain = 0;
  bool enable = false;

  sc_event rd_t, wr_t;
  
  // Constructor for memory
  //SC_CTOR(adc) {
  SC_HAS_PROCESS(adc);
    adc(sc_module_name adc, int size=8) {
    mem = new int [size];
    SC_THREAD(wr)
         
  } // End of Constructor

  //------------Code Starts Here-------------------------
  void write(int addr, int dat) {
    data = dat;
    address = addr;
    wr_t.notify(2, SC_NS);
  }

  int getResult8(int address) {
    rd_t.notify(2, SC_NS);
    return this->offset + this->data;
  }

  void wr() {
    while(true) {
      wait(wr_t);
      mem [address] = data;
    }
  }

  void enableADC(){
    this->enable = true;
  }
  
  void disableADC(){
    this->enable = false;
  }

  bool setOffset(uint32_t newOffset) {
    offset = newOffset;
    return true;
  }

  bool setGain(uint32_t newGain) {
    gain = newGain;
    return true;
  }

  uint16_t getResult16() {
    rd_t.notify(2, SC_NS);
    return this->offset + this->data;
  }

  uint32_t getResult32() {
    rd_t.notify(2, SC_NS);
    return this->offset + this->data;
  }

  uint64_t getResult64() {
    rd_t.notify(2, SC_NS);
    return this->offset + this->data;
  }

}; // End of Module memory
