  /**
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 by Daniel Eichhorn
 * Copyright (c) 2016 by Fabrice Weinberg
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.ud
 *
 */

// WiFi includes


 //#include <WiFiTcp.h>
 //
#include "images.h"
#include "frames.h"
#include "clock.h"
//
// OTA Includes
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>
#include <EEPROM.h>
#include <ESP8266mDNS.h>
//
String localHostName;
String localHostNameOTA;
String ssid;//         = "finDemo";
String password;//     = "qwerty";
//const char *ssid         = "finDemo";
//const char *password     = "qwerty";
//const char *ssid         = "glitchy";
//const char *password     = "qwed098u";
//const char *ssid         = "ITECH_C";
// const char *password     = "intelitech2016";
// const char *ssid         = "LemonPoodle";
// const char *password     = "qwed098u";
//
//
//
//
#define MAX_SRV_CLIENTS 3
WiFiServer server(8000);
WiFiClient serverClients[MAX_SRV_CLIENTS];
//
MDNSResponder mdns;
//
int modeSwitchDone = 0;
int displayMode = 0;
int displayState = 0;
//
//
int btn1;
int btn2;
int btn3;
int btn4;
int btnByte = 0;
int btnState1 = 0;
int btnState2 = 0;
int btnState3 = 0;
int btnState4 = 0;
//
int offlineMode = 0;
int setupMode = 0;
int warDriverMode = 0;
//
//
//### Received data parser ########################################################
//
char consoleCommand[16];
char consoleArg[16];
char consoleServerStream[32][MAX_SRV_CLIENTS];
int intNumber;

//
void setSlider1 (int data){
    sliderValue1 = data;
    //analogWrite(16, 1024 - pwmValue1);
}
void setSlider2 (int data){
    sliderValue2 = data;
    //analogWrite(12, 1024 - pwmValue2);
}
//
void parseReceivedPacket(char * data){
  char * pch;
  pch = strtok(data, " ,.-");   // get command
  strcpy (consoleCommand, pch); // set command
  int iter = 0;
  int index = 0;
  //
  if (!strncmp(consoleCommand, "KA", 2)) {
      Serial.println("keepalve");
    }
  if (!strncmp(consoleCommand, "L0V", 3)) {
//        while (pch != NULL) { // get arguments
        pch = strtok(NULL, " ,.-");
        strcpy(consoleArg, pch);
 //     }
    Serial.print("LED0 = ");
    intNumber = atoi(consoleArg);
    Serial.println(intNumber);
   // Serial.print(consoleArg);
  //  Serial.println("d;");
    setSlider1 (intNumber);
  }
  if (!strncmp(consoleCommand, "L1V", 3)) {
    pch = strtok(NULL, " ,.-");
    strcpy(consoleArg, pch);
    Serial.print("LED1 = ");
    intNumber = atoi(consoleArg);
    Serial.print(intNumber);
//    Serial.println("d;");
    setSlider2 (intNumber);
  }
  if (!strncmp(consoleCommand, "G1X", 3)) {
    pch = strtok(NULL, " ,.-");
    strcpy(consoleArg, pch);
    //Serial.print("Gyro X = ");
    intNumber = atoi(consoleArg);
    Serial.print(intNumber);
//    Serial.println("d;");
    gyroValueX = intNumber;
  }
  if (!strncmp(consoleCommand, "G1Y", 3)) {
    pch = strtok(NULL, " ,.-");
    strcpy(consoleArg, pch);
    //Serial.print("Gyro Y= ");
    intNumber = atoi(consoleArg);
    Serial.print(intNumber);
//    Serial.println("d;");
    gyroValueY = intNumber;
  }
  if (!strncmp(consoleCommand, "G1Z", 3)) {
    pch = strtok(NULL, " ,.-");
    strcpy(consoleArg, pch);
    //Serial.print("Gyro Z = ");
    intNumber = atoi(consoleArg);
    Serial.print(intNumber);
//    Serial.println("d;");
    gyroValueZ = intNumber;
  }
}
//
//### server connection and data handler #######################################
//
void serverHandle() {
  uint8_t i;
  int j;
  if (server.hasClient()){
    for(i = 0; i < MAX_SRV_CLIENTS; i++){
      if (!serverClients[i] || !serverClients[i].connected()){
        if(serverClients[i]) serverClients[i].stop();
        serverClients[i] = server.available();
        continue;
      }
    }
    //no free spot
    WiFiClient serverClient = server.available();
    serverClient.stop();
  }
  for(i = 0; i < MAX_SRV_CLIENTS; i++){
    j = 0;
    if (serverClients[i] && serverClients[i].connected()){
      if(serverClients[i].available()){
        while(serverClients[i].available()){
          //Serial.write(serverClients[i].read());
          consoleServerStream[i][j++] = serverClients[i].read();
          //j++;
        }
        consoleServerStream[i][j++] = 0;
       // Serial.print(consoleServerStream[i]);
        parseReceivedPacket(consoleServerStream[i]);
        //you can reply to the client here
      }
    }
  }
  if(Serial.available()){
    size_t len = Serial.available();
    uint8_t sbuf[len];
    Serial.readBytes(sbuf, len);
    //bello is a broadcast to all clients
    for(i = 0; i < MAX_SRV_CLIENTS; i++){
      if (serverClients[i] && serverClients[i].connected()){
        serverClients[i].write(sbuf, len);
        delay(1);
      }
    }
  }
}
//
//##########################################################################################################################################################################################
//###[SETUP]################################################################################################################################################################################
//##########################################################################################################################################################################################
int setupStage = 0;
//
void setup() {
//###[SETUP:GPIO & PWM]###########################
  pinMode(5, INPUT);
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(16, INPUT);
  //analogWriteRange(1024);
  //  analogWriteFreq(1000);
  //###[ SETUP : SERIAL]###########################
  Serial.begin(115200);
  Serial.println();
  Serial.println("\r\n");
  Serial.print("Chip ID: 0x");
  Serial.println(ESP.getChipId(), HEX);
  //###[ SETUP : Virtual EEPROM ]###########################
  EEPROM.begin(512);
  delay(10);
  //###[ SETUP : UI ]###########################
  ui.setTargetFPS(15);    // The ESP is capable of rendering 60fps in 80Mhz mode, but that won't give you much time for anything else - run it in 160Mhz mode or just set it to 30 fps
  ui.setActiveSymbol(activeSymbol);  // Customize the active and inactive symbol
  ui.setInactiveSymbol(inactiveSymbol);
  ui.setIndicatorPosition(TOP);   // You can change this to  // TOP, LEFT, BOTTOM, RIGHT
  ui.setFrameAnimation(SLIDE_LEFT);// You can change the transition that is used   // SLIDE_LEFT, SLIDE_RIGHT, SLIDE_UP, SLIDE_DOWN
  ui.setIndicatorDirection(LEFT_RIGHT);  // Defines where the first frame is located in the bar.
  ui.disableAllIndicators();
  ui.disableAutoTransition();
  ui.setOverlays(overlays, overlaysCount); // Add overlays
  ui.setFrames(framesClocks, framesClocksCount);  // Add frames
  ui.enableAllIndicators();
  ui.disableAutoTransition();
  ui.init();  // Initialising the UI will init the display too.
  display.flipScreenVertically();
  Serial.println();
//###[SETUP:DISPLAY]###########################
  Serial.print("Initializing display.. ");
  display.init();
  display.flipScreenVertically();
  display.setContrast(125); //255
  Serial.println("DONE;");
//
//###[ SETUP : NETWORK ]###########################
localHostName = "FinDemOled";
localHostNameOTA = "FinDemOledOTA";

  WiFi.hostname(localHostName.c_str());
  getBtn();
  if (btnByte == 0){
    //###[ SETUP : Load EEPROM Contnt ]###########################
    Serial.print("Reading EEPROM ssid: ");
    ssid = "";
    for (int i = 0; i < 32; ++i) {
      if (char(EEPROM.read(i)) != 0x00) ssid += char(EEPROM.read(i));
    }
    Serial.print("SSID: ");
    Serial.println(ssid);
    Serial.print("Reading EEPROM password: ");
    password = "";
    for (int i = 32; i < 96; ++i) {
      if (char(EEPROM.read(i)) != 0x00) password += char(EEPROM.read(i));
    }
    Serial.print("PASS: ");
    Serial.println(password);
    //
    if (ssid.length() < 2){
      display.clear();
      display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
      display.setFont(ArialMT_Plain_10);
      display.drawString(DISPLAY_WIDTH/2, 10, "Please choose an");
      display.drawString(DISPLAY_WIDTH/2, 20, "access Point");
      display.drawString(DISPLAY_WIDTH/2, 30, "in Setup Mode");
      display.display();
      delay (3000);
      offlineMode = 1;
    } else {

    //
    display.clear();
    display.setFont(ArialMT_Plain_10);
    display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
    display.drawString(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2 - 10, "Connecting to " + ssid);
    display.display();
    //
    Serial.print("Connecting to ");
    Serial.print(ssid);
    Serial.print("...");
    WiFi.begin (ssid.c_str(), password.c_str());
//    WiFi.begin ( ssid, password );
    // Wait for connection
    display.setFont(ArialMT_Plain_10);
    display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
    //int rotateState = 0;
    int counter = 0;
    bool wifiTimeout = false;
    //
    while ( WiFi.status() != WL_CONNECTED ) {
      //
      if (counter < 1024) counter++;
      else {
        wifiTimeout = true;
        counter = 0;
        display.clear();
        display.setFont(ArialMT_Plain_10);
        display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
        display.drawString(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2 - 10, "Connecting to " + ssid);
        display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
      }
      display.drawProgressBar(4, 32, 120, 8, counter / (1024 / 100) );
      if (wifiTimeout) display.drawString(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2+18, "Check router!");
      //
      display.display();
      delay ( 10 );
    }
    Serial.println("DONE");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    //
    display.drawString(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2 - 10, "Connecting to " + ssid);
    display.drawProgressBar(4, 32, 120, 8, counter / (1024 / 100) );
    display.drawString(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2+18, "WiFi AP OK");
    display.display();
    delay ( 1000 );
    //
    Serial.print("Starting OTA... ");
    //
    ArduinoOTA.setHostname(localHostNameOTA.c_str());
    ArduinoOTA.begin();
    ArduinoOTA.onStart([]() {
      display.clear();
      display.setFont(ArialMT_Plain_10);
      display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
      display.drawString(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2 - 10, "OTA Update");
      display.display();
    });
    //
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
      display.drawProgressBar(4, 32, 120, 8, progress / (total / 100) );
      display.display();
    });
    //
    ArduinoOTA.onEnd([]() {
      //   display.clear();
      display.setFont(ArialMT_Plain_10);
      display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
      display.drawString(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2+18, "Restarting...");
      display.display();
    });
    //
    Serial.println("DONE");
    // Align text vertical/horizontal center
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
    display.setFont(ArialMT_Plain_10);
    display.drawString(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2, "Ready for OTAu:\n" + WiFi.localIP().toString() + "\n@ " + ssid);
    display.display();
    delay (2000);
    ////
    //Serial.print("Starting mDNS.. ");
    //if (mdns.begin("FinDemOled", WiFi.localIP()))  Serial.println(" OK");
    //
    Serial.println("Starting UDP");
    udp.begin(localPort);
    Serial.print("Local port: ");
    Serial.println(udp.localPort());
    delay (2000);
    //
    Serial.print("Starting Server..  ");
    server.begin();
    server.setNoDelay(true);
    Serial.println("DONE");
    offlineMode = 0;
  }
  }else{
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
    display.setFont(ArialMT_Plain_10);
    if (btnByte == 6){
      Serial.print("Device starting in setup mode..  ");
      setupMode = 1;
      warDriverMode = 0;
      offlineMode = 1;
      display.drawString(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2, "System started\nin SETUP\n mode");
      display.display();
      delay (2000);
        //
setupStage = 0;
/*
        while (btn4 == 1){
          if (btn1 == 1) {
            WiFi.mode(WIFI_STA);
            WiFi.disconnect();
            delay(100);
//            Serial.println("scan start");
            int networksFountCount = WiFi.scanNetworks();
          }
          if (btn2 == 1) {
            cursorMaxPosition = networksFountCount;
            if (cursorPosition < cursorMaxPosition) cursorPosition ++;
          }
          if (btn3 == 1) {
            cursorMaxPosition = networksFountCount;
            if (cursorPosition > 0) cursorPosition --;
          }
        }
*/

    } else if (btnByte == 9){
      Serial.print("Device starting in wardriver mode..  ");
      setupMode = 0;
      warDriverMode = 1;
      offlineMode = 1;
      display.drawString(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2, "System started\nin WarDriver\n mode");
      display.display();
      delay (2000);
      Serial.println("DONE");
    } else {
      Serial.print("Device starting in offline mode..  ");
      offlineMode = 1;
      setupMode = 0;
      warDriverMode = 0;
      display.drawString(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2, "System started\nin off-line\n mode");
      display.display();
      delay (2000);
      Serial.println("DONE");
    }
  }
}
  //
  int loopCounter = 0;
  //

void getBtn () {
  btn1 = digitalRead(13);
  btn2 = digitalRead(16);
  btn3 = digitalRead(12);
  btn4 = digitalRead(5);
  if (btn1 == 0) btnByte |= 0x01;
  else btnByte &= (~0x01);
  if (btn2 == 0) btnByte |= 0x02;
  else btnByte &= (~0x02);
  if (btn3 == 0) btnByte |= 0x04;
  else btnByte &= (~0x04);
  if (btn4 == 0) btnByte |= 0x08;
  else btnByte &= (~0x08);
}
//
//##########################################################################################################################################################################################
//###[MAINLOOP]#############################################################################################################################################################################
//##########################################################################################################################################################################################
//
//
void loadLetters (int offset){
  //if (offset < numberOfLetters-4){
    currentLetterWindow = "";
    for (int letter = 0; letter<9; letter++){
      currentLetterWindow += char(' ');
      if (letter == 4) currentLetterWindow += char('>');
      currentLetterWindow += char(passwordLetters[letter+offset]);
      if (letter == 4) currentLetterWindow += char('<');
      currentLetterWindow += char(' ');
    }
  //} else {

  //}
}
//
//
  void loop() {
    if (offlineMode == 0) {
      ArduinoOTA.handle();
    }
    int remainingTimeBudget = ui.update();
    if (remainingTimeBudget > 0) {
      //
      if (offlineMode == 0) {
        getNTP();
        serverHandle();
      }
      //
      getBtn();
//      if (btnByte !=0) { Serial.print("BTN: "); Serial.print(btnByte); }

      //

if (setupMode == 1) {
switch (setupStage){
  case 0:
    ui.setFrameAnimation(SLIDE_LEFT);// You can change the transition that is used   // SLIDE_LEFT, SLIDE_RIGHT, SLIDE_UP, SLIDE_DOWN
    ui.setFrames(framesSetup, framesSetupCount);  // Add frames
    ui.disableAllIndicators();
    ui.disableAutoTransition();
    ui.transitionToFrame(0);
    Serial.println("DONE");
    //orgStartScan:
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
    Serial.println("scan start");
    networksFountCount = WiFi.scanNetworks();
    Serial.println("scan done");
    if (networksFountCount == 0)
      Serial.println("no networks found");
    else
    {
      Serial.print(networksFountCount);
      Serial.println(" networks found");
      for (int i = 0; i < networksFountCount; i++)
      {
        // Print SSID and RSSI for each network found
        Serial.print(i + 1);
        Serial.print(": ");
        Serial.print(WiFi.SSID(i));
        Serial.print(" (");
        Serial.print(WiFi.RSSI(i));
        Serial.print(")");
        Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*");
        delay(10);
      }
    }
    Serial.println("");
    cursorMaxPosition = networksFountCount;
    ui.transitionToFrame(1);
    setupStage = 1;
    break;
  case 1:
      //
      if (btn1 == 0) {
        if ( btnState1 == 0 ){
          setupStage = 0;
          btnState1 = 1;
          cursorMaxPosition = 0;
          cursorPosition = 0;
          ui.transitionToFrame(0);
        }
      }
      else btnState1 = 0;
      //
      if (btn2 == 0) {
        if ( btnState2 == 0 ){
          btnState2 = 1;
          cursorMaxPosition = networksFountCount;
          if (cursorPosition < (cursorMaxPosition-1)) cursorPosition ++;
        }
      }
      else btnState2 = 0;
      //
      if (btn3 == 0) {
        if ( btnState3 == 0 ){
          btnState3 = 1;
          cursorMaxPosition = networksFountCount;
          if (cursorPosition > 0) cursorPosition --;
        }
      }
      else btnState3 = 0;
      //
      if (btn4 == 0) {
        if ( btnState4 == 0 ){
          btnState4 = 1;
          setupStage = 2;
          //for (int i = 0; i < 32; ++i)
          //  {
          //    currentSSID += //char(EEPROM.read(i));
          //    }
          currentSSID = WiFi.SSID(cursorPosition);
          cursorPosition = 0;
          currentPassword = "";
          loadLetters(cursorPosition);
          //WiFi.SSID(cursorPosition)
          ui.transitionToFrame(2);
        }
      }
      else btnState4 = 0;
      break;
    //
    case 2: // Enter Password
      if (btn1 == 0) { // Password : Sel
        if ( btnState1 == 0 ){
          btnState1 = 1;
          setupStage = 3;
        }
      } else btnState1 = 0;

      if (btn2 == 0) { // Pbassword +
        if ( btnState2 == 0 ){
          btnState2 = 1;
          if (cursorPosition < numberOfLetters-1) cursorPosition ++;
          else cursorPosition = 0;
          loadLetters(cursorPosition);
          //
        }
      } else btnState2 = 0;
      //
      if (btn3 == 0) { // Password -
        if ( btnState3 == 0 ){
          btnState3 = 1;
          if (cursorPosition > 0) cursorPosition --;
          else cursorPosition = numberOfLetters-1;
          loadLetters(cursorPosition);
          //
        }
      } else btnState3 = 0;

      if (btn4 == 0) { // Password : OK
        if ( btnState4 == 0 ){
          btnState4 = 1;
          currentPassword += char(passwordLetters[cursorPosition+4]);
          //
        }
      } else btnState4 = 0;
      break;
      default:
        if (currentSSID.length() > 0 && currentPassword.length() > 0) {
          Serial.println("clearing eeprom");
          for (int i = 0; i < 96; ++i) { EEPROM.write(i, 0); }
          Serial.print(currentSSID);
          Serial.print("; ");
          Serial.println(currentPassword);
          //Serial.println("");

          Serial.println("writing eeprom ssid:");
          for (int i = 0; i < currentSSID.length(); ++i)
            {
              EEPROM.write(i, currentSSID[i]);
              Serial.print("Wrote: ");
              Serial.println(currentSSID[i]);
            }
          Serial.println("writing eeprom pass:");
          for (int i = 0; i < currentPassword.length(); ++i)
            {
              EEPROM.write(32+i, currentPassword[i]);
              Serial.print("Wrote: ");
              Serial.println(currentPassword[i]);
            }
          EEPROM.commit();
        }
        WiFi.begin (currentSSID.c_str(), currentPassword.c_str());
        //ESP.restart();
        setupStage = 0;
        setupMode = 0;
      break;
    }
}
else {
      if ( btn2 == 0 ){
        if ( btnState2 == 0 ){
          btnState2 = 1;
          if (displayMode ==2) {
            if (displayState < 5) displayState ++;
            else displayState = 0;
          } else {
            displayMode = 2;
            displayState = 0;
            ui.disableAllIndicators();
            ui.disableAutoTransition();
            ui.setFrameAnimation(SLIDE_RIGHT);// You can change the transition that is used   // SLIDE_LEFT, SLIDE_RIGHT, SLIDE_UP, SLIDE_DOWN
            ui.setFrames(framesLogo, framesLogoCount);  // Add frames
          }
          ui.nextFrame();
        }
      } else btnState2 = 0;
      //
      if ( btn1 == 0 ){
        if ( btnState1 == 0 ){
          btnState1 = 1;
          if (displayMode ==1) {
            if (displayState < 2) displayState ++;
            else displayState = 0;
          } else {
            displayMode = 1;
            displayState = 0;
            //ui.setFrameAnimation(SLIDE_LEFT);// You can change the transition that is used   // SLIDE_LEFT, SLIDE_RIGHT, SLIDE_UP, SLIDE_DOWN
            ui.setFrames(framesClocks, framesClocksCount);  // Add frames
            ui.enableAllIndicators();
            ui.disableAutoTransition();
            ui.setFrameAnimation(SLIDE_RIGHT);// You can change the transition that is used   // SLIDE_LEFT, SLIDE_RIGHT, SLIDE_UP, SLIDE_DOWN
          }
          ui.nextFrame();
        }
      } else btnState1 = 0;
      //
      if ( btn3 == 0 ){
        if ( btnState3 == 0 ){
          btnState3 = 1;
          if (displayMode == 3) {
            if (displayState < 1) displayState ++;
            else displayState = 0;
          } else {
            displayMode = 3;
            displayState = 0;
            ui.setFrameAnimation(SLIDE_LEFT);// You can change the transition that is used   // SLIDE_LEFT, SLIDE_RIGHT, SLIDE_UP, SLIDE_DOWN
            ui.setFrames(framesSocket, framesSocketCount);  // Add frames
            ui.disableAllIndicators();
            ui.disableAutoTransition();
            ui.setFrameAnimation(SLIDE_RIGHT);// You can change the transition that is used   // SLIDE_LEFT, SLIDE_RIGHT, SLIDE_UP, SLIDE_DOWN
          }
          ui.nextFrame();
        }
      } else btnState3 = 0;
      // Network
      if ( btn4 == 0 ){
        if ( btnState4 == 0 ){
          btnState4 = 1;
          if (displayMode == 4) {
            if (displayState < 2) displayState ++;
            else displayState = 0;
          } else {
            displayMode = 4;
            displayState = 0;
            ui.setFrameAnimation(SLIDE_LEFT);// You can change the transition that is used   // SLIDE_LEFT, SLIDE_RIGHT, SLIDE_UP, SLIDE_DOWN
            ui.setFrames(framesNetwork, framesNetworkCount);  // Add frames
            ui.disableAllIndicators();
            ui.disableAutoTransition();
          }
          ui.nextFrame();
        }
      } else btnState4 = 0;
    }
}
    delay(remainingTimeBudget);
  }
  //
