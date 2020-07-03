#include <systemc.h>
#include "memory.cpp"

SC_MODULE (testbench) {
 
  int data;
  ram *mem;
    
  SC_HAS_PROCESS(testbench);
    testbench(sc_module_name testbench, int size=8) {
      mem = new ram("mem",size);    	
    SC_THREAD(test);
         
  } 
  void test() {
    printf("WR: addr = 0x10, data = 0xaced\n");
    mem->write(0x10, 0xaced);
    wait(3,SC_NS);
    data = mem->read(0x10);
    printf("Rd: addr = 0x10, data = %x\n",data);
    
    printf("WR: addr = 0x11, data = 0xbeef\n");
    printf("WR: addr = 0x12, data = 0xdead\n");
    printf("WR: addr = 0x13, data = 0x1234\n");
    mem->write(0x11, 0xbeef);
    wait(1,SC_NS);
    mem->write(0x12, 0xdead);
    wait(1,SC_NS);
    mem->write(0x13, 0x1234);
    wait(1,SC_NS);
    
    wait(1,SC_NS);
    data = mem->read(0x10);
    wait(1,SC_NS);
    printf("Rd: addr = 0x10, data = %x\n",data);
  
    data = mem->read(0x11);
    wait(1,SC_NS);
    printf("Rd: addr = 0x11, data = %x\n",data);
  
    data = mem->read(0x12);
    wait(1,SC_NS);
    printf("Rd: addr = 0x12, data = %x\n",data);
  
    data = mem->read(0x13);
    wait(1,SC_NS);
    printf("Rd: addr = 0x13, data = %x\n",data); 
  }
};

int sc_main (int argc, char* argv[]) {
 
  
  
  testbench tb("tb",1024);
            
  // Open VCD file
  sc_trace_file *wf = sc_create_vcd_trace_file("memory");
  wf->set_time_unit(1, SC_NS);
  
  // Dump the desired signals
  sc_trace(wf, tb.data, "data");
  sc_trace(wf, tb.mem->mem[0x10], "data_10");
  sc_trace(wf, tb.mem->mem[0x11], "data_11");
  sc_trace(wf, tb.mem->mem[0x12], "data_12");
  sc_trace(wf, tb.mem->mem[0x13], "data_13");

  
  sc_start();
     
  cout << "@" << sc_time_stamp() <<" Terminating simulation\n" << endl;
  sc_close_vcd_trace_file(wf);
  
  return 0;// Terminate simulation

  
};



