#pragma once
#include "board.h"




/**
 * Interface class for the user that play the game of connect four
 * This is used so the derived classes Player and Computer can be called. from the game class
*/
class IUser{
public:

  IUser()=default;
  IUser(uint8_t number): user_number(number){

  }

  virtual ~IUser() = default;
  virtual const uint32_t GetPlacement() = 0;
  
  [[nodiscard]] const uint8_t GetNumber(){
    return user_number;
  }
protected:
  uint8_t user_number{0};
};