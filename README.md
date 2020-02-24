# Carlandoo, the 1:32 Local\Internet controlled Crawler #

## See explanation video here: ##
https://www.youtube.com/watch?v=6lzFsBAROm0


It's been a while since I've wanted to control a car using a mobile phone.
I got to work and found these amazing devices called ESP8266 that create their own wifi network and an even more amazing app called RemoteXY that allows you to connect to said ESP8266 AND even design your own graphic inferface.

While studying this app I found it even is able to host a middle man server that your ESP connects to.
This means that if you want to control your ESP via the internet you don't have to open up ports in your router, like you do with other apps.

For your benefit I made two seperate codes, one for controlling the Carlandoo locally and one for controlling it over the internet.


## DOWNLOAD THE APP

* Remotexy is available for IOS and Android >> http://remotexy.com
* If you intend to run this car over the internet you will need to register for a free account.
* Just as a note, I have 0 involvement with this company. I just found it to be a really great app for what I wanted to do :)


## PRINT THE PARTS

* 3D print of the Carlandoo parts. 
* Follow the guide in https://www.thingiverse.com/thing:3928745


## BUILD THE ELECTRONICS

You will need the following electronic parts as mentioned in Thingyverse*

1x ESP8266 (https://www.banggood.com/Geekcreit-NodeMcu-Lua-WIFI-Internet-Things-Development-Board-Based-ESP8266-CP2102-Wireless-Module-p-1097112.html)
- 3x 2.2g servos (1 is steering servo, the others are motor servos) > https://www.dronejunkie.co.uk/22g-servo
- 2x 40mm white leds
- 1x brushed 1s ESC > https://www.dronejunkie.co.uk/dasmikro-1s5a-micro-bi-directional-esc
- 1s battery (recommend tiny whoop battery) > https://www.dronejunkie.co.uk/mylipo-255mah-435v-hv-25c-50c-mcpx-pw
- battery connector (recommend mxcp connector) > https://www.dronejunkie.co.uk/mylipo-lead-and-socket-for-mcpxpw-type-lipos

*For the FPV version follow the additional FPV parts list in https://www.thingiverse.com/thing:3928745

Start by placing the ESP8266 in the bottom part of the base body of the Carlandoo.
I prefer putting the USB facing backwards so it's easier to install the code afterwards

Here comes the hard part. It's best if you watch this video to understand what is being done >> https://youtu.be/6lzFsBAROm0?t=883

You will need to open up two of the 2.2g servos and remove the small esc inside.
Once the esc is removed, extend the motor cables from inside the servo so they will be able to reach the ESC.
Connect the motors in paralell to the ESC motor connection.

* Connect battery connector to ESC
* Connect esc + to VIN on your esp8266
* Connect esc - to Ground on your esp8266
* Connect esc signal to D3
* Connect steering servo + (red cable) to VIN on your esp8266
* Connect steering servo - (black cable) to Ground on your esp8266
* Connect steering servo signal (yellow cable) to D5

If you want to have lights to your vehicle the code is already done!
* Connect LED negative pole to Ground on your esp8266
* Connect LED positive pole to D6




## LOCAL CARLANDOO CODE

Connect the esp8266 to your computer with a usb cable and load up the localcarlando.ino code using Arduino IDE.
If you don't know how to use Arduino IDE with ESP8266 please watch this short video: https://www.youtube.com/watch?v=OC9wYhv6juM
My upload settings are:
Board: Wemos D1 R1
Erase flash: All flash contents
All other settings are default

Once the flash is complete connect a battery to your Carlandoo, wait a few moments and you should be able to see a new network appear in your phone.
- Connect to this wireless network
- and then launch RemoteXY app
- in RemoteXY app click top right + and select WIFI Point

You should now be connected to your Carlandoo.
Enjoy!





## INTERNET CARLANDOO CODE

Before uploading any code you need to register for a free account in remotexy.com
Once registered, log in and press My Tokens on the top right of the page.
Create a new token for your car. Name it as you see fit.


Connect the esp8266 to your computer with a usb cable and load up the internetcarlando.ino code using Arduino IDE.
If you don't know how to use Arduino IDE with ESP8266 please watch this short video: https://www.youtube.com/watch?v=OC9wYhv6juM
Before uploading you will need to change a few settings.

You will need to fill in your access point name (any accesspoints with spaces will NOT work)
Then you need to fill in your access point password
And finally you will need to fill in the token you got from remotexy.com

You are now ready for upload :)

My upload settings are:
Board: Wemos D1 R1
Erase flash: All flash contents
All other settings are default

Once the flash is complete connect a battery to your Carlandoo, wait a few moments and your Carlandoo should now be connected to your accesspoint.
- Launch RemoteXY app
- in RemoteXY app click top right + and select Cloud
- Leave the other fields as they are and fill in your token.

You should now be connected to your Carlandoo and you or anyone with that token will be able to control it from anywhere in the world!!
Enjoy!


# CONTACTS

- https://www.youtube.com/SeekNDFPV
- https://www.facebook.com/SeekNDFPV/


# SUPPORT

If you'd like to help support the project please contribute with ideas.

If you would like to contribute in another way, I would be very grateful as well.
http://paypal.me/SeekND

Thank you for your support!!
