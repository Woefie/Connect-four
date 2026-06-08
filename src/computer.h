#ifndef COMPUTER_H
#define COMPUTER_H

#include <cstdint>

#include "player.h"

class Computer : public Participent
{
public:
  using Participent::Participent;
  Computer() = default;
  explicit Computer(uint8_t);

  /**
   * Return a randomized number between 0 and 6
   */
  [[nodiscard]] auto get_placement() -> uint32_t override;
};

#endif  // COMPUTER_H