#include "can.h"

Can::Can():MCP2515(CS_PIN){
  // reset();
  setBitrate(CAN_125KBPS);
  setNormalMode();
}

void Can::set_id(int new_id){
  id = new_id;
}

void Can::send_byte(byte * b, int data_lenght){
  struct can_frame canMsg;
  canMsg.can_id = id;
  canMsg.can_dlc = data_lenght;

  for(int i=0; i<data_lenght; i++){
    canMsg.data[i] = (b[i]);
  }

  sendMessage(&canMsg);
}

void Can::send_data(float data){
  int data_lenght = 4; // float jest 4 bytowy
  byte * b = (byte *) &data;
  send_byte(b, data_lenght);
}

void Can::send_data(int data){
  int data_lenght = 2;
  byte * b = (byte *) &data;
  send_byte(b, data_lenght);
}

void Can::send_data(long data){
  int data_lenght = 4; // float jest 4 bytowy
  byte * b = (byte *) &data;
  send_byte(b, data_lenght);
}