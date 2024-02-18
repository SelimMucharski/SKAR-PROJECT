#ifndef CONSTATNS_H
#define CONSTATNS_H

#include <SPI.h>
#include <mcp2515.h>

const int CS_PIN = 8;
const int LOADCELL_SCK_PIN = 3;
const int LOADCELLS_NUMBER = 1;
const int LOADCELL_DOUT_PINS[10] = {2};
const canid_t SENSOR_ID = 10;

#endif