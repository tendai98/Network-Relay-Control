#include "i2c_master.h"
#include "server.h"

void setup(){
  init_net();
  init_server();
  init_i2c_bus();
  reset_relays();
}

void loop()
{
  server_loop();
  delay(100);
}
