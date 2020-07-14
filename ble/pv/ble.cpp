//-----------------------------------------------------
#include "systemc.h"

#include <unistd.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#define BUFFER_SIZE 32
#define AMOUNT_DEVICES 5

SC_MODULE (ble) {
    
    //-----------Internal variables-------------------
    std::string mode;                               // Determinates the operating mode (transmitter/receiver)
    std::string mac_address;                        // Unique ID identifier for trasmission
    std::string buffer[BUFFER_SIZE];                // Buffer for readings
    std::string inputTestSignal[AMOUNT_DEVICES];    // Simulation for input signals 
    std::string ouputTestSignal;                    // Simulation of output signal in case of transmission


    int current;                                    // Simulate current value
    int vibration_x;                                // Simulate vibration in x axis 
    int vibration_y;                                // Simulate vibration in y axis 
    int vibration_z;                                // Simulate vibration in z axis 
    int lastIndex;                                  // Index of last reading

    // Constructor for memory
    //SC_CTOR(uart) {
    SC_HAS_PROCESS(ble);
    ble(sc_module_name ble, std::string mode, std::string mac_address) : sc_module(ble) {
        this->mac_address = mac_address;
        this->mode = mode;
    } // End of Constructor

    //------------Code Starts Here-------------------------

    /*
    * This function set a value in tx line for testing
    */
    void setMode(std::string mode){
        this->mode = mode;
    }

    /*
    * This function set a value in simulation variables
    */
    void setVariable(std::string variable,int value){
        if(variable == "current"){
            this->current = value;
        }
        else if(variable == "vibration_x"){
            this->vibration_x = value;
        } 
        else if(variable == "vibration_y"){
            this->vibration_y = value;
        }
        else if(variable == "vibration_z"){
            this->vibration_z = value;
        }
    }


    /*
    * This function set the unique machine id
    */
    void setMacAddress(std::string mac_address){
        this->mac_address = mac_address;
    }

    /*
    * This function encode a message according to variable
    */
    std::string encodeVariable(std::string variable, int value){
        std::stringstream stream;
        stream << std::hex << value;
        std::string result(stream.str());
        if(variable == "current"){
            return "A0"+result;
        }
        else if(variable == "vibration_x"){
            return "B0"+result;
        } 
        else if(variable == "vibration_y"){
            return "B1" + result;
        }
        else if(variable == "vibration_z"){
            return "B2"+ result;
        }
        else {
            return "";
        }
    }


    /*
    * This function encode a message according to message type
    */
    std::string encode(std::string message_type, std::string instruction) {
        if(message_type == "telemetry"){
            std::string raw_message = "0x" + this->mac_address + "10" + this->encodeVariable("current", this->current) + this->encodeVariable("vibration_x", this->vibration_x) + this->encodeVariable("vibration_y", this->vibration_y) + this->encodeVariable("vibration_z", this->vibration_z);
            return raw_message;
        }
        else if(message_type == "threshold_alert"){
            std::string raw_message = "0x" + this->mac_address + "20";
            return raw_message;
        } 
        else if(message_type == "vibration_alert"){
            std::string raw_message = "0x" + this->mac_address + "30";
            return raw_message;
        }
        else if(message_type == "status_report"){
            std::string raw_message = "0x" + this->mac_address + "40";
            return raw_message;
        }
        else {
            return "";
        }
    }

    /*
    * This function simulates the data transmission through BLE Protocol Stack
    */
    void transmitSignal(std::string message) {
        if(this->mode =="transmitter"){
                for(uint i = 0;i < message.length(); i+=2){
                    this-> emitByte(message.substr(i,2));
                }  
        }
    }

    /*
    * This function simulates the single byte transmission through BLE Protocol Stack
    */
    void emitByte(std::string byte){
        // Simulate byte modulation

    }

    /*
    * This function allows to fill the reception buffer
    */
    void receiveSignal(){
        if(this->mode == "receiver"){
            if(this->lastIndex < BUFFER_SIZE){
                buffer[this->lastIndex] = this->readFrame();
                this->lastIndex++;
            } 
            else {
                buffer[this->lastIndex] = this->readFrame();
                this->lastIndex = 0;
            }
        }
    }

    /*
    * This function allows to read a frame from BLE Stack
    */
    std::string readFrame() {
        // Simulate demodulating a frame
        srand (time(NULL));  
        int index = rand() % AMOUNT_DEVICES;  
        return this->inputTestSignal[index];
    }

}; // End of BLE Module
