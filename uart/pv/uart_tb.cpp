#include <systemc.h>
#include "uart.cpp"

// https://forums.accellera.org/topic/24-systemc-230-with-main/
int sc_main (int argc, char* argv[]) {
  int data;
  
  uart uart_comp("MEM", 1024);
            
  // Open VCD file
  sc_trace_file *wf = sc_create_vcd_trace_file("memory");
  wf->set_time_unit(1, SC_NS);
  
  // Dump the desired signals
  sc_trace(wf, data, "data");
  
  sc_start();
  cout << "@" << sc_time_stamp()<< endl;
  
  printf("Writing in zero time\n");
  printf("WR: addr = 0x10, data = 0xaced\n");
  printf("WR: addr = 0x12, data = 0xbeef\n");
  printf("WR: addr = 0x13, data = 0xdead\n");
  printf("WR: addr = 0x14, data = 0x1234\n");
  
  // operation

  cout << "@" << sc_time_stamp()<< endl;
  
  cout << "Reading in zero time" <<endl; 
  // data = mem.rd(0x10);
  
  cout << "@" << sc_time_stamp()<< endl;  

  cout << "@" << sc_time_stamp() <<" Terminating simulation\n" << endl;
  sc_close_vcd_trace_file(wf);
  return 0;// Terminate simulation

 }
