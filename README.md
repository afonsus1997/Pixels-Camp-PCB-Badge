# Pixels Camp PCB Badge

## Latest Updates
* Waiting for parts
* Waiting for devboard

## Info
This is a PCB badge for the 2019 edition of pixels camp. The project consists on a 39x9 (351) LED matrix display driven by the IS31FL3741 IC and controlled by an ESP32, making it wifi-connected. The board can be powered by usb and/or a 1s lipo battery (charges with usb).

The main goal is to make a web connected scrolling text display, although anyone can develop a custom version of the firmware.

**Special thanks to ISSI for supporting the project by supplying a devboard for the IS31FL3741 IC, much apreciated!**

## Circuit and PCB

### Circuit

#### Power
Power is supplied by usb and/or 1s lipo, with usb charging capabilities.

Used ICs:
* Voltage Regulator: NCP708
    * [Datasheet](https://www.onsemi.com/pub/Collateral/NCP708-D.PDF)
* Lipo charger: MCP73831T-2ADI/OT
    * [Datasheet](https://www.sparkfun.com/datasheets/Prototyping/Batteries/MCP73831T.pdf)

#### Digital and logic
The microcontroller used is the ESP32 with WIFI and bluetooth built-in. The LED matrix is driven by the IS31FL3741 IC. The usb to serial conversion in handled by the CH340G (with auto-reset DTR capabilities).

Used ICs:
* uC: ESP32
    * [Datasheet](https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf)
* USB-to-Serial: CH340G
    * [Datasheet](https://cdn.sparkfun.com/datasheets/Dev/Arduino/Other/CH340DS1.PDF)
* LED driver: IS31FL3741
    * [Datasheet](http://ams.issi.com/WW/pdf/IS31FL3741.pdf)

### PCBs
The PCBs was designed in Altium Designer and the most recent GERBERs and schematics are available in their respective repo folders. The Badge consists of 2 stackable PCBs, one for the matrix and one for the power and logic. Each PCB is 126x36mm and there is a panel PCB with both of the PCBs held by cuttable tabs. The panel is 140x91mm.

#### IO
Placeholder


#### Renders

##### 2D 
![TOP](https://github.com/afonsus1997/0603-Led-Matrix/blob/master/PCB%20ESP32/PDF/PANEL/PCB%20Prints-1.jpg)
![BOT](https://github.com/afonsus1997/0603-Led-Matrix/blob/master/PCB%20ESP32/PDF/PANEL/PCB%20Prints-2.jpg)

##### 3D
![TOP](https://github.com/afonsus1997/0603-Led-Matrix/blob/master/PCB%20ESP32/PDF/PANEL/3D%20Prints-1.jpg)
![BOT](https://github.com/afonsus1997/0603-Led-Matrix/blob/master/PCB%20ESP32/PDF/PANEL/3D%20Prints-2.jpg)



