#ifndef FRAMES_h
#define FRAMES_h


//#include <ESP8266WiFi.h>
//#include <WiFiUdp.h>
//#include <WiFiTcp.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <TimeLib.h>
#include "OLEDDisplayUi.h"
//#include "images.h"
#include "nanoPLCboot.h"
#include "nanoPLCpix.h"
//#include "frames.h"
#include "ad128.h"
#include "fi128.h"
#include "it128.h"
#include "lt128.h"
#include "wsi128c.h"
#include "wt128.h"
//
#include "steinhart.h"
//
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
//#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"`
//SSD1306  display(0x3c, 4, 2);
#include "SSD1309.h" // alias for `#include "SSD1306Wire.h"`
SSD1309  display(0x3c, 4, 2);//, 15, 14);
//
OLEDDisplayUi ui ( &display );
//
int screenW = 128;
int screenH = 64;
int clockCenterX = screenW/2;
int clockCenterY = ((screenH-16)/2)+16;   // top yellow part is 16 px height
int clockRadius = 23;
//
//

//
// utility function for digital clock display: prints leading 0
String twoDigits(int digits){
  if(digits < 10) {
    String i = '0'+String(digits);
    return i;
  }
  else {
    return String(digits);
  }
}
String threeDigits(int digits){
  if(digits < 10) {
    String i = '0'+'0'+String(digits);
    return i;
  }
  else if(digits < 100) {
    String i = '0'+String(digits);
    return i;
  }
  else {
    return String(digits);
  }
}
//
void clockOverlay(OLEDDisplay *display, OLEDDisplayUiState* state) {
/*
  if (displayMode > 0){
    display->setTextAlignment(TEXT_ALIGN_CENTER);
    display->setFont(ArialMT_Plain_10);
  //display->drawString(DISPLAY_WIDTH -15, DISPLAY_HEIGHT - 15, pwmValue );
//  display->drawString(DISPLAY_WIDTH -18, 2, String("A:" + threeDigits((pwmValue1-pwmMin)/((pwmMax-pwmMin)/100) )) + "%");
//  display->drawString(DISPLAY_WIDTH -18, 12, String("B:" + threeDigits((pwmValue2-pwmMin)/((pwmMax-pwmMin)/100) )) + "%");
    display->drawString(DISPLAY_WIDTH -18, 2,  String("A:" + String(map(pwmValue1,pwmMin,pwmMax,0,100 ))) + "%");
    display->drawString(DISPLAY_WIDTH -18, 12, String("B:" + String(map(pwmValue2,pwmMin,pwmMax,0,100 ))) + "%");
    display->drawString(18, 2, String(getTemp() + "°C"));
  }
*/
}
//
//
void frameLogoFi(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->clear();
  display->drawXbm(0, 0, x_width_fi, x_height_fi, x_bits_fi);
}
void frameLogoIt(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->clear();
  display->drawXbm(0, 0, x_width_it, x_height_it, x_bits_it);
}
void frameLogoWsi(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->clear();
  display->drawXbm(0, 0, x_width_wsi, x_height_wsi, x_bits_wsi);
}
void frameLogoWt(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->clear();
  display->drawXbm(0, 0, x_width_wt, x_height_wt, x_bits_wt);
}
void frameLogoLt(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->clear();
  display->drawXbm(0, 0, x_width_lt, x_height_lt, x_bits_lt);
}
void frameLogoAd(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->clear();
  display->drawXbm(0, 0, x_width_ad, x_height_ad, x_bits_ad);
}
//
//
void analogClockFrame(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
//  ui.disableIndicator();

  // Draw the clock face
//  display->drawCircle(clockCenterX + x, clockCenterY + y, clockRadius);
  display->drawCircle(clockCenterX + x, clockCenterY + y, 2);
  //
  //hour ticks
  for( int z=0; z < 360;z= z + 30 ){
  //Begin at 0° and stop at 360°
    float angle = z ;
    angle = ( angle / 57.29577951 ) ; //Convert degrees to radians
    int x2 = ( clockCenterX + ( sin(angle) * clockRadius ) );
    int y2 = ( clockCenterY - ( cos(angle) * clockRadius ) );
    int x3 = ( clockCenterX + ( sin(angle) * ( clockRadius - ( clockRadius / 8 ) ) ) );
    int y3 = ( clockCenterY - ( cos(angle) * ( clockRadius - ( clockRadius / 8 ) ) ) );
    display->drawLine( x2 + x , y2 + y , x3 + x , y3 + y);
  }

  // display second hand
  float angle = second() * 6 ;
  angle = ( angle / 57.29577951 ) ; //Convert degrees to radians
  int x3 = ( clockCenterX + ( sin(angle) * ( clockRadius - ( clockRadius / 5 ) ) ) );
  int y3 = ( clockCenterY - ( cos(angle) * ( clockRadius - ( clockRadius / 5 ) ) ) );
  display->drawLine( clockCenterX + x , clockCenterY + y , x3 + x , y3 + y);
  //
  // display minute hand
  angle = minute() * 6 ;
  angle = ( angle / 57.29577951 ) ; //Convert degrees to radians
  x3 = ( clockCenterX + ( sin(angle) * ( clockRadius - ( clockRadius / 4 ) ) ) );
  y3 = ( clockCenterY - ( cos(angle) * ( clockRadius - ( clockRadius / 4 ) ) ) );
  display->drawLine( clockCenterX + x , clockCenterY + y , x3 + x , y3 + y);
  //
  // display hour hand
  angle = hour() * 30 + int( ( minute() / 12 ) * 6 )   ;
  angle = ( angle / 57.29577951 ) ; //Convert degrees to radians
  x3 = ( clockCenterX + ( sin(angle) * ( clockRadius - ( clockRadius / 2 ) ) ) );
  y3 = ( clockCenterY - ( cos(angle) * ( clockRadius - ( clockRadius / 2 ) ) ) );
  display->drawLine( clockCenterX + x , clockCenterY + y , x3 + x , y3 + y);
}
//
void digitalClockFrame(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  String timenow = String(hour())+":"+twoDigits(minute())+":"+twoDigits(second());
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setFont(ArialMT_Plain_24);
  display->drawString(clockCenterX + x , clockCenterY + y, timenow );
}
//
void digitalThermometerFrame(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
//  int temp = analogRead(A0);
// int voltage = analogRead(ADC_VCC);
  String tempnow = String(getTemp() +"°C");
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setFont(ArialMT_Plain_24);
  display->drawString(clockCenterX + x , clockCenterY + y, tempnow );
}
//
void frameNetwork1 (OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->clear();
  display->setFont(ArialMT_Plain_10);
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setColor(WHITE);
  display->fillRect(0, 0, 128, 12);
  display->setColor(BLACK);
  display->drawString(DISPLAY_WIDTH/2, 0, "IP Info");
  display->setColor(WHITE);
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->drawString(10, 12, "Host: " + WiFi.hostname());
  display->drawString(10, 22, "IP: " + WiFi.localIP().toString());
  display->drawString(10, 32, "GW: " + WiFi.gatewayIP().toString());
  display->drawString(10, 42, "Subnet: " + WiFi.subnetMask().toString());
  display->drawString(10, 52, "DNS: " + WiFi.dnsIP().toString());
}
void frameNetwork2 (OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->clear();
  display->setFont(ArialMT_Plain_10);
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setColor(WHITE);
  display->fillRect(0, 0, 128, 12);
  display->setColor(BLACK);
  display->drawString(DISPLAY_WIDTH/2, 0, "Connection Info");
  display->setColor(WHITE);
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->drawString(10, 12, "MAC: " + WiFi.macAddress());//.toString());
  display->drawString(10, 22, "SSID: " + WiFi.SSID());
  display->drawString(10, 32, "PSK: " + WiFi.psk());
  //if (WiFi.RSSI() > 31) display->drawString(10, 42, "RSSI: " + String(WiFi.RSSI()));//.toString());
  //else display->drawString(10, 42, "RSSI: N/A");
  display->drawString(10, 42, "RSSI: " + String(WiFi.RSSI()));//.toString());
//display->drawString(10, 52, "DNS: " + WiFi.dnsIP().toString());
}
void frameNetwork3 (OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->clear();
  display->setFont(ArialMT_Plain_10);
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setColor(WHITE);
  display->fillRect(0, 0, 128, 12);
  display->setColor(BLACK);
  display->drawString(DISPLAY_WIDTH/2, 0, "More Info");
  display->setColor(WHITE);
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  //display->drawString(10, 12, "Status: " + WiFi.status());//.toString());
//  display->drawString(10, 22, "RSSI: " + WiFi.RSSI());
  //display->drawString(10, 50, "Status: " + WiFi.status());//.toString());
  //display->drawString(5, 12, "BTN1=" + String(btn1) + ", BTN2=" + String(btn2));//.toString());
  //display->drawString(5, 12, "BTN3=" + String(btn1) + ", BTN4=" + String(btn2));//.toString());

}

//
//
int sliderValue1=66;//0 ;
int sliderValue2=66;//0 ;
int gyroValueX=0;
int gyroValueY=0;
int gyroValueZ=0;
//
void frameSocketSlider (OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->clear();
  display->setFont(ArialMT_Plain_10);
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->drawString(DISPLAY_WIDTH/2, 0/*DISPLAY_HEIGHT/2 - 10*/, "SockTest: Slider");
  display->drawProgressBar(4, 22, 120, 8, (sliderValue1-66) / 4 );
  display->drawProgressBar(4, 38, 120, 8, (sliderValue2-66) / 4 );
//  display->display();
}
void frameSocketGyro (OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->clear();
  display->setFont(ArialMT_Plain_10);
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->drawString(DISPLAY_WIDTH/2, 0/*DISPLAY_HEIGHT/2 - 10*/, "SockTest: Gyro");
  display->drawString(6, 18/*DISPLAY_HEIGHT/2 - 10*/, "X");
  display->drawString(6, 30/*DISPLAY_HEIGHT/2 - 10*/, "Y");
  display->drawString(6, 42/*DISPLAY_HEIGHT/2 - 10*/, "Z");
  display->drawProgressBar(14, 18, 110, 8, gyroValueX );
  display->drawProgressBar(14, 30, 110, 8, gyroValueY );
  display->drawProgressBar(14, 42, 110, 8, gyroValueZ );
  //display->display();
}
void frameSocketChat (OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->clear();
  display->setFont(ArialMT_Plain_10);
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->drawString(DISPLAY_WIDTH/2, 0/*DISPLAY_HEIGHT/2 - 10*/, "SockTest: Chat");
  //display->drawProgressBar(4, 22, 120, 8, (sliderValue1-66) / 4 );
  //display->drawProgressBar(4, 38, 120, 8, (sliderValue2-66) / 4 );
  //display->display();
}
//
//
int cursorPosition = 0;
int cursorMaxPosition = 0;
int networksFountCount = 0;
String currentSSID ="";
String currentPassword ="";
int numberOfLetters = 66;
const char passwordLetters [74] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w',
                                   'x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T',
                                   'U','V','W','X','Y','Z','1','2','3','4','5','6','7','8','9','0','!','@','#','_','a','b','c',
                                   'd','e','f','g','h' }; // 8 extra tailing cahracter are for display font strip overhead at circular buffer wrapping
String currentLetterWindow = "";
//
void frameSetupScan (OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->clear();
  display->setFont(ArialMT_Plain_10);
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setColor(WHITE);
  display->fillRect(0, 0, 128, 12);
  display->setColor(BLACK);
  display->drawString(DISPLAY_WIDTH/2, 0, "Scanning networks...");
  display->setColor(WHITE);
  //
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setColor(WHITE);
  display->fillRect(0, 53, 31, 11);
  display->fillRect(32, 53, 31, 11);
  display->fillRect(64, 53, 31, 11);
  display->fillRect(96, 53, 31, 11);
}
void frameSetupSelect (OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->clear();
  display->setFont(ArialMT_Plain_10);
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setColor(WHITE);
  display->fillRect(0, 0, 128, 12);
  display->setColor(BLACK);
  display->drawString(DISPLAY_WIDTH/2, 0, "Select Network ["+ String(cursorPosition+1) +"/"+String(cursorMaxPosition) +"]:");
  display->setColor(WHITE);
  //
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  int itemOffset = 0;
  if (cursorPosition > 3) {
    itemOffset = cursorPosition - 3;
  } else itemOffset = 0;
/*
    if (cursorMaxPosition > 0) display->drawString(8, 11, WiFi.SSID(0+itemOffset) + ":" + String(WiFi.encryptionType(0+itemOffset)) + ":" + String(WiFi.RSSI(0+itemOffset)) + "dBm");//.toString());
    if (cursorMaxPosition > 1) display->drawString(8, 21, WiFi.SSID(1+itemOffset) + ":" + String(WiFi.encryptionType(1+itemOffset)) + ":" + String(WiFi.RSSI(1+itemOffset)) + "dBm");//.toString());
    if (cursorMaxPosition > 2) display->drawString(8, 31, WiFi.SSID(2+itemOffset) + ":" + String(WiFi.encryptionType(2+itemOffset)) + ":" + String(WiFi.RSSI(2+itemOffset)) + "dBm");//.toString());
    if (cursorMaxPosition > 3) display->drawString(8, 41, WiFi.SSID(3+itemOffset) + ":" + String(WiFi.encryptionType(3+itemOffset)) + ":" + String(WiFi.RSSI(3+itemOffset)) + "dBm");//.toString());
*/
    if (cursorMaxPosition > 0) display->drawString(8, 11, WiFi.SSID(0+itemOffset) + ":" + String(WiFi.RSSI(0+itemOffset)) + "dBm");//.toString());
    if (cursorMaxPosition > 1) display->drawString(8, 21, WiFi.SSID(1+itemOffset) + ":" + String(WiFi.RSSI(1+itemOffset)) + "dBm");//.toString());
    if (cursorMaxPosition > 2) display->drawString(8, 31, WiFi.SSID(2+itemOffset) + ":" + String(WiFi.RSSI(2+itemOffset)) + "dBm");//.toString());
    if (cursorMaxPosition > 3) display->drawString(8, 41, WiFi.SSID(3+itemOffset) + ":" + String(WiFi.RSSI(3+itemOffset)) + "dBm");//.toString());
    display->drawString(0, 11 + (10*(cursorPosition-itemOffset)), ">");
  //
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setColor(WHITE);
  display->fillRect(0, 53, 31, 11);
  display->fillRect(32, 53, 31, 11);
  display->fillRect(64, 53, 31, 11);
  display->fillRect(96, 53, 31, 11);
  display->setColor(BLACK);
  display->drawString(16, 52, "Scan");
  display->drawString(48, 52, "+");
  display->drawString(80, 52, "-");
  display->drawString(112, 52, "OK");
  display->setColor(WHITE);
}
void frameSetupPasswd (OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->clear();
  display->setFont(ArialMT_Plain_10);
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setColor(WHITE);
  display->fillRect(0, 0, 128, 22);
  display->setColor(BLACK);
  display->drawString(DISPLAY_WIDTH/2, 0, currentSSID);
  display->drawString(DISPLAY_WIDTH/2, 11, "Enter Password:");
  display->setColor(WHITE);
  //
//  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setFont(ArialMT_Plain_16);
  display->drawString(DISPLAY_WIDTH/2, 21, String(currentPassword) + "_");
  display->setFont(ArialMT_Plain_10);
  display->drawString(DISPLAY_WIDTH/2, 39, String(currentLetterWindow));
  //
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setColor(WHITE);
  display->fillRect(0, 53, 31, 11);
  display->fillRect(32, 53, 31, 11);
  display->fillRect(64, 53, 31, 11);
  display->fillRect(96, 53, 31, 11);
  display->setColor(BLACK);
  display->drawString(16, 52, "OK");
  display->drawString(48, 52, "+");
  display->drawString(80, 52, "-");
  display->drawString(112, 52, "Sel");
  display->setColor(WHITE);
  //
}

//
// This array keeps function pointers to all frames // frames are the single views that slide in
FrameCallback framesClocks[] = { analogClockFrame, digitalClockFrame, digitalThermometerFrame };
FrameCallback framesLogo[] = { frameLogoAd, frameLogoFi, frameLogoIt, frameLogoWsi, frameLogoWt, frameLogoLt };
FrameCallback framesNetwork[] = { frameNetwork3, frameNetwork2, frameNetwork1};
FrameCallback framesSocket[] = { frameSocketGyro, frameSocketSlider };
FrameCallback framesSetup[] = { frameSetupScan, frameSetupSelect, frameSetupPasswd };
//
int framesWardriverCount = 1; // how many frames are there?
int framesSetupCount = 3; // how many frames are there?
int framesLogoCount = 6; // how many frames are there?
int framesClocksCount = 3; // how many frames are there?
int framesNetworkCount = 3; // how many frames are there?
int framesSocketCount = 2; // how many frames are there?
OverlayCallback overlays[] = { clockOverlay }; // Overlays are statically drawn on top of a frame eg. a clock
int overlaysCount = 1;
//
//
#endif
