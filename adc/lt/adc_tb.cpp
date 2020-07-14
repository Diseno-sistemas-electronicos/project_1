
#include "adc.cpp"

#include <systemc.h>

int sc_main (int argc, char* argv[]) {
 
  int data;
  
  adc adc("ADC",1024);
            
  // Open VCD file
  sc_trace_file *wf = sc_create_vcd_trace_file("adc");
  wf->set_time_unit(1, SC_NS);
  
  // Dump the desired signals
  sc_trace(wf, data, "data");
  
  sc_start(0,SC_NS);
  cout << "@" << sc_time_stamp()<< endl;
  
  adc.enableADC();

  adc.write(0x10, 0xaced);
  sc_start(3,SC_NS);
  data = adc.getResult8(0x10);
  printf("Rd: data = %x\n",data);
    
  adc.write(0x11, 0xbeef);

  sc_start(10,SC_NS);
  adc.write(0x12, 0xdead);

  sc_start(10,SC_NS);
  adc.write(0x13, 0x1234);

  sc_start(10,SC_NS);

  data = adc.getResult8(0x10);
  sc_start(10,SC_NS);
  printf("Rd: data = %x\n",data);

  data = adc.getResult8(0x11);
  sc_start(10,SC_NS);
  printf("Rd: data = %x\n",data);

  adc.setOffset(128);

  data = adc.getResult8(0x12);
  sc_start(10,SC_NS);
  printf("Rd: data = %x\n",data);
  

  data = adc.getResult8(0x13);
  sc_start(10,SC_NS);
  printf("Rd: data = %x\n",data);
  
  cout << "@" << sc_time_stamp() <<" Terminating simulation\n" << endl;
  sc_close_vcd_trace_file(wf);
  return 0;// Terminate simulation

 }
