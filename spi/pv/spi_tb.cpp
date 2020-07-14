#include <systemc.h> 
#include "spi.cpp"

// https://forums.accellera.org/topic/24-systemc-230-with-main/
int sc_main (int argc, char* argv[]) {
  int data;
  
  spi spi("spi");
            
  // Open VCD file
  sc_trace_file *wf = sc_create_vcd_trace_file("spi");
  wf->set_time_unit(1, SC_NS);
  
  // Dump the desired signals
  sc_trace(wf, data, "data");
  
  sc_start();
  cout << "@" << sc_time_stamp()<< endl;

  printf("Select mode 1\n");

  spi.select_mode(1);

  printf("Select slave 1\n");

  spi.select_slave(1);
  
  
  printf("Writing \n");
  
  printf("WR:  data = 0xaced\n");
  printf("WR:  data = 0xbeef\n");
  printf("WR:  data = 0xdead\n");
  printf("WR:  data = 0x1234\n");
  
  
  spi.transmit(0xaced);
  spi.transmit(0xbeef);
  spi.transmit(0xdead);
  spi.transmit(0x1234);
  
  cout << "@" << sc_time_stamp()<< endl;
  
  cout << "Reading in zero time" <<endl; 
  data = spi.receive();
  printf("Rd:data = %x\n",data);
  data = spi.receive();
  printf("Rd:data = %x\n",data);
  data = spi.receive();
  printf("Rd:data = %x\n",data);
  data = spi.receive();
  printf("Rd:data = %x\n",data);
  
  cout << "@" << sc_time_stamp()<< endl;  

  cout << "@" << sc_time_stamp() <<" Terminating simulation\n" << endl;
  sc_close_vcd_trace_file(wf);
  return 0;// Terminate simulation

 }
