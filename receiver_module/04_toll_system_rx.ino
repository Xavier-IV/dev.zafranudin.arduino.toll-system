/*******************************************************************************
 * Copyright (c) 2021.
 *
 * Author: Zafranudin Zafrin
 * Facebook: https://www.facebook.com/Hobi-Elektronik-110633564588022
 * Youtube: https://www.youtube.com/ZafranudinZafrin
 ******************************************************************************/

/** UNO as receiver */

#include <LiquidCrystal.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

#define SERIAL_DEBUG 1

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
RF24 radio(A1, A2); // CE, CSN

Servo servo_1;

const byte address[6] = "toll01";
const int servo_1_pin = 3, buzzer_pin = 2, red_pin = A4, green_pin = A5;

struct Payload {
  double balance;
  int status_user;
};

Payload payload;

float test[2];

void setup() {
  Serial.begin(9600);

  while (!Serial) delay(100);

  while (!radio.begin()) delay(100);

  lcd.begin(16, 2);

  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  servo_1.attach(servo_1_pin);
  servo_1.write(180);

  pinMode(buzzer_pin, OUTPUT);
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
}

void loop() {
  lcd.clear();

  if (radio.available()) {

    radio.read(&payload, sizeof(payload));

    Serial.println(payload.balance);
    Serial.println(payload.status_user);

    switch (payload.status_user) {
      case 10:
        lcd.setCursor(0, 0);
        lcd.print("Invalid card");

        digitalWrite(red_pin, HIGH);

        digitalWrite(buzzer_pin, HIGH);
        delay(200);
        digitalWrite(buzzer_pin, LOW);
        delay(200);
        digitalWrite(buzzer_pin, HIGH);
        delay(200);
        digitalWrite(buzzer_pin, LOW);

        delay(1000);
        digitalWrite(red_pin, LOW);
        break;
      case 20:
        lcd.setCursor(0, 0);
        lcd.print("Low balance");
        lcd.setCursor(0, 1);
        lcd.print("RM " + String(payload.balance, 2));

        digitalWrite(red_pin, HIGH);

        digitalWrite(buzzer_pin, HIGH);
        delay(200);
        digitalWrite(buzzer_pin, LOW);
        delay(200);
        digitalWrite(buzzer_pin, HIGH);
        delay(200);
        digitalWrite(buzzer_pin, LOW);
        delay(200);
        digitalWrite(buzzer_pin, HIGH);
        delay(200);
        digitalWrite(buzzer_pin, LOW);

        delay(1000);
        digitalWrite(red_pin, LOW);
        break;
      case 30:
        lcd.setCursor(0, 0);
        lcd.print("Welcome");
        lcd.setCursor(0, 1);
        lcd.print("RM " + String(payload.balance, 2));

        digitalWrite(green_pin, HIGH);


        digitalWrite(buzzer_pin, HIGH);
        delay(500);
        digitalWrite(buzzer_pin, LOW);

        servo_1.write(90);
        delay(3000);
        digitalWrite(green_pin, LOW);
        break;
    }
  }
  servo_1.write(180);
}
