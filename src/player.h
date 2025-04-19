#pragma once
#include "board.h"




/**
 * Interface class for the user that play the game of connect four
 * This is used so the derived classes Player and Computer can be called. from the game class
*/
class Player{
public:

  Player()=default;
  Player(const Player&) = default;
  Player(Player&&) = delete;
  auto operator=(const Player&) -> Player& = default;
  auto operator=(Player&&) -> Player& = delete;
  explicit Player(uint8_t number)
      : m_user_number(number)
  {
  }

  virtual ~Player() = default;
  virtual auto get_placement() -> const uint32_t = 0;
  
  [[nodiscard]] auto get_number() const -> const uint8_t{
    return m_user_number;
  }
protected:
  uint8_t m_user_number{0};
};