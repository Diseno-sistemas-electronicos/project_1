#include <systemc.h>

#include "control.cpp"
#include "stim.h"

int sc_main(int argc, char* argv[])
{
		//-- Signals --//
		//-- In --//
		sc_clock clock("clock",10,SC_NS,0.5);	// Create a clock signal
		sc_signal<sc_uint<4> > opcode;	// OPCODE
		sc_signal<sc_uint<8> > of1;		// Operando fonte 1
		sc_signal<sc_uint<8> > of2;		// Operando fonte 2
		sc_signal<sc_uint<9> > opd;		// Operando destino
		sc_signal<bool> N;
		sc_signal<bool> Z;

		//-- Out --//
		// Program counter control
		sc_signal<bool> enableCP;
		sc_signal<bool> loadCP;
		sc_signal<bool> resetCP;
		sc_signal<sc_uint<9> > jumpValueCP;

		// Instruction memory control
		sc_signal<bool> enableIM;
		sc_signal<bool> writeIM;

		// Data memory control;
		sc_signal<bool> enableDM;
		sc_signal<bool> writeDM;

		// Instruction register control
		sc_signal<bool> enableRI;
		sc_signal<bool> writeRI;
		sc_signal<sc_uint<8> > immediateValue;
		sc_signal<sc_uint<9> > immediateRegister;

		// Register base control
		sc_signal<bool> enableRB;
		sc_signal<bool> writeRB;

		// Register pipeline
		sc_signal<bool> enableRPL;
		sc_signal<bool> writeRPL;
		sc_signal<bool> resetRPL;

		// ULA control
		sc_signal<bool> resetZN;

		// Multiplex for write data on register base
		sc_signal<sc_uint<2> > seletorMultiRBW;

		// Multiplex for addressing DM
		sc_signal<sc_uint<2> > seletorMultiDM;


		sc_trace_file *fp;					// Create VCD file
		fp=sc_create_vcd_trace_file("wave");// open(fp), create wave.vcd file
		fp->set_time_unit(1, SC_NS);		// set tracing resolution to ns
		
		control DUT("control");
		
		DUT.clock(clock);
		DUT.opcode(opcode);
		DUT.of1(of1);
		DUT.of2(of2);
		DUT.opd(opd);
		DUT.N(N);
		DUT.Z(Z);
		

		//-- Out --//
		// Program counter control
		DUT.enableCP(enableCP);
		DUT.loadCP(loadCP);
		
		DUT.resetCP(resetCP);
		DUT.jumpValueCP(jumpValueCP);
		

		// Instruction memory control
		DUT.enableIM(enableIM);
		DUT.writeIM(writeIM);
	
		// Data memory control;
		DUT.enableDM(enableDM);
		DUT.writeDM(writeDM);
		
		// Instruction register control
		DUT.enableRI(enableRI);
		DUT.writeRI(writeRI);
		DUT.immediateValue(immediateValue);
		DUT.immediateRegister(immediateRegister);

		// Register base control
		DUT.enableRB(enableRB);
		DUT.writeRB(writeRB);

		// Register pipeline
		DUT.enableRPL(enableRPL);	
		DUT.writeRPL(writeRPL);
		DUT.resetRPL(resetRPL);

		// ULA control
		DUT.resetZN(resetZN);

		// Multiplex for write data on register base
		DUT.seletorMultiRBW(seletorMultiRBW);
		
		// Multiplex for addressing DM
		DUT.seletorMultiDM(seletorMultiDM);
		
		stim STIM("stimulus");				// Instantiate stimulus generator
		STIM.clock(clock);
		STIM.opcode(opcode);
		STIM.of1(of1);
		STIM.of2(of2);
		STIM.opd(opd);
		STIM.N(N);
		STIM.Z(Z);
		
		sc_trace(fp,clock,"clock");	
		sc_trace(fp,opcode,"opcode");
		sc_trace(fp,of1,"of1");
		sc_trace(fp,of2,"of2");
		sc_trace(fp,opd,"opd");
		sc_trace(fp,N,"N");
		sc_trace(fp,Z,"Z");
			
		sc_trace(fp,DUT.enableCP,"DUT.enableCP");


		sc_trace(fp,DUT.loadCP,"DUT.loadCP");
		
		sc_trace(fp,DUT.resetCP,"DUT.resetCP");

		sc_trace(fp,DUT.jumpValueCP,"DUT.jumpValueCP");
	// Instruction memory control
		sc_trace(fp,DUT.enableIM,"DUT.enableIM");

		sc_trace(fp,DUT.writeIM,"DUT.writeIM");
		// Data memory control;
		sc_trace(fp,DUT.enableDM,"DUT.enableDM");
		sc_trace(fp,DUT.writeDM,"DUT.writeDM");
		// Instruction register control
		sc_trace(fp,DUT.enableRI,"DUT.enableRI");
		sc_trace(fp,DUT.writeRI,"DUT.writeRI");
		sc_trace(fp,DUT.immediateValue,"DUT.immediateValue");
		sc_trace(fp,DUT.immediateRegister,"DUT.immediateRegister");
		

		// Register base control
		sc_trace(fp,DUT.enableRB,"DUT.enableRB");
		sc_trace(fp,DUT.writeRB,"DUT.writeRB");
		
		// Register pipeline
		sc_trace(fp,DUT.enableRPL,"DUT.enableRPL");
		sc_trace(fp,DUT.writeRPL,"DUT.writeRPL");	
		sc_trace(fp,DUT.resetRPL,"DUT.resetRPL");
		
		// ULA control
		sc_trace(fp,DUT.resetZN,"DUT.resetZN");

		// Multiplex for write data on register base
		sc_trace(fp,DUT.seletorMultiRBW,"DUT.seletorMultiRBW");
		
		// Multiplex for addressing DM
		sc_trace(fp,DUT.seletorMultiDM,"DUT.seletorMultiDM");
		
		sc_start(100, SC_NS);			   	// Run simulation

		sc_close_vcd_trace_file(fp);		// close(fp)

		return 0;							// Return OK, no errors.		

}