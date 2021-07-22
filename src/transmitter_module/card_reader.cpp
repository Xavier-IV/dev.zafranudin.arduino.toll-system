/*******************************************************************************
 * Copyright (c) 2021.
 *
 * Author: Zafranudin Zafrin
 * Facebook: https://www.facebook.com/Hobi-Elektronik-110633564588022
 * Youtube: https://www.youtube.com/ZafranudinZafrin
 ******************************************************************************/

#include "card_reader.h"

void CardReader::register_reader() {
  mfrc522.PCD_Init();
  delay(4);
  mfrc522.PCD_DumpVersionToSerial();
}

bool CardReader::new_card() {
  return mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial();
}

String CardReader::read_card() {
  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  return content.substring(1);
}
