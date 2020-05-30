#include<Wire.h>
#include<pgmspace.h>
#define Addr_GND 0x60
#define R 0xFF
#define G 0xFF
#define B 0xFF
#define byte uint8_t
#define MAXPWM 40
#define TIME 0
#define KEEPTIME 100
#define STEP 4
uint8_t i,j;
const PROGMEM byte PWM_Gama64[64]=
{
 0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
 0x08,0x09,0x0b,0x0d,0x0f,0x11,0x13,0x16,
 0x1a,0x1c,0x1d,0x1f,0x22,0x25,0x28,0x2e,
 0x34,0x38,0x3c,0x40,0x44,0x48,0x4b,0x4f,
 0x55,0x5a,0x5f,0x64,0x69,0x6d,0x72,0x77,
 0x7d,0x80,0x88,0x8d,0x94,0x9a,0xa0,0xa7,
 0xac,0xb0,0xb9,0xbf,0xc6,0xcb,0xcf,0xd6,
 0xe1,0xe9,0xed,0xf1,0xf6,0xfa,0xfe,0xff
};

void IS_IIC_WriteByte(uint8_t Dev_Add,uint8_t Reg_Add,uint8_t Reg_Dat)
{
 Wire.beginTransmission(Dev_Add/2); // transmit to device IS31FL373x
 Wire.write(Reg_Add); // sends regaddress
 Wire.write(Reg_Dat); // sends regaddress
 Wire.endTransmission(); // stop transmitting
}

void Init_3741(uint8_t Rdata, uint8_t Gdata, uint8_t Bdata)
{
    IS_IIC_WriteByte(Addr_GND,0xfe,0xc5);//unlock
    IS_IIC_WriteByte(Addr_GND,0xfD,0x02);//write page 2
    for(i=2;i<0xB4;i+=3)
        {
            IS_IIC_WriteByte(Addr_GND,i,Rdata);//R LED Scaling
        }
    for(i=1;i<0xB4;i+=3)
    {
        IS_IIC_WriteByte(Addr_GND,i,Gdata);//G LED Scaling
    }
    for(i=0;i<0xB4;i+=3)
    {
        IS_IIC_WriteByte(Addr_GND,i,Bdata);//B LED Scaling
    }
    IS_IIC_WriteByte(Addr_GND,0xfe,0xc5);//unlock
    IS_IIC_WriteByte(Addr_GND,0xfD,0x03);//write page 3
    for(i=2;i<0xAB;i+=3)
    {
        IS_IIC_WriteByte(Addr_GND,i,Rdata);//R LED Scaling
    }
    for(i=1;i<0xAB;i+=3)
    {
        IS_IIC_WriteByte(Addr_GND,i,Gdata);//G LED Scaling
    }
    for(i=0;i<0xAB;i+=3)
    {
        IS_IIC_WriteByte(Addr_GND,i,Bdata);//B LED Scaling
    }
    IS_IIC_WriteByte(Addr_GND,0xfe,0xc5);//unlock
    IS_IIC_WriteByte(Addr_GND,0xfD,0x00);//write page 0
    for(i=0;i<0xB4;i++)
    {
        IS_IIC_WriteByte(Addr_GND,i,0x00);//write all PWM set 0x00
    }
    IS_IIC_WriteByte(Addr_GND,0xfe,0xc5);//unlock
    IS_IIC_WriteByte(Addr_GND,0xfD,0x01);//write page 1
    for(i=0;i<0xAB;i++)
    {
        IS_IIC_WriteByte(Addr_GND,i,0x00);//write all PWM set 0x00
    } //init all the PWM data to 0

    IS_IIC_WriteByte(Addr_GND,0xfe,0xc5);//unlock
    IS_IIC_WriteByte(Addr_GND,0xfD,0x04);//write page 4
    IS_IIC_WriteByte(Addr_GND,0x01,0x7F);//global current
    IS_IIC_WriteByte(Addr_GND,0x00,0x01);//normal operation
}

void IS31FL3741_Test_mode1(void)
{
    //IS_IIC_WriteByte(Addr_GND,0xFD,0x00);//write frist frame
    while(1){
    
        
        j=0;

   
    for (j=0;j<MAXPWM;j+=STEP)//all LED ramping up
    {
        IS_IIC_WriteByte(Addr_GND,0xfe,0xc5);//unlock
        IS_IIC_WriteByte(Addr_GND,0xfD,0x00);//write page 0
        for(i=0;i<0xB4;i++)
        {
            IS_IIC_WriteByte(Addr_GND,i,j);//set all PWM
            //IS_IIC_WriteByte(Addr_GND,i,pgm_read_byte_near(&PWM_Gama64[j]));//set all PWM
        }
        IS_IIC_WriteByte(Addr_GND,0xfe,0xc5);//unlock
        IS_IIC_WriteByte(Addr_GND,0xfD,0x01);//write page 1
        for(i=0;i<0xAB;i++)
        {
        IS_IIC_WriteByte(Addr_GND,i,j);//set all PWM
        }
        delay(TIME);//10ms
    }
    delay(KEEPTIME); //keep on 1s

    for (j=MAXPWM;j>0;j-=STEP)//all LED ramping down
    {
    IS_IIC_WriteByte(Addr_GND,0xfe,0xc5);//unlock
    IS_IIC_WriteByte(Addr_GND,0xfD,0x00);//write page 0
    for(i=0;i<0xB4;i++)
    {
    IS_IIC_WriteByte(Addr_GND,i,j);//set all PWM
    //IS_IIC_WriteByte(Addr_GND,i,pgm_read_byte_near(&PWM_Gama64[j-1]));//set all PWM

    }
    IS_IIC_WriteByte(Addr_GND,0xfe,0xc5);//unlock
    IS_IIC_WriteByte(Addr_GND,0xfD,0x01);//write page 1
    for(i=0;i<0xAB;i++)
    {
    IS_IIC_WriteByte(Addr_GND,i,j);//set all PWM  pgm_read_byte_near(j)
    }
    delay(TIME);//10ms
    }
    delay(KEEPTIME); //keep off 0.5s
  

    }
} 

void setup() {
 Wire.begin(23,22);
 Wire.setClock(800000);//I2C 1MHz
 Init_3741(R, G, B);
 IS31FL3741_Test_mode1();//breath mode
 
}
void loop() {
}

//SDA 23
//SCL 22


/*
#include <Wire.h>
#include <Arduino.h>
#define byte uint8_t
#define ADDR 0x30
#define Addr_GND 0x60

void IS_IIC_WriteByte(uint8_t Dev_Add,uint8_t Reg_Add,uint8_t Reg_Dat)
{
 Wire.beginTransmission(Dev_Add/2); // transmit to device IS31FL373x
 Wire.write(Reg_Add); // sends regaddress
 Wire.write(Reg_Dat); // sends regaddress
 Wire.endTransmission(); // stop transmitting
}

uint8_t x;

void setup() {

Wire.begin(23,22);
Serial.begin(9600);
Wire.setClock(400000); // choose 400 kHz I2C rate
Serial.println("Start i2c-test");

IS_IIC_WriteByte(Addr_GND, 0x01, 0xFF); //gcc
delay(10);


IS_IIC_WriteByte(Addr_GND, 0x00, 0x05); //config register
delay(10);



Wire.beginTransmission(ADDR);
Wire.write((byte)0xFC);
Wire.endTransmission();
Wire.beginTransmission(ADDR);
Wire.requestFrom(ADDR, (byte)1);
x = Wire.read();
Wire.endTransmission();
Serial.print("Check: ");Serial.println(x, HEX);
delay(10);

Wire.beginTransmission(ADDR);
Wire.write((byte)0x00);
Wire.endTransmission();
Wire.beginTransmission(ADDR);
Wire.requestFrom(ADDR, (byte)1);
x = Wire.read();
Wire.endTransmission();
Serial.print("Register: ");Serial.println(x, HEX);
delay(10);

Wire.beginTransmission(ADDR);
Wire.write((byte)0xF1);
Wire.endTransmission();
Wire.beginTransmission(ADDR);
Wire.requestFrom(ADDR, (byte)1);
x = Wire.read();
Wire.endTransmission();
Serial.print("OPEN/SHORT: ");Serial.println(x, HEX);
delay(10);

Wire.beginTransmission(ADDR);
Wire.write((byte)0x01);
Wire.endTransmission();
Wire.beginTransmission(ADDR);
Wire.requestFrom(ADDR, (byte)1);
x = Wire.read();
Wire.endTransmission();
Serial.print("Current: ");Serial.println(x, HEX);
delay(10);


}





void loop() {
byte error;

Serial.println("Try to contact");
uint8_t data = 0;
//IS_IIC_WriteByte(ADDR, 0xF1, 0xFC);

 Serial.println();

 int c = 1;

for(uint8_t i = 0x3; i<0x30;i++){
    Serial.print(i, HEX); Serial.print(" ");  
    Wire.beginTransmission(ADDR);
    //Wire.write((byte)0xFC);
    Wire.write((byte)i);
    Wire.endTransmission();
    Wire.beginTransmission(ADDR);
    Wire.requestFrom(ADDR, (byte)1);
    x = Wire.read();
    Wire.endTransmission();
    Serial.println(x, HEX);//Serial.print(" ");
    delay(50);
    c++;
    }


Serial.println("done");

while(1){
    delay(10);
}


}
*/

/*

#include <Arduino.h>
void setup(){
    pinMode(22, OUTPUT);
    pinMode(23, OUTPUT);
    
}

void loop(){
    digitalWrite(22, HIGH);
    digitalWrite(23, LOW);
    delay(100);
    digitalWrite(23, HIGH);
    digitalWrite(22, LOW);
    delay(100);
}*/
/*
#include <Arduino.h>
#include <Wire.h>

void scan(){
Serial.println(" Scanning I2C Addresses");
uint8_t cnt=0;
for(uint8_t i=0;i<128;i++){
  Wire.beginTransmission(i);
  uint8_t ec=Wire.endTransmission(true);
  if(ec==0){
    if(i<16)Serial.print('0');
    Serial.print(i,HEX);
    cnt++;
  }
  else Serial.print("..");
  Serial.print(' ');
  if ((i&0x0f)==0x0f)Serial.println();
  }
Serial.print("Scan Completed, ");
Serial.print(cnt);
Serial.println(" I2C Devices found.");
}

bool i2cReady(uint8_t adr){
uint32_t timeout=millis();
bool ready=false;
while((millis()-timeout<100)&&(!ready)){
	Wire.beginTransmission(adr);
	ready=(Wire.endTransmission()==0);
	}
return ready;
}


void setup(){
Serial.begin(9600);
Wire.begin(23,22);
scan();
Serial.println();
}

void loop(){}*/