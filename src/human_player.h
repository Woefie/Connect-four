#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "player.h"

class HumanPlayer : public Participent
{
public:
  using Participent::Participent;
  HumanPlayer() = default;
  explicit HumanPlayer(uint8_t);

  /**
   * Get players input between 0 and 6
   */
  [[nodiscard]] auto get_placement() -> uint32_t override;
};

#endif  // HUMAN_PLAYER_H