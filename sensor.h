#ifndef SENSOR_H
#define SENSOR_H
#include <Arduino.h>
#include "loadcell.h"
#include "Constants.h"

class Sensor{
  LoadCell *loadcells[10];
  float amplitudes[10];
  public:
    void set_loadcell(LoadCell *loadcell, int index, float amplitude=1);
    void tare();
    void scale(float known_mass);
    float get_sum();

    float* get_scales();
    long* get_offsets();

    void set_scales(float *scales);
    void set_offsets(long *offsets);
};


#endif