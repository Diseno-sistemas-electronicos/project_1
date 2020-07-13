#ifndef STIM_H
#define STIM_H

#include <systemc.h>
							    
SC_MODULE(stim) {
		sc_in<bool> clock;
		sc_out<sc_uint<4> > opcode;	// OPCODE
		sc_out<sc_uint<8> > of1;		// Operando F1
		sc_out<sc_uint<8> > of2;		// Operando F2
		sc_out<sc_uint<9> > opd;		// Operando destino
		sc_out<bool> N;
		sc_out<bool> Z;

  	void ps1() {	
		opcode.write("0b0000");
		of1.write("0b00000001");
		of2.write("0b00000001");
		opd.write("0b000000001");
		N.write(false);
		Z.write(false);
		wait();
		
		opcode.write("0b0001");
		of1.write("0b00000001");
		of2.write("0b00000001");
		opd.write("0b000000001");
		N.write(false);
		Z.write(false);
		wait();
		
		opcode.write("0b0001");
		of1.write("0b00000001");
		of2.write("0b00000001");
		opd.write("0b000000001");
		N.write(false);
		Z.write(false);
		wait();
		
		opcode.write("0b0001");
		of1.write("0b00000001");
		of2.write("0b00000001");
		opd.write("0b000000001");
		N.write(false);
		Z.write(false);
		wait();
		
		opcode.write("0b0001");
		of1.write("0b00000001");
		of2.write("0b00000001");
		opd.write("0b000000001");
		N.write(false);
		Z.write(false);
		wait();		

		sc_stop();							// End simulation
	}

	SC_CTOR(stim) {	 
      	SC_THREAD(ps1);						// Run ps1 only ones
		sensitive << clock.pos();
    }
};
#endif

