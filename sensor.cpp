#include "sensor.h"

void Sensor::set_loadcell(LoadCell *loadcell, int index, float amplitude=1){
  if (index < 0 or index > LOADCELLS_NUMBER){
    return;
  }
  loadcells[index] = loadcell;
  amplitudes[index] = amplitude;
}

void Sensor::tare(){
  for(int i=0;i<LOADCELLS_NUMBER;i++){
    loadcells[i] -> tare();
  }
}

void Sensor::scale(float known_mass){
  for(int i=0;i<LOADCELLS_NUMBER;i++){
    loadcells[i] -> scale(known_mass);
  }
}

void Sensor::set_scales(float *scales){
  for(int i=0;i<LOADCELLS_NUMBER;i++){
    loadcells[i] -> set_scale(*scales+i);
  }
}

void Sensor::set_offsets(long *offsets){
  for(int i=0;i<LOADCELLS_NUMBER;i++){
    loadcells[i] -> set_offset(*offsets+i);
  }
}

float Sensor::get_sum(){
  float sum = 0;
  for(int i=0;i<LOADCELLS_NUMBER;i++){
    float weight = loadcells[i] -> weight();
    sum += weight;
  }

  return sum;
}

float* Sensor::get_scales(){
  float scales[10];

  for(int i=0; i<LOADCELLS_NUMBER;i++){
    scales[i] = loadcells[i] -> get_scale();
  }

  return scales;
}

long* Sensor::get_offsets(){
  long offsets[10];

  for(int i=0; i<LOADCELLS_NUMBER;i++){
    offsets[i] = loadcells[i] -> get_offset();
  }

  return offsets;
}