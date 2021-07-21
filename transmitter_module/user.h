/*******************************************************************************
 * Copyright (c) 2021.
 *
 * Author: Zafranudin Zafrin
 * Facebook: https://www.facebook.com/Hobi-Elektronik-110633564588022
 * Youtube: https://www.youtube.com/ZafranudinZafrin
 ******************************************************************************/

#ifndef USER_h
#define USER_h

#include <Arduino.h>
#include <ArduinoJson.h>

using namespace std;

class User {
  private:
    String _uid;
    String _name;
    double _balance;
    double _min_balance = 5.0;
    StaticJsonDocument<200> _doc;

  public:
    User();
    User(String json);
    void find(String uid);
    bool has_enough_balance();
    bool deduct(double amount);
    String update();
    bool exists();
    double get_balance();
};

#endif
