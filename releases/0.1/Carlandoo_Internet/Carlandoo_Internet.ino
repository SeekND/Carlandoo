/*
   -- Carlandoo --

   by Carlos Costa (SeekNDFPV @ youtube)

   This source code of graphical user interface
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 2.4.3 or later version
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/
     - for ANDROID 4.3.1 or later version;
     - for iOS 1.3.5 or later version;

   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
*/
// User interface: Change the three values below

#define REMOTEXY_WIFI_SSID "enter_your_ssid_here"
#define REMOTEXY_WIFI_PASSWORD "enter_your_ssid_pass_here"
#define REMOTEXY_CLOUD_TOKEN "enter_your_token_here_from_remotexy"

// End of user interface. Don't change any values below

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library
#define REMOTEXY_MODE__ESP8266WIFI_LIB_CLOUD
#include <ESP8266WiFi.h>
#include <RemoteXY.h>
#include <Servo.h>

Servo myservo;
Servo myesc;

// RemoteXY connection settings 
#define REMOTEXY_CLOUD_SERVER "cloud.remotexy.com" // leave this alone
#define REMOTEXY_CLOUD_PORT 6376 // leave this alone


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,5,0,14,0,45,0,8,42,0,
  3,130,29,3,22,12,16,26,4,16,
  0,0,21,63,2,26,4,16,81,0,
  21,63,2,26,5,5,32,23,38,38,
  2,26,31,67,4,54,6,24,5,2,
  26,14 };
  
// this structure defines all the variables of your control interface 
struct {

    // input variable
  uint8_t select_1; // =0 if select position A, =1 if position B, =2 if position C, ... 
  int8_t slider_1; // =0..100 slider position 
  int8_t slider_2; // =0..100 slider position 
  int8_t joystick_1_x; // =-100..100 x-coordinate joystick position 
  int8_t joystick_1_y; // =-100..100 y-coordinate joystick position 

    // output variable
  char text_1[14];  // string UTF8 end zero 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_SWITCH_1 12   // D6 - connect lights (positive leg) here, negative leg goes in ground


char str[] = "Mins on:";
unsigned long whattime;

void setup()
{
  RemoteXY_Init ();

  pinMode (PIN_SWITCH_1, OUTPUT);

  myservo.attach(14);   // D5 - connect steering servo signal cable here
  myesc.attach(0);      // D3 - connect ESC signal cable here
  
  Serial.begin(9600);

}

void loop()
{
  RemoteXY_Handler ();

  int steering =  map(RemoteXY.joystick_1_x, -100, 100, 1700, 1300); // steering, max 1700 min 1300
  myservo.writeMicroseconds(steering);

  if ( RemoteXY.slider_2 > 0 )
  {
    int forward =  map(RemoteXY.slider_2, 0, 100, 1500, 2000);   // going forward, max 2000, min 1500 (center)
    myesc.writeMicroseconds(forward);
  }
  else
  {

    int reverse =  map(RemoteXY.slider_1, 0, 100, 1500, 1000);  // going backwards, max 1000, min 1500 (center)
    myesc.writeMicroseconds(reverse);
  }

  whattime = millis() / 60000;
   sprintf (RemoteXY.text_1, "%s %d", str, whattime);             // will display how long the arduino has been on in the interface

   if (RemoteXY.select_1!=0) digitalWrite(PIN_SWITCH_1, HIGH);        
  else digitalWrite(PIN_SWITCH_1, LOW);                                     // turns on the lights

}
