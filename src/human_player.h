#pragma once
#include "player.h"

class HumanPlayer : public Player{
  public:
  HumanPlayer()=default;
  explicit HumanPlayer(uint8_t);

  /**
   * Get players input between 0 and 6
  */
  [[nodiscard]] auto get_placement() -> const uint32_t override ;


};