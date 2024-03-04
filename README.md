# Toll System
###### By Zafranudin Zafrin


This project is to help me understand how to sandbox with complex multi Arduino projects.

<img width="400" alt="image" src="https://github.com/Xavier-IV/dev.zafranudin.arduino.toll-system/assets/14009259/1d836479-4b67-46bb-896c-6d6624b8d564">

See the project in action at:
https://www.facebook.com/watch/?v=192834632804605

Package Library Used:

- https://github.com/miguelbalboa/rfid
- https://github.com/nRF24/RF24

## Receiver Module

This module will receive incoming data from the transmitter and display relevant information.

Able to control Servos (example given) for controlling user or vehicle activities.


## Transmitter Module

The main logic controller that uses RFID to read user data. Have mock in-memory database
that can be further refine with API call.

Contains classes:
- CardReader
- User

That allows manageable code structure and scalability. Adhering SOLID principle for code.

## Follow and Subscribe

* Like our [Facebook](https://fb.me/hobielektronik.101) page
* Subscribe to our [Youtube](https://www.youtube.com/ZafranudinZafrin) channel
