#ifndef STIM_H
#define STIM_H

#include <systemc.h>
							    
SC_MODULE(stim) {
		sc_in<bool> clock;

		sc_out<sc_uint<64> > instructionIn;
		sc_out<bool> enable;
		sc_out<bool> write;



  	void ps1() {	
		instructionIn.write("0x1234000000000000");
		enable.write(false);
		write.write(false);
		wait();
		
		instructionIn.write("0x0000000000001234");
		enable.write(false);
		write.write(false);
		wait();
		
		instructionIn.write("0x0000123400000000");
		enable.write(false);
		write.write(false);
		wait();

		sc_stop();							// End simulation
	}

	SC_CTOR(stim) {	 
      	SC_THREAD(ps1);						// Run ps1 only ones
		sensitive << clock.pos();
    }
};
#endif

