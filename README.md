# Toll System
###### By Zafranudin Zafrin


This project is to help me understand how to sandbox with complex multi Arduino projects.

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