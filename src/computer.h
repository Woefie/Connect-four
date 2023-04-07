#pragma once
#include "iuser.h"

class Computer : public IUser{
  public:
  Computer()=default;
  Computer(uint8_t);

  /**
   * Return a randomised number between 0 and 6
  */
  [[nodiscard]] const uint32_t GetPlacement()  override;


};