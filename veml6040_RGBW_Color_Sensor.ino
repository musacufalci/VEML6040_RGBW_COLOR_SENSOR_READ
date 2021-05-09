// I2C device found at address 0x10

#define VEML6040Adress 16
#include <Wire.h>

void setup()
{
   Serial.begin(9600); 
   Wire.begin();
}


void initSensor(int dataByteLow)     		//sensor start start or stop
{
   writeVEML6040(0,dataByteLow,0);   
}


void writeVEML6040(int commandOrder, int dataByteLow, int dataByteHigh)  
{
  Wire.beginTransmission(VEML6040Adress);       
  Wire.write(commandOrder);                     
  Wire.write(dataByteLow);                  //low byte send
  Wire.write(dataByteHigh);                 //high byte send
  Wire.endTransmission();                   //fin de transmission
}


int readVEML6040(int commandOrder)          //veri okumak için altprogram
{
  int data=0;                               //information transfer variable
  Wire.beginTransmission(VEML6040Adress);   //the beginning of communication
  Wire.write(commandOrder);                 //register address
  Wire.requestFrom(VEML6040Adress,2);       //Waiting for response
  
  while(Wire.available())                   //lorsque les deux donnée sont disponible
  {
    data  =  Wire.read();                	//LSB byte read
    data |=  Wire.read() << 8;           	
  }
  
  //Wire.endTransmission();
  Wire.endTransmission(false);
  return data;                    
}


void loop()
{  
  
  int Red, Green, Blue, White;    	//variables RGB
  initSensor(80);                 	//sensör init
  delay(1300);                    	//delay
  initSensor(81);                 	//sensor stop

  
  Red   = readVEML6040(8);       	//find the value of red color
  Red   = readVEML6040(8);       	//find the value of red color
  
  Green = readVEML6040(9);       	//find the value of green color
  Green = readVEML6040(9);       	//find the value of green color
  
  Blue  = readVEML6040(10);      	//find the value of blue color
  Blue  = readVEML6040(10);      	//find the value of blue color
  
  White = readVEML6040(11);      	//find the value of white color
  White = readVEML6040(11);      	//find the value of white color

  
  Serial.print("Red:   ");
  Serial.println(Red);      	//Red color value indicator
  
  Serial.print("Green: ");
  Serial.println(Green);    	//Green color value indicator

  Serial.print("Blue:  ");	
  Serial.println(Blue);     	//Blue color value indicator

  Serial.print("White: ");
  Serial.println(White);    	//White color value indicator

  Serial.println();

}
