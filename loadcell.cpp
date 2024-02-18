#include "loadcell.h"

LoadCell::LoadCell(int dataPin, int sckPin)
{
  begin(dataPin, sckPin);
}

float LoadCell::weight()
{
  return get_units(5);
}

void LoadCell::scale(int known_weight)
{
  float factor = get_units(10)/known_weight;
  set_scale(factor);
}