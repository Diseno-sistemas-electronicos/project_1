//-----------------------------------------------------
#include "systemc.h"

#include <unistd.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#define BUFFER_SIZE 32

SC_MODULE (uart) {
    
  //-----------Internal variables-------------------
  std::string tx_data;              // Simulates the tx line
  std::string rx_data;              // Simulates the rx line
  std::string buffer[BUFFER_SIZE];  // Buffer for readings
  int lastIndex;                // Index of last reading

  // Constructor for memory
  //SC_CTOR(uart) {
  SC_HAS_PROCESS(uart);
    uart(sc_module_name uart, int tx_port=12 ,int rx_port=13,int baudrate=115200) : sc_module(uart) {
  } // End of Constructor

   //------------Code Starts Here-------------------------

  
  /*
  * This function set a value in tx line for testing
  */
  void setTxData(std::string data){
    this->tx_data = data;
  }

  /*
  * This function set a value in rx line for testing
  */
  void setRxData(std::string data){
    this->rx_data = data;
  }
  /*
  * This function allows to put a command in the tx line byte by byte
  */
  void sendCommand(std::string command){
    for(uint i = 0; i < command.length(); i+=2){
      writeByte(command.substr(i,2));
    }
  }

  /*
  * This function allows to read data from rx buffer 
  */
  std::string readCommand(){
    std::string command = "";
    for(int i = 0 ; i < BUFFER_SIZE; i++){
      command = command + readByte();
    }
    return command;
  }

  /*
  * This function write single byte in the tx line
  */
  void writeByte(std::string data) {
    this->tx_data = data;
  }

  /*
  * This function reads single byte in the rx line
  */
  std::string readByte() {
    if(lastIndex < BUFFER_SIZE){
      buffer[this->lastIndex] = this->rx_data;
      this->lastIndex++;
    } else {
      this->lastIndex=0;
      buffer[this->lastIndex] = this->rx_data;
    }
    return this->rx_data;
  }
  
}; // End of UART Module
