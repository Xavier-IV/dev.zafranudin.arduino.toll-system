/*******************************************************************************
 * Copyright (c) 2021.
 *
 * Author: Zafranudin Zafrin
 * Facebook: https://www.facebook.com/Hobi-Elektronik-110633564588022
 * Youtube: https://www.youtube.com/ZafranudinZafrin
 ******************************************************************************/

/** NANO as transmitter */

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "user.h"
#include "card_reader.h"

CardReader card_reader;

RF24 radio(7, 6); // CE, CSN

const String user_db = "{\"29 57 64 3a\":{\"name\":\"Zaf\",\"balance\":8.5},\"23 5f cc 04\":{\"name\":\"Fina\",\"balance\":18.3}}";
const byte address[6] = "toll01";
String uid;

struct Payload {
  double balance;
  int status_user;
};

Payload payload;

User user(user_db);

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);

  while (!Serial) delay(100);

  while (!radio.begin()) delay(100);

  radio.powerUp();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

  card_reader.register_reader();

  digitalWrite(2, HIGH);
}

void loop() {
  if (!card_reader.new_card()) {
    return;
  }

  uid = card_reader.read_card();
  user.find(uid);

  if (!user.exists()) {
    payload.balance = user.get_balance();
    payload.status_user = 10;
    radio.write(&payload , sizeof(payload));
    delay(1000);
    return;
  }

  if (!user.deduct(2.0)) {
    payload.balance = user.get_balance();
    payload.status_user = 20;
    radio.write(&payload , sizeof(payload));
    delay(1000);
    return;
  }

  payload.balance = user.get_balance();
  payload.status_user = 30;
  radio.write(&payload , sizeof(payload));

  user_db = user.update();

  delay(1000);
}
