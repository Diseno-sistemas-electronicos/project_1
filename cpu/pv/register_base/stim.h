#ifndef STIM_H
#define STIM_H

#include <systemc.h>
							    
SC_MODULE(stim) {
		sc_in<bool> clock;
	
		sc_out<bool> enable;			// Available to read/write
		sc_out<bool> write;			// write if true; read if false
		sc_out<sc_uint<8> > addressSource1;	// Addressing first operand
		sc_out<sc_uint<8> > addressSource2;	// Addressing second operand 
		sc_out<sc_uint<9> > addressDest;		// Addressing destination operand 
		sc_out<sc_uint<32> > dataToWrite; 		// Data to be written

  	void ps1() {	
		enable.write(false);
		write.write(false);
		addressSource1.write("0b00000000");
		addressSource2.write("0b00000000");
		addressDest.write("0b000000000");
		dataToWrite.write("0x000000000");
		wait();
		
		enable.write(false);
		write.write(false);
		addressSource1.write("0b00000000");
		addressSource2.write("0b00000000");
		addressDest.write("0b000000000");
		dataToWrite.write("0x000000000");
		wait();
		
		enable.write(false);
		write.write(false);
		addressSource1.write("0b00000000");
		addressSource2.write("0b00000000");
		addressDest.write("0b000000000");
		dataToWrite.write("0x000000000");
		wait();

		sc_stop();							// End simulation
	}

	SC_CTOR(stim) {	 
      	SC_THREAD(ps1);						// Run ps1 only ones
		sensitive << clock.pos();
    }
};
#endif

