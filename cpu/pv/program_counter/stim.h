#ifndef STIM_H
#define STIM_H

#include <systemc.h>
							    
SC_MODULE(stim) {
		sc_in<bool> clock;
	
		sc_out<bool> reset;
		sc_out<bool> enable;
		sc_out<bool> load;
		sc_out<sc_uint<9> > counter_in;

  	void ps1() {	
		reset.write(false);
		enable.write(false);
		load.write(false);
		counter_in.write("0b000000000");
		wait();
		
		reset.write(false);
		enable.write(false);
		load.write(false);
		counter_in.write("0b000000000");
		wait();
		
		reset.write(false);
		enable.write(false);
		load.write(false);
		counter_in.write("0b000000000");
		wait();

		sc_stop();							// End simulation
	}

	SC_CTOR(stim) {	 
      	SC_THREAD(ps1);						// Run ps1 only ones
		sensitive << clock.pos();
    }
};
#endif

