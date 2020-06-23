
#include "adc.cpp"

#include <systemc.h>


int sc_main (int argc, char* argv[]) {

  int data;

  adc adc("ADC0");

  // Open VCD file
  sc_trace_file *wf = sc_create_vcd_trace_file("memory");
  wf->set_time_unit(1, SC_NS);

  // Dump the desired signals
  sc_trace(wf, data, "data");

  sc_start();
  cout << "@" << sc_time_stamp()<< endl;

  return 0;
}