#pragma once
#include "board.h"


class IUser{
public:

  IUser()=default;
  IUser(uint8_t number): user_number(number){

  }

  virtual ~IUser() = default;
  virtual const uint32_t GetPlacement() = 0;

  const uint8_t GetNumber(){
    return user_number;
  }
protected:
  uint8_t user_number{0};
};