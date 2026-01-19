// Mod from the standard CAN bus (mpc2515) write example.
// Reads analogue on A0, sends data across CAN bus

// https://docs.arduino.cc/learn/communication/spi/
#include <SPI.h>

// library for the CAN BUS board (https://github.com/autowp/arduino-mcp2515)
#include <mcp2515.h>

struct can_frame canMsg1;
MCP2515 mcp2515(10);

int sensorPin = A0;
int sensorValue = 0;

void setup() 
{
  canMsg1.can_id  = 0x0F6;
  canMsg1.can_dlc = 1;
  canMsg1.data[0] = 0x8E;
  
  while (!Serial);
  Serial.begin(115200);
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS);
  mcp2515.setNormalMode();
  
  Serial.println("Example: Write to CAN");
}

void loop() 
{

  // Read the value of a potentiometer on pin A0 (see declaration above)
  sensorValue = analogRead(sensorPin);
  // map it to fit one byte _and_ to fit on the OLED on the receiving Arduino
  sensorValue = map(sensorValue, 0, 1024, 0, 128);

  // update the data of the CAN messate and send it
  canMsg1.data[0] = sensorValue;
  mcp2515.sendMessage(&canMsg1);
  
  delay(100);
}
