#ifndef __VEML6040_h
#define	__VEML6040_h

#define uns8 	unsigned char
#define uns16	unsigned int

//UV Sensor VEML6070 Address
#define VEML6070_ADDR	0x38 //i2c Address UV sensor

//RGBW Sensor VEML6040 Address
#define VEML6040_ADDR	0x10 //i2c address RGBW sensor
#define VEML6040_CONF	0x00

class VEMLClass {
private:

	uns8 VEML6070_command; //Hold previous byte written
	void VEML6070_init(); //Initialize VEML6070 = 0
	void VEML6070_write(uns8 cmd); //Write command to the VEML6070
	void VEML6040_init(); //Initialize VEML6040 = 0
	void VEML6040_write(uns8 addr, uns8 lsb); //Write 0x00 register
	uns16 VEML6040_read(uns8 addr); //Read register address VEML6040
	
public:

	void init(); //Initialize VEML6040 & VEML6070
	uns16 getUV(); //Reads UV measurement
	

	void VEML6070_setIT(uns8 it);  // Set integration time for VEML6070 measurement. 0 = 1/2T, 1 = T, 2 = 2T, 3 = 4T
	
	uns16 getRed(); //Get red light measurement
	uns16 getGreen(); //Get green light measurement
	uns16 getBlue(); //Get blue light measurement
	uns16 getWhite(); //Get white light measurement
	void VEML6040_enableSensor(); //Enable light sensor in VEML6040
	void VEML6040_disableSensor(); //Disable light sensor in VEML6040
	void VEML6040_setIT(uns8 it); //Set integration time for VEML6040 measurement. 0 = 40ms, 1 = 80ms, 2 = 160ms, 3 = 320ms, 4 = 640ms,  = 1280ms
	void VEML6040_forceMode(); // Set VEML6040 to forced measurement mode. Must be triggered to start a measurement
	void VEML6040_autoMode(); //Set VEML6040 to auto measurement mode
	void VEML6040_trigger(); //Triggers a measurement during forced mode
};

extern VEMLClass VEML6040;

#endif