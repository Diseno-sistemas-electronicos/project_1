#ifndef STIM_H
#define STIM_H

#include <systemc.h>
							    
SC_MODULE(stim) {
		sc_in<bool> clock;

		sc_out<bool> enable;		// Available to read/write
		sc_out<bool> write;		// write if 1; read if 0
		sc_out<sc_uint<4> > opcodeIn;	// OPCODE
		sc_out<sc_uint<8> > of1In;	// Operando Fuente 1
		sc_out<sc_uint<8> > of2In;	// Operando Fuente 2
		sc_out<sc_uint<9> > odIn;		// Operando destino

  	void ps1() {	
		enable.write(false);
		write.write(false);
		opcodeIn.write("0b0000");
		of1In.write("0b00000000");
		of2In.write("0b00000000");
		odIn.write("0b000000000");
		wait();
		
		enable.write(false);
		write.write(false);
		opcodeIn.write("0b0000");
		of1In.write("0b00000000");
		of2In.write("0b00000000");
		odIn.write("0b000000000");
		wait();
		
		enable.write(false);
		write.write(false);
		opcodeIn.write("0b0000");
		of1In.write("0b00000000");
		of2In.write("0b00000000");
		odIn.write("0b000000000");
		wait();

		sc_stop();							// End simulation
	}

	SC_CTOR(stim) {	 
      	SC_THREAD(ps1);						// Run ps1 only ones
		sensitive << clock.pos();
    }
};
#endif

