#include <systemc.h>

#include "register_base.h"
#include "stim.h"

int sc_main(int argc, char* argv[])
{
		//-- Signals --//
		//-- In --//
		sc_clock clock("clock",10,SC_NS,0.5);	// Create a clock signal
	
		sc_signal<bool> enable;			// Available to read/write
		sc_signal<bool> write;			// write if true; read if false
		sc_signal<sc_uint<8> > addressSource1;	// Addressing first operand
		sc_signal<sc_uint<8> > addressSource2;	// Addressing second operand 
		sc_signal<sc_uint<9> > addressDest;		// Addressing destination operand 
		sc_signal<sc_uint<32> > dataToWrite; 		// Data to be written
		sc_signal<sc_uint<32> > dataSource1; 		// Data for the first operand
		sc_signal<sc_uint<32> > dataSource2; 		// Data for the second operand
	
	
		sc_trace_file *fp;					// Create VCD file
		fp=sc_create_vcd_trace_file("wave");// open(fp), create wave.vcd file
		fp->set_time_unit(1, SC_NS);		// set tracing resolution to ns
		
		register_base DUT("register_base");
		
		DUT.clock(clock);
		DUT.enable(enable);
		DUT.write(write);
		DUT.addressSource1(addressSource1);
		DUT.addressSource2(addressSource2);
		DUT.addressDest(addressDest);
		DUT.dataToWrite(dataToWrite);
		DUT.dataSource1(dataSource1);
		DUT.dataSource2(dataSource2);
		
		stim STIM("stimulus");				// Instantiate stimulus generator
		STIM.clock(clock);
		STIM.enable(enable);
		STIM.write(write);
		STIM.addressSource1(addressSource1);
		STIM.addressSource2(addressSource2);
		STIM.addressDest(addressDest);
		STIM.dataToWrite(dataToWrite);
			
		sc_trace(fp,clock,"clock");	
		sc_trace(fp,enable,"enable");
		sc_trace(fp,write,"write");
		sc_trace(fp,addressSource1,"addressSource1");
		sc_trace(fp,addressSource2,"addressSource2");
		sc_trace(fp,addressDest,"addressDest");
		sc_trace(fp,dataToWrite,"dataToWrite");
		sc_trace(fp,dataSource1,"dataSource1");
		sc_trace(fp,dataSource2,"dataSource2");
		
		sc_start(100, SC_NS);			   	// Run simulation

		sc_close_vcd_trace_file(fp);		// close(fp)

		return 0;							// Return OK, no errors.		

}