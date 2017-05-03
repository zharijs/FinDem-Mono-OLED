#ifndef CLOCK_h
#define CLOCK_h

//#include <Arduino.h>

//#include <ESP8266mDNS.h>
#include "frames.h"

int timeZone = 2;
bool timeSummer = true;

unsigned int localPort = 2390;
//IPAddress timeServer(129, 6, 15, 28); // time.nist.gov NTP server
IPAddress timeServerIP; // time.nist.gov NTP server address
const char* ntpServerName = "time.nist.gov";
const int NTP_PACKET_SIZE = 48; // NTP time stamp is in the first 48 bytes of the message
byte packetBuffer[ NTP_PACKET_SIZE]; //buffer to hold incoming and outgoing packets
WiFiUDP udp; // A UDP instance to let us send and receive packets over UDP
//WiFiTCP tcp;



unsigned long sendNTPpacket(IPAddress& address)
{
  Serial.println("sending NTP packet...");
  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)
  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;

  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  udp.beginPacket(address, 123); //NTP requests are to port 123
  udp.write(packetBuffer, NTP_PACKET_SIZE);
  udp.endPacket();
}

//###[NTP state machine]#######################################################

unsigned int ntpState = 0;
unsigned long ntpDelay;
int cb;
unsigned long highWord;
unsigned long lowWord;
unsigned long secsSince1900;
const unsigned long seventyYears = 2208988800UL;  // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
unsigned long epoch;
unsigned long localTime;

void getNTP (void) {
  switch (ntpState){
    case 0:
      WiFi.hostByName(ntpServerName, timeServerIP);
      sendNTPpacket(timeServerIP); // send an NTP packet to a time server
      ntpDelay = now();
      ntpState = 1;
      Serial.print(ntpServerName);
      Serial.print(" -> ");
      Serial.print(timeServerIP);
      Serial.println(";");
      return;
    break;
    case 1:
      if ((ntpDelay + 5) < now()) ntpState = 2;
      return;
    break;
    case 2:
      cb = udp.parsePacket();
      if (!cb) {
        Serial.println("no packet yet");
        ntpState = 128;
      } else ntpState = 3;
      return;
    break;
    case 3:
      Serial.print("packet received, length=");
      Serial.println(cb);  // We've received a packet, read the data from it
      udp.read(packetBuffer, NTP_PACKET_SIZE); // read the packet into the buffer
      highWord = word(packetBuffer[40], packetBuffer[41]);  //the timestamp starts at byte 40 of the received packet and is four bytes,
      lowWord = word(packetBuffer[42], packetBuffer[43]);  // or two words, long. First, esxtract the two words:
      secsSince1900 = highWord << 16 | lowWord;  // combine the four bytes (two words) into a long integer
      Serial.print("Seconds since Jan 1 1900 = " );  // this is NTP time (seconds since Jan 1 1900):
      Serial.println(secsSince1900);
      Serial.print("Unix time = "); // now convert NTP time into everyday time:
      epoch = secsSince1900 - seventyYears;  // subtract seventy years:
      Serial.println(epoch);  // print Unix time:
      Serial.print("The UTC time is ");       // UTC is the time at Greenwich Meridian (GMT)
      Serial.print((epoch  % 86400L) / 3600); // print the hour (86400 equals secs per day)
      Serial.print(':');
      if ( ((epoch % 3600) / 60) < 10 ) {
        Serial.print('0');// In the first 10 minutes of each hour, we'll want a leading '0'
      }
      Serial.print((epoch  % 3600) / 60); // print the minute (3600 equals secs per minute)
      Serial.print(':');
      if ( (epoch % 60) < 10 ) {
        Serial.print('0');// In the first 10 seconds of each minute, we'll want a leading '0'
      }
      Serial.println(epoch % 60); // print the second
      //
      if (timeSummer) localTime = epoch + long(3600 * (timeZone+1));
      else localTime = epoch + long(3600 * timeZone);
      Serial.print("The Local time is ");       // UTC is the time at Greenwich Meridian (GMT)
      Serial.print((localTime  % 86400L) / 3600); // print the hour (86400 equals secs per day)
      Serial.print(':');
      if ( ((localTime % 3600) / 60) < 10 ) {
        Serial.print('0');
        display.drawString(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2 - 10, "Main loop...");
      }
      Serial.print((localTime  % 3600) / 60); // print the minute (3600 equals secs per minute)
      Serial.print(':');
      if ( (localTime % 60) < 10 ) {
        Serial.print('0');
      }
      Serial.println(localTime % 60); // print the second
      //
      setTime(localTime);
      ntpState = 128;
      return;
    break;
    case 128:
      ntpDelay = now();
      ntpState = 129;
      return;
    break;
    case 129:
      if ((ntpDelay + 55) < now()) ntpState = 130;
      return;
    break;
    case 130:
      ntpState = 0;
      return;
    break;
    default:
      ntpState = 128;
      return;
    break;
  }

}

#endif
