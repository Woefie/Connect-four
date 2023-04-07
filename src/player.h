#pragma once
#include "iuser.h"

class Player : public IUser{
  public:
  Player()=default;
  Player(uint8_t);

  /**
   * Get players input between 0 and 6
  */
  [[nodiscard]] const uint32_t GetPlacement() override;


};