#include <systemc.h>
#include "uart.cpp"

// https://forums.accellera.org/topic/24-systemc-230-with-main/
int sc_main (int argc, char* argv[]) {
  int data;
  
  uart uart("uart");
            
  // Open VCD file
  sc_trace_file *wf = sc_create_vcd_trace_file("uart");
  wf->set_time_unit(1, SC_NS);
  
  // Dump the desired signals
  sc_trace(wf, data, "data");
  
  sc_start(0,SC_NS);
  cout << "@" << sc_time_stamp()<< endl;

  cout << "Write start Command\n" << endl;
  std::string START_COMMAND = "START";
  uart.sendCommand(START_COMMAND);

  cout << "Simulating response\n" << endl;
  uart.setRxData("OK");

  cout << "Reading response\n" << endl;
  std::string response = uart.readCommand(1);
  cout << "Readed value " << response << endl;


  return 0;

  
 }


