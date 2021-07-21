/*******************************************************************************
 * Copyright (c) 2021.
 *
 * Author: Zafranudin Zafrin
 * Facebook: https://www.facebook.com/Hobi-Elektronik-110633564588022
 * Youtube: https://www.youtube.com/ZafranudinZafrin
 ******************************************************************************/

#ifndef CARD_READER_h
#define CARD_READER_h

#include <Arduino.h>
#include <MFRC522.h>

using namespace std;

class CardReader {
  private:
    const int SS_PIN = 5, RST_PIN = 4;
    MFRC522 mfrc522 = MFRC522(SS_PIN, RST_PIN);

  public:
    void register_reader();
    bool new_card();
    String read_card();
};

#endif
