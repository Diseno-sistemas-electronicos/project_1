
#include <systemc.h>
#include <unistd.h>

SC_MODULE (adc) {

  //-----------Internal variables-------------------
  uint32_t offset = 0;
  uint32_t gain = 0;

  // Constructor for memory
  SC_HAS_PROCESS(adc);
  adc(sc_module_name adc) : sc_module(adc) {
  }

  void enable(){}

  bool setOffset(uint32_t newOffset) {
    offset = newOffset;
    return true;
  }

  bool setGain(uint32_t newGain) {
    gain = newGain;
    return true;
  }

  uint8_t getResult8(){
    return 0;
  }

  uint16_t getResult16() {
    return 0;
  }

  uint32_t getResult32() {
    return 0;
  }

  uint64_t getResult64() {
    return 0;
  }

}; // End of Module ADC