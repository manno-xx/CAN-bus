# CAN bus
Example of Arduino to Arduino communication using CAN bus (MCP2515)

Example uses the MPC2515 library mentioned below. There are other libraries that do the same thing. 

## Hardware used
All available at the Makerspace(s). Upstairs does not have the MCP2515, but _does_ have a bunch of OLEDs. Both have various types of Arduino's.

128x64 OLED [https://www.otronic.nl/en/mini-oled-display-white-096-inch-128x64-i2c.html](https://www.otronic.nl/en/mini-oled-display-white-096-inch-128x64-i2c.html)

MCP2515 CAN bus module [https://www.otronic.nl/en/can-bus-module-mcp2515-spi-5v.html](https://www.otronic.nl/en/can-bus-module-mcp2515-spi-5v.html)

## Libraries used
MCP2515 [https://github.com/autowp/arduino-mcp2515](https://github.com/autowp/arduino-mcp2515) (<- see instructions for installing)

OLED [https://github.com/adafruit/Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306) (Install using Arduino IDE Library Manager (look for _Adafruit SSD1306_)

## Set up
See [https://how2electronics.com/interfacing-mcp2515-can-bus-module-with-arduino/](https://how2electronics.com/interfacing-mcp2515-can-bus-module-with-arduino/) for wiring the MCP2515 CAN bus break out boards

See [https://learn.adafruit.com/monochrome-oled-breakouts/arduino-library-and-examples](https://learn.adafruit.com/monochrome-oled-breakouts/arduino-library-and-examples) for OLED Examples

### The actual thing
![CAN bus example project](https://github.com/manno-xx/CAN-bus/blob/main/IMG_0449.jpeg "CAN bus example project")
