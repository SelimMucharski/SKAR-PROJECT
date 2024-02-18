#include "loadcell.h"
#include "can.h"
#include "sensor.h"

const float KNOWN_MASS = 429; // masa w gramach

const long OFFSET = 4294868745;
const float SCALE = -374.9;

Sensor sensor;
Can CanShield;


void scale_with_mass(){
  Serial.println("Remove all mass");
  delay(3000);
  sensor.tare();

  Serial.println("Put known mass");
  delay(3000);
  sensor.scale(KNOWN_MASS);
}

void send_weight(){
  float weight = sensor.get_sum();
  Serial.println(weight, 1);
  CanShield.send_data(weight);
}

void setup(){
  Serial.begin(38400);

  // TWORZENIE LOADCELL'I
  for(int i=0;i<LOADCELLS_NUMBER;i++){
    LoadCell l(LOADCELL_DOUT_PINS[i], LOADCELL_SCK_PIN);
    sensor.set_loadcell(&l, i);
  }

  // SKALOWANIE LOADCELL'I
  float scales = {SCALE};
  sensor.set_scales(&scales);
  sensor.tare();

  // USTAWIENIA CANSHIELD'A
  CanShield.set_id(SENSOR_ID);
}

void loop(){
  struct can_frame canMsg;
  if (CanShield.readMessage(&canMsg) == MCP2515::ERROR_OK){
    canid_t id = canMsg.can_id;
    if(id == SENSOR_ID){
      uint8_t operactionID = canMsg.data[0];

      switch(operactionID){
        case 0:
          sensor.tare();
        case 1:
          send_weight();
        default:
          Serial.write("Unknown operaction", 1);
      }
    }
  }

  float weight = sensor.get_sum();
  Serial.println(weight, 1);
  
}