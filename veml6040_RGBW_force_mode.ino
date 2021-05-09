//////////////// I2C device found at address 0x10
/*
Right
Left

Up
Down 
Middle

1RUL = 1.kart, Red, Up, Left = 1.kart
1RUM 
1RUR

1RML
1RMM 
1RMR

1RDL
1RDM
1RDR   

1GML
1GMM
1GMR

1OML
1OMM
1OMR

*/

//defines
//#define D1RUL_VDD  5
//#define D1RUM_VDD  8

#define D1RUL_VDD   9
#define D2RUL_VDD   10
#define D3RUL_VDD   11
#define D4RUL_VDD   12
#define D5RUL_VDD   13

#define SDA_PORT PORTC
#define SDA_PIN 4
#define SCL_PORT PORTC
#define SCL_PIN 5

#define VEML6040Adress 16   //VEML6040 I2C HEX Adresss = 0x10, DEC Adresss= 16

//libraries
#include "Wire.h"
#include "veml6040.h"

VEML6040 RGBWSensor;

int length = 4;         // 4 byte filter
char buffer [5];        // for buffer serial string data
char termChar = '\n';

//*****************************************************************************
void initSensor()
{
    //sensör init
    Wire.beginTransmission(VEML6040Adress);
    Wire.write(0);                     
    Wire.write(80);                      
    Wire.write(0);                     
    Wire.endTransmission();
}
//*****************************************************************************
void SensorStop() 
{
    //sensor stop
    Wire.beginTransmission(VEML6040Adress);
    Wire.write(0);                     
    Wire.write(81);                      
    Wire.write(0);                     
    Wire.endTransmission();
}
//*****************************************************************************
void read_VEML6040()
{
    //read_VEML6040
    Serial.print("RED:   ");
    Serial.println(RGBWSensor.getRed());  
    Serial.print("GREEN: ");
    Serial.println(RGBWSensor.getGreen());  
    Serial.print("BLUE:  ");
    Serial.println(RGBWSensor.getBlue());  
    Serial.print("WHITE: ");
    Serial.println(RGBWSensor.getWhite()); 
    Serial.print("CCT:   ");
    Serial.println(RGBWSensor.getCCT());  
    Serial.print("AL:    ");
    Serial.println(RGBWSensor.getAmbientLight()); 
    Serial.println();
    Serial.println();   
}
//*****************************************************************************
void read_UART()
{
    if (Serial.available())
    {
        int numChars = Serial.readBytesUntil(termChar, buffer, length);
        buffer[numChars]='\0';  
        //Serial.println(buffer);
        
//*****************************************************************************

        //1RUL
        if( (buffer[0] == '1') && (buffer[1] == 'R') && (buffer[2] == 'U') && (buffer[3] == 'L') )
        {
//            //
//            digitalWrite(D1RUM_VDD, LOW);
//            digitalWrite(D1RUR_VDD, LOW);
//            
//            digitalWrite(D1RML_VDD, LOW);
//            digitalWrite(D1RMM_VDD, LOW);
//            digitalWrite(D1RMR_VDD, LOW);
//            
//            digitalWrite(D1RDL_VDD, LOW);
//            digitalWrite(D1RDM_VDD, LOW);
//            digitalWrite(D1RDR_VDD, LOW);
//            
//            digitalWrite(D1GML_VDD, LOW);
//            digitalWrite(D1GMM_VDD, LOW);
//            digitalWrite(D1GMR_VDD, LOW);
//            
//            digitalWrite(D1OML_VDD, LOW);
//            digitalWrite(D1OMM_VDD, LOW);
//            digitalWrite(D1OMR_VDD, LOW);
//            
//            digitalWrite(D1RUL_VDD, HIGH); 
//            Serial.println("D1RUL_VDD_ON");
//            
//            initSensor(); 
//            delay(1300);
//            read_VEML6040();

        }
        //1RUM
        else if( (buffer[0] == '1') && (buffer[1] == 'R') && (buffer[2] == 'U') && (buffer[3] == 'M') )
        {
//            digitalWrite(D1RUL_VDD, LOW);
//            //
//            digitalWrite(D1RUR_VDD, LOW);
//    
//            digitalWrite(D1RML_VDD, LOW);
//            digitalWrite(D1RMM_VDD, LOW);
//            digitalWrite(D1RMR_VDD, LOW);
//    
//            digitalWrite(D1RDL_VDD, LOW);
//            digitalWrite(D1RDM_VDD, LOW);
//            digitalWrite(D1RDR_VDD, LOW);
//    
//            digitalWrite(D1GML_VDD, LOW);
//            digitalWrite(D1GMM_VDD, LOW);
//            digitalWrite(D1GMR_VDD, LOW);
//            
//            digitalWrite(D1OML_VDD, LOW);
//            digitalWrite(D1OMM_VDD, LOW);
//            digitalWrite(D1OMR_VDD, LOW);
//           
//            digitalWrite(D1RUM_VDD, HIGH); 
//            Serial.println("D1RUM_VDD_ON");
//            
//            initSensor(); 
//            delay(1300);
//            read_VEML6040();
        }
        //1RUR
        else if( (buffer[0] == '1') && (buffer[1] == 'R') && (buffer[2] == 'U') && (buffer[3] == 'R') )
        {
//            digitalWrite(D1RUL_VDD, LOW);
//            digitalWrite(D1RUM_VDD, LOW);
//            //
//
//            digitalWrite(D1RML_VDD, LOW);
//            digitalWrite(D1RMM_VDD, LOW);
//            digitalWrite(D1RMR_VDD, LOW);
//    
//            digitalWrite(D1RDL_VDD, LOW);
//            digitalWrite(D1RDM_VDD, LOW);
//            digitalWrite(D1RDR_VDD, LOW);
//    
//            digitalWrite(D1GML_VDD, LOW);
//            digitalWrite(D1GMM_VDD, LOW);
//            digitalWrite(D1GMR_VDD, LOW);
//            
//            digitalWrite(D1OML_VDD, LOW);
//            digitalWrite(D1OMM_VDD, LOW);
//            digitalWrite(D1OMR_VDD, LOW);
//           
//            digitalWrite(D1RUR_VDD, HIGH); 
//            Serial.println("D1RUR_VDD_ON");
//            
//            initSensor(); 
//            delay(1300);
//            read_VEML6040(); 
        }
        
//*****************************************************************************

        //1RML
        else if( (buffer[0] == '1') && (buffer[1] == 'R') && (buffer[2] == 'M') && (buffer[3] == 'L') )
        {
//            digitalWrite(D1RUL_VDD, LOW);
//            digitalWrite(D1RUM_VDD, LOW);
//            digitalWrite(D1RUR_VDD, LOW);
//    
//            //
//            digitalWrite(D1RMM_VDD, LOW);
//            digitalWrite(D1RMR_VDD, LOW);
//    
//            digitalWrite(D1RDL_VDD, LOW);
//            digitalWrite(D1RDM_VDD, LOW);
//            digitalWrite(D1RDR_VDD, LOW);
//    
//            digitalWrite(D1GML_VDD, LOW);
//            digitalWrite(D1GMM_VDD, LOW);
//            digitalWrite(D1GMR_VDD, LOW);
//            
//            digitalWrite(D1OML_VDD, LOW);
//            digitalWrite(D1OMM_VDD, LOW);
//            digitalWrite(D1OMR_VDD, LOW);
//           
//            digitalWrite(D1RML_VDD, HIGH); 
//            Serial.println("D1RML_VDD_ON");
//            
//            initSensor(); 
//            delay(1300);
//            read_VEML6040();
        }
        //1RMM 
        else if( (buffer[0] == '1') && (buffer[1] == 'R') && (buffer[2] == 'M') && (buffer[3] == 'M') )
        {
//            digitalWrite(D1RUL_VDD, LOW);
//            digitalWrite(D1RUM_VDD, LOW);
//            digitalWrite(D1RUR_VDD, LOW);
//    
//            digitalWrite(D1RML_VDD, LOW);
//            //
//            digitalWrite(D1RMR_VDD, LOW);
//    
//            digitalWrite(D1RDL_VDD, LOW);
//            digitalWrite(D1RDM_VDD, LOW);
//            digitalWrite(D1RDR_VDD, LOW);
//    
//            digitalWrite(D1GML_VDD, LOW);
//            digitalWrite(D1GMM_VDD, LOW);
//            digitalWrite(D1GMR_VDD, LOW);
//            
//            digitalWrite(D1OML_VDD, LOW);
//            digitalWrite(D1OMM_VDD, LOW);
//            digitalWrite(D1OMR_VDD, LOW);
//           
//            digitalWrite(D1RMM_VDD, HIGH); 
//            Serial.println("D1RMM_VDD_ON");
//            
//            initSensor(); 
//            delay(1300);
//            read_VEML6040(); 
        }
        //1RMR 
        else if( (buffer[0] == '1') && (buffer[1] == 'R') && (buffer[2] == 'M') && (buffer[3] == 'R') )
        {
//              digitalWrite(D1RUL_VDD, LOW);
//              digitalWrite(D1RUM_VDD, LOW);
//              digitalWrite(D1RUR_VDD, LOW);
//              
//              digitalWrite(D1RML_VDD, LOW);
//              digitalWrite(D1RMM_VDD, LOW);
//              //
//      
//              digitalWrite(D1RDL_VDD, LOW);
//              digitalWrite(D1RDM_VDD, LOW);
//              digitalWrite(D1RDR_VDD, LOW);
//      
//              digitalWrite(D1GML_VDD, LOW);
//              digitalWrite(D1GMM_VDD, LOW);
//              digitalWrite(D1GMR_VDD, LOW);
//              
//              digitalWrite(D1OML_VDD, LOW);
//              digitalWrite(D1OMM_VDD, LOW);
//              digitalWrite(D1OMR_VDD, LOW);
//             
//              digitalWrite(D1RMR_VDD, HIGH); 
//              Serial.println("D1RMR_VDD_ON");
//              
//              initSensor(); 
//              delay(1300);
//              read_VEML6040(); 
        }
        
//*****************************************************************************

        //1RDL
        else if( (buffer[0] == '1') && (buffer[1] == 'R') && (buffer[2] == 'D') && (buffer[3] == 'L') )
        {
//            digitalWrite(D1RUL_VDD, LOW);
//            digitalWrite(D1RUM_VDD, LOW);
//            digitalWrite(D1RUR_VDD, LOW);
//    
//            digitalWrite(D1RML_VDD, LOW);
//            digitalWrite(D1RMM_VDD, LOW);
//            digitalWrite(D1RMR_VDD, LOW);
//    
//            //
//            digitalWrite(D1RDM_VDD, LOW);
//            digitalWrite(D1RDR_VDD, LOW);
//    
//            digitalWrite(D1GML_VDD, LOW);
//            digitalWrite(D1GMM_VDD, LOW);
//            digitalWrite(D1GMR_VDD, LOW);
//            
//            digitalWrite(D1OML_VDD, LOW);
//            digitalWrite(D1OMM_VDD, LOW);
//            digitalWrite(D1OMR_VDD, LOW);
//           
//            digitalWrite(D1RDL_VDD, HIGH); 
//            Serial.println("D1RDL_VDD_ON");
//            
//            initSensor(); 
//            delay(1300);
//            read_VEML6040();
        }
        //1RDM 
        else if( (buffer[0] == '1') && (buffer[1] == 'R') && (buffer[2] == 'D') && (buffer[3] == 'M') )
        {
//            digitalWrite(D1RUL_VDD, LOW);
//            digitalWrite(D1RUM_VDD, LOW);
//            digitalWrite(D1RUR_VDD, LOW);
//    
//            digitalWrite(D1RML_VDD, LOW);
//            digitalWrite(D1RMM_VDD, LOW);
//            digitalWrite(D1RMR_VDD, LOW);
//    
//            digitalWrite(D1RDL_VDD, LOW);
//            //
//            digitalWrite(D1RDR_VDD, LOW);
//    
//            digitalWrite(D1GML_VDD, LOW);
//            digitalWrite(D1GMM_VDD, LOW);
//            digitalWrite(D1GMR_VDD, LOW);
//            
//            digitalWrite(D1OML_VDD, LOW);
//            digitalWrite(D1OMM_VDD, LOW);
//            digitalWrite(D1OMR_VDD, LOW);
//           
//            digitalWrite(D1RDM_VDD, HIGH); 
//            Serial.println("D1RDM_VDD_ON");
//            
//            initSensor(); 
//            delay(1300);
//            read_VEML6040();
        }
        //1RDR 
        else if( (buffer[0] == '1') && (buffer[1] == 'R') && (buffer[2] == 'D') && (buffer[3] == 'R') )
        {
//            digitalWrite(D1RUL_VDD, LOW);
//            digitalWrite(D1RUM_VDD, LOW);
//            digitalWrite(D1RUR_VDD, LOW);
//    
//            digitalWrite(D1RML_VDD, LOW);
//            digitalWrite(D1RMM_VDD, LOW);
//            digitalWrite(D1RMR_VDD, LOW);
//    
//            digitalWrite(D1RDL_VDD, LOW);
//            digitalWrite(D1RDM_VDD, LOW);
//            //
//    
//            digitalWrite(D1GML_VDD, LOW);
//            digitalWrite(D1GMM_VDD, LOW);
//            digitalWrite(D1GMR_VDD, LOW);
//            
//            digitalWrite(D1OML_VDD, LOW);
//            digitalWrite(D1OMM_VDD, LOW);
//            digitalWrite(D1OMR_VDD, LOW);
//           
//            digitalWrite(D1RDR_VDD, HIGH); 
//            Serial.println("D1RDR_VDD_ON");
//            
//            initSensor(); 
//            delay(1300);
//            read_VEML6040();
        }
        
//*****************************************************************************

        //1GML
        else if( (buffer[0] == '1') && (buffer[1] == 'G') && (buffer[2] == 'M') && (buffer[3] == 'L') )
        {
//            digitalWrite(D1RUL_VDD, LOW);
//            digitalWrite(D1RUM_VDD, LOW);
//            digitalWrite(D1RUR_VDD, LOW);
//    
//            digitalWrite(D1RML_VDD, LOW);
//            digitalWrite(D1RMM_VDD, LOW);
//            digitalWrite(D1RMR_VDD, LOW);
//    
//            digitalWrite(D1RDL_VDD, LOW);
//            digitalWrite(D1RDM_VDD, LOW);
//            digitalWrite(D1RDR_VDD, LOW);
//    
//            //
//            digitalWrite(D1GMM_VDD, LOW);
//            digitalWrite(D1GMR_VDD, LOW);
//            
//            digitalWrite(D1OML_VDD, LOW);
//            digitalWrite(D1OMM_VDD, LOW);
//            digitalWrite(D1OMR_VDD, LOW);
//           
//            digitalWrite(D1GML_VDD, HIGH); 
//            Serial.println("D1GML_VDD_ON");
//            
//            initSensor(); 
//            delay(1300);
//            read_VEML6040();
        }
        //1GMM 
        else if( (buffer[0] == '1') && (buffer[1] == 'G') && (buffer[2] == 'M') && (buffer[3] == 'M') )
        {
//            digitalWrite(D1RUL_VDD, LOW);
//            digitalWrite(D1RUM_VDD, LOW);
//            digitalWrite(D1RUR_VDD, LOW);
//    
//            digitalWrite(D1RML_VDD, LOW);
//            digitalWrite(D1RMM_VDD, LOW);
//            digitalWrite(D1RMR_VDD, LOW);
//    
//            digitalWrite(D1RDL_VDD, LOW);
//            digitalWrite(D1RDM_VDD, LOW);
//            digitalWrite(D1RDR_VDD, LOW);
//    
//            digitalWrite(D1GML_VDD, LOW);
//            //
//            digitalWrite(D1GMR_VDD, LOW);
//            
//            digitalWrite(D1OML_VDD, LOW);
//            digitalWrite(D1OMM_VDD, LOW);
//            digitalWrite(D1OMR_VDD, LOW);
//           
//            digitalWrite(D1GMM_VDD, HIGH);
//            Serial.println("D1GMM_VDD_ON");
//            
//            initSensor(); 
//            delay(1300);
//            read_VEML6040();
        }
        //1GMR 
        else if( (buffer[0] == '1') && (buffer[1] == 'G') && (buffer[2] == 'M') && (buffer[3] == 'R') )
        {
//            digitalWrite(D1RUL_VDD, LOW);
//            digitalWrite(D1RUM_VDD, LOW);
//            digitalWrite(D1RUR_VDD, LOW);
//    
//            digitalWrite(D1RML_VDD, LOW);
//            digitalWrite(D1RMM_VDD, LOW);
//            digitalWrite(D1RMR_VDD, LOW);
//    
//            digitalWrite(D1RDL_VDD, LOW);
//            digitalWrite(D1RDM_VDD, LOW);
//            digitalWrite(D1RDR_VDD, LOW);
//    
//            digitalWrite(D1GML_VDD, LOW);
//            digitalWrite(D1GMM_VDD, LOW);
//            //
//            
//            digitalWrite(D1OML_VDD, LOW);
//            digitalWrite(D1OMM_VDD, LOW);
//            digitalWrite(D1OMR_VDD, LOW);
//           
//            digitalWrite(D1GMR_VDD, HIGH);
//            Serial.println("D1GMR_VDD_ON");
//            
//            initSensor(); 
//            delay(1300);
//            read_VEML6040();
        }

//*****************************************************************************

        //1OML
        else if( (buffer[0] == '1') && (buffer[1] == 'O') && (buffer[2] == 'M') && (buffer[3] == 'L') )
        {
//            digitalWrite(D1RUL_VDD, LOW);
//            digitalWrite(D1RUM_VDD, LOW);
//            digitalWrite(D1RUR_VDD, LOW);
//    
//            digitalWrite(D1RML_VDD, LOW);
//            digitalWrite(D1RMM_VDD, LOW);
//            digitalWrite(D1RMR_VDD, LOW);
//    
//            digitalWrite(D1RDL_VDD, LOW);
//            digitalWrite(D1RDM_VDD, LOW);
//            digitalWrite(D1RDR_VDD, LOW);
//    
//            digitalWrite(D1GML_VDD, LOW);
//            digitalWrite(D1GMM_VDD, LOW);
//            digitalWrite(D1GMR_VDD, LOW);
//            
//            //
//            digitalWrite(D1OMM_VDD, LOW);
//            digitalWrite(D1OMR_VDD, LOW);
//           
//            digitalWrite(D1OML_VDD, HIGH);
//            Serial.println("D1OML_VDD_ON");
//            
//            initSensor(); 
//            delay(1300);
//            read_VEML6040(); 
        }
        //1OMM 
        else if( (buffer[0] == '1') && (buffer[1] == 'O') && (buffer[2] == 'M') && (buffer[3] == 'M') )
        {
//            digitalWrite(D1RUL_VDD, LOW);
//            digitalWrite(D1RUM_VDD, LOW);
//            digitalWrite(D1RUR_VDD, LOW);
//    
//            digitalWrite(D1RML_VDD, LOW);
//            digitalWrite(D1RMM_VDD, LOW);
//            digitalWrite(D1RMR_VDD, LOW);
//    
//            digitalWrite(D1RDL_VDD, LOW);
//            digitalWrite(D1RDM_VDD, LOW);
//            digitalWrite(D1RDR_VDD, LOW);
//    
//            digitalWrite(D1GML_VDD, LOW);
//            digitalWrite(D1GMM_VDD, LOW);
//            digitalWrite(D1GMR_VDD, LOW);
//            
//            digitalWrite(D1OML_VDD, LOW);
//            //
//            digitalWrite(D1OMR_VDD, LOW);
//           
//            digitalWrite(D1OMM_VDD, HIGH);
//            Serial.println("D1OMM_VDD_ON");
//            
//            initSensor(); 
//            delay(1300);
//            read_VEML6040();
        }
        //1OMR 
        else if( (buffer[0] == '1') && (buffer[1] == 'O') && (buffer[2] == 'M') && (buffer[3] == 'R') )
        {
//            digitalWrite(D1RUL_VDD, LOW);
//            digitalWrite(D1RUM_VDD, LOW);
//            digitalWrite(D1RUR_VDD, LOW);
//    
//            digitalWrite(D1RML_VDD, LOW);
//            digitalWrite(D1RMM_VDD, LOW);
//            digitalWrite(D1RMR_VDD, LOW);
//    
//            digitalWrite(D1RDL_VDD, LOW);
//            digitalWrite(D1RDM_VDD, LOW);
//            digitalWrite(D1RDR_VDD, LOW);
//    
//            digitalWrite(D1GML_VDD, LOW);
//            digitalWrite(D1GMM_VDD, LOW);
//            digitalWrite(D1GMR_VDD, LOW);
//            
//            digitalWrite(D1OML_VDD, LOW);
//            digitalWrite(D1OMM_VDD, LOW);
//            //
//           
//            digitalWrite(D1OMR_VDD, HIGH);
//            Serial.println("D1OMR_VDD_ON");
//            
//            initSensor(); 
//            delay(1300);
//            read_VEML6040();
        }

//*****************************************************************************









//*****************************************************************************   
    }
}


//*****************************************************************************
void setup() 
{
    pinMode(D1RUL_VDD, OUTPUT);
    pinMode(D1RUM_VDD, OUTPUT);
    //...

    
    digitalWrite(D1RUL_VDD, LOW);
    digitalWrite(D1RUM_VDD, LOW);
    //...

    //Serial.println("1RUL_VDD_OFF");
              
    Serial.begin(1000000);          // 2Mbps Baud Rates
    Wire.begin();
    if(!RGBWSensor.begin()) 
    {
        Serial.println("ERROR: couldn't detect the sensor");
        while(1){}
    }
    /*
    * init RGBW sensor with: 
    *  - 160ms integration time
    *  - force mode with trigger
    *  - color sensor enable
    */ 
    RGBWSensor.setConfiguration(VEML6040_IT_160MS + VEML6040_TRIG_ENABLE + VEML6040_AF_FORCE + VEML6040_SD_ENABLE);
    delay(1300);
    Serial.println("Vishay VEML6040 RGBW color sensor auto mode");
    Serial.println("Enter 't' or 'f' to get new color measurements");
    initSensor();
    delay(1000);
}
//*****************************************************************************

void loop() 
{
    read_UART();

   
    //initSensor(); 
    //digitalWrite(A0_LED, HIGH);
    //delay(1300);
    //read_VEML6040();
    
}













//*****************************************************************************
//switch(inchar) 
//{
//    case 't':   
//      /*
//      * init RGBW sensor with: 
//      *  - 1280ms integration time
//      *  - force mode with trigger
//      *  - color sensor enable
//      */
//      RGBWSensor.setConfiguration(VEML6040_IT_1280MS + VEML6040_TRIG_ENABLE + VEML6040_AF_FORCE + VEML6040_SD_ENABLE);
//      Serial.println("integration time 1280ms"); 
//      break;
//      
//    case 'f':   
//      /*
//      * init RGBW sensor with: 
//      *  - 160ms integration time
//      *  - force mode with trigger
//      *  - color sensor enable
//      */
//      RGBWSensor.setConfiguration(VEML6040_IT_80MS + VEML6040_TRIG_ENABLE + VEML6040_AF_FORCE + VEML6040_SD_ENABLE);
//      Serial.println("integration time 80ms"); 
//      break;
//      
//
//      case 'DD': 
//      digitalWrite(D1_RUL_VDD, HIGH);
//      Serial.println("D1_RUL_VDD_ON");
//      initSensor(); 
//      delay(1300);
//      read_VEML6040();  
//      break;
//
//      case '2': 
//      analogWrite(D1_RUL_VDD, LOW); 
//      Serial.println("D1_RUL_VDD_OFF");
//      read_VEML6040();
//      SensorStop();
//      break;
//      
//    default:
//      Serial.println("Enter 't' or 'f' to get new color measurements");
//      break;           
//}
//*****************************************************************************
