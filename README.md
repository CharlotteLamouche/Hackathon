# Hackaton
We were asked to create a connected object in 24h. Here is what we've come up with !

## Project :
Make a connected speakerLamp ! The idea is to have a webserver hosted on a Raspberry Pi where the user can choose a music. The music is then analysed to determine a color which represents the mood of the music. All the connected speakerLamps then change color and play the selected music !

### Webserver
The webserver is hosted on the Raspberry Pi. 
It's coded in Python using Django.
We use the GPIO ports to transmit to the arduino using 433Mhz emitter (using the awesome pigpio library).

The analyser which determines the color of the music can be found in Django/lampe/music/analysis_music.py
The RF transmitter is connected to GPIO 25 and the emitting script can be found in Django/lampe/music/emit.py

### Arduino
The arduino code is separated in two parts :

#### Emitter
The emitter is used for debug purposes. It send a 'T' on 433Mhz to test if the speaker can receive it.

#### Speaker
We didn't had time to implement audio streaming from the Raspberry to the Arduino. The music is stored on an SD card. The Raspberry transmit the color of the lamp and which music to play.

## Ressources :
* http://electroniqueamateur.blogspot.fr/2014/01/modules-rf-433-mhz-virtualwire-et.html
* https://az835927.vo.msecnd.net/sites/iot/Resources/images/PinMappings/RP2_Pinout.png
* https://www.pjrc.com/teensy/td_libs_VirtualWire.html
* https://www.mbeckler.org/microcontrollers/rgb_led/led_pinout.png

## Credits :
* Charlotte Lamouche
* Lola Jean--Cadène
* Théo Bocquelet
* Grégoire Martinache
