#include <Wire.h> 
#define TARGET_ADDR 0xBE

char command[4]={0, 0, 0, 0};

void i2c_recv_data(int);

void init_i2c_bus()
{
  Wire.begin(TARGET_ADDR);
  Wire.onReceive(i2c_recv_data);
}

void i2c_recv_data(int data_len)
{
  int index = 0;
  while (Wire.available())
  {
      command[index] = Wire.read();
      index++;
  }
}
