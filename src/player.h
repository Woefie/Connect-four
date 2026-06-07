#ifndef PLAYER_H
#define PLAYER_H

#include <cstdint>




/**
 * Interface class for the user that play the game of connect four
 * This is used so the derived classes Participent and Computer can be called. from the game class
*/
class Participent{
public:

  Participent()=default;
  Participent(const Participent&) = default;
  Participent(Participent&&) = delete;
  auto operator=(const Participent&) -> Participent& = default;
  auto operator=(Participent&&) -> Participent& = delete;
  explicit Participent(uint8_t number)
      : m_user_number(number)
  {
  }

  virtual ~Participent() = default;
  virtual auto get_placement() -> const uint32_t = 0;
  
  [[nodiscard]] auto get_number() const -> uint8_t{
    return m_user_number;
  }
private:
  uint8_t m_user_number{0};
};

#endif // PLAYER_H