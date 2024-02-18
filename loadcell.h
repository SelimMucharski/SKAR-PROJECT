#ifndef LOADCELL_H
#define LOADCELL_H
#include <Arduino.h>
#include "HX711.h"
#include "Constants.h"

class LoadCell: public HX711{
  public:
    LoadCell(int dataPin, int sckPin);
    float weight();
    void scale(int known_weight);
};

#endif