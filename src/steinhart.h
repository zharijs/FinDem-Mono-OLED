#ifndef STEINHART_h
#define STEINHART_h
//
#include <Arduino.h>
//
// Below variables are used for Steinhart-Hart and associated temperature calcs
// Refer to // https://arduinodiy.wordpress.com/2015/11/10/measuring-temperature-with-ntc-the-steinhart-hart-formula/
//
#define SERIESRESISTOR 150000 //  Reduced current and scale to 0 - 1 Volts
#define NOMINAL_RESIST 10000 // @25C
#define NOMINAL_TEMP 25 // See above
#define BCOEFFICIENT 3950 // need to verify for Vishay 10K NTC
float ADCvalue = 0.0; // Initialized values have no meaning
float Resistance = 0.0; //       ditto
float steinhart = 0.0; //       ditto
float temperature = 0.0; //       ditto
int temp_int = 0; //       ditto
int correction = 21; // adjust readings to measured by accurate digital thermometer
//
String getTemp (){
  String temp_str;
  ADCvalue = float(analogRead(A0)); // Only analog pin on ESP8266
  Resistance = 1023 / ADCvalue - 1; // Current thermistor resistance
  Resistance = SERIESRESISTOR / Resistance;
  steinhart = Resistance / NOMINAL_RESIST; // (R/Ro)
  steinhart = log(steinhart); // ln(R/Ro)
  steinhart /= BCOEFFICIENT; // 1/B * ln(R/Ro)
  steinhart += 1.0 / (NOMINAL_TEMP + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart; // Invert
  temperature = steinhart - 273.15; // K ==> C
  //temperature = (temperature * 9.0) / 5.0 + 32.0; // C ==> F
  temp_int = round((temperature + correction) * 10) / 10;
  temp_str = String(temp_int);
  return temp_str;
}
//
#endif
