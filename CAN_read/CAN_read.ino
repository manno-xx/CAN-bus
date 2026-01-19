// Mod from the example CAN bus (mpc2515) read example
// Mod from Adafruit SSD1306 OLED example
// Reads incoming CAN message and draws a bar on an OLED of the received value

// https://docs.arduino.cc/learn/communication/spi/
#include <SPI.h>

// libraries for the OLED 128x64
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// library for the CAN BUS board (https://github.com/autowp/arduino-mcp2515)
#include <mcp2515.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

struct can_frame canMsg;
MCP2515 mcp2515(10);

void setup() 
{
  Serial.begin(115200);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000);

  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS);
  mcp2515.setNormalMode();
  
  Serial.println("------- CAN Read ----------");
  Serial.println("ID  DLC   DATA");
}

void loop() 
{
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK)
  {
    // print out the entire message
    Serial.print(canMsg.can_id, HEX); // print message ID
    Serial.print(" "); 
    Serial.print(canMsg.can_dlc, HEX); // print message DLC (Data Length Code)
    Serial.print(" ");
    
    for (int i = 0; i<canMsg.can_dlc; i++)    // print the data
    {
      Serial.print(canMsg.data[i],HEX);
      Serial.print(" ");
    }

    Serial.println();

    // draw the bar on the OLED
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.write("Volume:");
    display.fillRect(0, 12, canMsg.data[0], 10, SSD1306_WHITE);
    display.display();
  }
}
