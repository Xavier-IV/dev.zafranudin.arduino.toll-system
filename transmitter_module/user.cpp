/*******************************************************************************
 * Copyright (c) 2021.
 *
 * Author: Zafranudin Zafrin
 * Facebook: https://www.facebook.com/Hobi-Elektronik-110633564588022
 * Youtube: https://www.youtube.com/ZafranudinZafrin
 ******************************************************************************/

#include "user.h"
#include <ArduinoJson.h>


User::User() {}

User::User(String json) {
  deserializeJson(_doc, json);
}

void User::find(String uid) {
  _uid = uid;
  _name = _doc[_uid]["name"].as<String>();
  _balance = _doc[_uid]["balance"].as<double>();
}

bool User::has_enough_balance() {
  return (double)_balance > _min_balance;
}

bool User::deduct(double amount) {
  if (_balance < amount) return false;
  if (_balance - amount < _min_balance) return false;
  _doc[_uid]["balance"] = (double)_doc[_uid]["balance"] - amount;
  return true;
}

String User::update() {
  String updated;
  serializeJson(_doc, updated);
  return updated;
}

double User::get_balance() {
  return _doc[_uid]["balance"].as<double>();
}

bool User::exists() {
  return _doc[_uid];
}
