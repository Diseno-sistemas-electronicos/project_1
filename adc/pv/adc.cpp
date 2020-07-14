
#include <systemc.h>
#include <unistd.h>

SC_MODULE (adc) {

  //-----------Internal variables-------------------
  uint32_t offset = 0;
  uint32_t gain = 0;
  uint32_t data = 0;
  bool enable = false;

  // Constructor for memory
  SC_HAS_PROCESS(adc);
  adc(sc_module_name adc) : sc_module(adc) {
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

  uint8_t getResult8(){
    return this->data + this->offset;
  }

  uint16_t getResult16() {
    return this->data + this->offset;
  }

  uint32_t getResult32() {
    return this->data + this->offset;
  }

  uint64_t getResult64() {
    return this->data + this->offset;
  }

}; // End of Module ADC