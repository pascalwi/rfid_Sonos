# rfid_Sonos
play spotify playlist on sonos via rfid reader> esp8266 > raspberry > sonos
## general
I want to be able to place a cd-case with a passive rfid-chip on a specified location and the Sonos speaker should play this album/playlist. Maybe there is an additional switch and/or potentiometer to adjust shuffle / volume.
I don't want to use the rpi directly, because it is somewhere else and also too bulky. So the rfid reader should be connected with an esp8266 wifi microcontroller. 
The esp8266 then connects wirelessly to the rpi and the rpi controls the Sonos speaker
## what you need
- [rfid reader](https://www.amazon.de/AZDelivery-Reader-Arduino-Raspberry-gratis/dp/B074S9FZC5/ref=sr_1_6?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=E4CHPTG0BWK2&dchild=1&keywords=rfid+raspberry+pi&qid=1600594839&sprefix=rfid+raspberry%2Caps%2C242&sr=8-6) _10€ for 5, ordered
- [nodeMCU esp8266](https://www.amazon.de/AZDelivery-NodeMCU-ESP8266-ESP-12E-Development/dp/B0754HWZSQ/ref=sr_1_3?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=3OXGIP9RVMAB4&dchild=1&keywords=nodemcu+esp8266&qid=1600618699&sprefix=nodem%2Caps%2C297&sr=8-3) _still got one I think, order new ones for safety, 14€ for 3, ordered_
- rpi 

## todo
###V1
#### esp8266
- micro usb to nodeMCU
- connect wifi and mqtt
- power and read rfid reader with nodeMCU
- broadcast album/playlist
#### rpi
- listen to broadcast
- host [node-sonos-http-api](https://github.com/jishi/node-sonos-http-api) to control Sonos speaker
###V2
- directly from esp to sonos is easier
- either with micropython and [node-sonos-http-api](https://github.com/jishi/node-sonos-http-api), not sure if esp powerful/big enough
- or [sonos-esp](https://github.com/bopeterson/sonos-esp) seems more lightweight ? not sure
