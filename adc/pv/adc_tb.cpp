
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
  adc.enableADC();
  adc.setOffset(0);

  printf("Writing into ADC\n");

  data = adc.getResult8();
  printf("Rd 8:data = %x\n",data);
  data = adc.getResult16();
  printf("Rd 16:data = %x\n",data);
  data = adc.getResult32();
  printf("Rd 32:data = %x\n",data);

  cout << "@" << sc_time_stamp()<< endl;

  cout << "@" << sc_time_stamp() <<" Terminating simulation\n" << endl;

  sc_close_vcd_trace_file(wf);
  return 0;
}