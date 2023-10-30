#include "i2c_slave.h"
#include "relay.h"

void setup(){
  init_i2c_bus();
  init_control_relays();
}

void loop(){
  drive_relays(command);
  delay(100);
}
