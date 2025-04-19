#pragma once

#include <array>
#include <utility>
#include <cstdint>

constexpr uint8_t BOARD_HEIGHT {6};
constexpr uint8_t BOARD_WIDTH {7};

class Board
{
public:
  Board() = default;
  ~Board()= default;

  // Delete copy and move constructors
  Board(const Board& other) = delete;
  Board(Board&& other) = delete;
  auto operator=(const Board& other) -> Board& = delete;
  auto operator=(Board&& other) -> Board& = delete;

  /**
   * Set the puck on the board
   * @param[in, out] point will be used for placing a puck on the board
   * @param[in] player value to be put on the board
   * 
   * @return true if value was succesfull in placing the puck
  */
  [[nodiscard]] auto set_puck(std::pair<uint8_t, uint8_t>& point, uint8_t player) -> bool;

  /**
   * Check if last set puck has a winning position
   * @param[in] point containing coordinates of a placed puck
   * @return true if last point was winnig
  */
  [[nodiscard]] auto check_for_win( std::pair<uint8_t, uint8_t> point) -> bool;
  
  /**
   * Check if the board is full
   * @return true if full
  */
  [[nodiscard]] auto is_full() -> bool;

  /**
   * Print out a stylized connect four board on the command line
  */
  void print_board();

 
private:
  uint8_t m_last_player{};
  std::array<std::array<uint8_t, BOARD_WIDTH>, BOARD_HEIGHT> m_board {0};
};