#include <Wire.h>
#include <VEML6040.h>

int x = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  VEML6040.init();
  Serial.println("14CORE | VEML6040 TEST CODE");
  VEML6040.VEML6040_forceMode();
  VEML6040.VEML6040_trigger();
  delay(1000);
}

void loop() {
  measureLight();
  Serial.println();
  delay(500);
  VEML6040.VEML6040_trigger();
}
void measureLight() {
  uns16 uv, red, blue, green, white;
  uv = VEML6040.getUV();
  red = VEML6040.getRed();
  green = VEML6040.getGreen();
  blue = VEML6040.getBlue();
  white = VEML6040.getWhite();
  Serial.println("VEML6040 DATA");
  Serial.println();
  Serial.print("VEML6070 UV:\t");
  Serial.println(uv);
  Serial.println();
  Serial.print("Red:\t");
  Serial.print(red);
  Serial.println();
  Serial.print("\tGreen:\t");
  Serial.print(green);
  Serial.println();
  Serial.print("\tBlue:\t");
  Serial.print(blue);
  Serial.println();
  Serial.print("\tWhite:\t");
  Serial.println(white);
}
