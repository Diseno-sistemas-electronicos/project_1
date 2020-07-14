#ifndef STIM_H
#define STIM_H

#include <systemc.h>
							    
SC_MODULE(stim) {
		sc_in<bool> clock;

		sc_out<sc_int<32> > a;
		sc_out<sc_int<32> > b;
		sc_out<sc_uint<4> > operacao;
		sc_out<bool> reset; // reset Z and N

  	void ps1() {	
		a.write("0x00000000");
		b.write("0x00000000");
		operacao.write("0b0000");
		reset.write(false);
		wait();
		
		a.write("0x00000000");
		b.write("0x00000000");
		operacao.write("0b0000");
		reset.write(false);
		wait();
		
		a.write("0x00000000");
		b.write("0x00000000");
		operacao.write("0b0000");
		reset.write(false);
		wait();

		sc_stop();							// End simulation
	}

	SC_CTOR(stim) {	 
      	SC_THREAD(ps1);						// Run ps1 only ones
		sensitive << clock.pos();
    }
};
#endif

