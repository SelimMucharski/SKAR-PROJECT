#ifndef CAN_H
#define CAN_H
#include <Arduino.h>
#include <SPI.h>
#include <mcp2515.h>
#include "Constants.h"

class Can: public MCP2515{
  int id;
  public:
    Can();
    void set_id(int new_id);

    void send_byte(byte* b, int data_lenght);
    void send_data(float data);
    void send_data(int data);
    void send_data(long data);
};

#endif