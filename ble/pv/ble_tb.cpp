#include <systemc.h>
#include "ble.cpp"


// https://forums.accellera.org/topic/24-systemc-230-with-main/
int sc_main (int argc, char* argv[]) {
    int data;
    std::string mode = "transmitter";
    std::string mac_address = "AC223F03D1"; // Need to be read from system memory
    std::string message_type = "telemetry"; // Defined by the procesor
    std::string command = "AT$SFT=4,50,30,10"; // Defined by the procesor

    ble ble("ble", mode, mac_address);
            
    // Open VCD file
    sc_trace_file *wf = sc_create_vcd_trace_file("ble");
    wf->set_time_unit(1, SC_NS);

    // Dump the desired signals
    sc_trace(wf, data, "data");

    sc_start(0,SC_NS);
    cout << "@" << sc_time_stamp()<< endl;
    cout << "Simulating variable data.." << endl;

    srand (time(NULL)); 
    int current = rand() % 40;
    int vibration_x = rand() % 40;
    int vibration_y = rand() % 40;
    int vibration_z = rand() % 40;

    ble.setVariable("current",current);
    ble.setVariable("vibration_x",vibration_x);
    ble.setVariable("vibration_y",vibration_y);
    ble.setVariable("vibration_z",vibration_z);

    cout << "Encoding Message data.." << endl;
    std::string raw_message = ble.encode(message_type,command);
    cout << "Encoded Message: " << raw_message << endl;

    cout << "Transmitting Message: " << endl;
    ble.transmitSignal(raw_message);
    






    return 0;

  
 }