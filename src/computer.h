#pragma once
#include "player.h"

class Computer : public Player{
  public:
  Computer()=default;
  explicit Computer(uint8_t);

  /**
   * Return a randomised number between 0 and 6
  */
  [[nodiscard]] auto get_placement() -> const uint32_t  ;


};