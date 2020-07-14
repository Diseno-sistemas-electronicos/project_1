#ifndef STIM_H
#define STIM_H

#include <systemc.h>
							    
SC_MODULE(stim) {
		sc_in<bool> clock;
	
		sc_out<bool> enable;		// Available to read/write
		sc_out<bool> write;		// write if true; read if false
		sc_out<sc_uint<9> > address;	// Addressing the memory for write/read
		sc_out<sc_uint<9> > dataIn; 		// Data to be written/read

  	void ps1() {	
		enable.write(false);
		write.write(false);
		address.write("0b000000000");
		dataIn.write("0b000000000");
		wait();
		
		enable.write(true);
		write.write(true);
		address.write("0b000000000");
		dataIn.write("0b000000101");
		wait();

		enable.write(true);
		write.write(true);
		address.write("0b000000000");
		dataIn.write("0b000000101");
		wait();
		
		enable.write(true);
		write.write(false);
		address.write("0b000000000");
		dataIn.write("0b000000000");
		wait();

		enable.write(true);
		write.write(false);
		address.write("0b000000000");
		dataIn.write("0b000000000");
		wait();

		enable.write(true);
		write.write(false);
		address.write("0b000000000");
		dataIn.write("0b000000000");
		wait();

		sc_stop();							// End simulation
	}

	SC_CTOR(stim) {	 
      	SC_THREAD(ps1);						// Run ps1 only ones
		sensitive << clock.pos();
    }
};
#endif

