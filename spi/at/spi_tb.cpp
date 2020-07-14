#include <systemc.h> 
#include "spi.cpp"



int sc_main (int argc, char* argv[]) {
  sc_signal<sc_uint<32>> data;
  
  spi spi("spi");
  spi.spiData(data);
            
  // Open VCD file
  sc_trace_file *wf = sc_create_vcd_trace_file("spi");
  wf->set_time_unit(1, SC_NS);
  
  // Dump the desired signals
  sc_trace(wf, data, "data");
  
  sc_start(0,SC_NS);
  cout << "@" << sc_time_stamp()<< endl;

  printf("Select mode 1\n");

  spi.select_mode(1);

  printf("Select slave 1\n");

  spi.select_slave(1);
  
  
  printf("Writing \n");
  
  printf("WR:  data = 0xaced\n");
  data=0xaced;
  spi.transmit();
  sc_start(10,SC_NS);

  printf("WR:  data = 0xbeef\n");
  data=0xbeef;
  spi.transmit();
  sc_start(10,SC_NS);

  printf("WR:  data = 0xdead\n");
  data = 0xdead;
  spi.transmit();
  sc_start(10,SC_NS);

  printf("WR:  data = 0x1234\n");
  data = 0x1234;
  spi.transmit();
  sc_start(10,SC_NS);
  




  
  
  cout << "@" << sc_time_stamp()<< endl;
  
  cout << "Reading in zero time" <<endl; 
  spi.receive();
  sc_start(10,SC_NS);
  cout<< "data=" << hex << data.read() << endl;
  spi.receive();
  sc_start(10,SC_NS);
  cout<< "data=" << hex << data.read() << endl;
  spi.receive();
  sc_start(10,SC_NS);
  cout<< "data=" << hex << data.read() << endl;
  spi.receive();
  sc_start(10,SC_NS);
  cout<< "data=" << hex << data.read() << endl;
  
  cout << "@" << sc_time_stamp()<< endl;  

  cout << "@" << sc_time_stamp() <<" Terminating simulation\n" << endl;
  sc_close_vcd_trace_file(wf);
  return 0;// Terminate simulation

 }
