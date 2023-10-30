#include <Wire.h>
#define TARGET_ADDR 0xBE

void init_i2c_bus(){
  Wire.begin();
}

void i2c_send_data(int target_address, char * data_buffer)
{
  Wire.beginTransmission(target_address);
  Wire.write(data_buffer);
  Wire.endTransmission(); // stop transmitting
  delay(100);
}

void reset_relays(){
  i2c_send_data(TARGET_ADDR, "01"); 
  i2c_send_data(TARGET_ADDR, "11"); 
  i2c_send_data(TARGET_ADDR, "21"); 
  i2c_send_data(TARGET_ADDR, "31");
}
