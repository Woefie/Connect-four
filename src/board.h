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

  // Delete copy and move constructors
  Board(const Board& other) = delete;
  Board(Board&& other) = delete;
  Board& operator=(const Board& other) = delete;
  Board& operator=(Board&& other) = delete;

  /**
   * Set the puck on the board
   * @param[in, out] point will be used for placing a puck on the board
   * @param[in] player value to be put on the board
   * 
   * @return true if value was succesfull in placing the puck
  */
  [[nodiscard]] bool SetPuck(std::pair<uint8_t, uint8_t>& point, uint8_t player);

  /**
   * Check if last set puck has a winning position
   * @param[in] point containing coordinates of a placed puck
   * @return true if last point was winnig
  */
  [[nodiscard]] bool CheckForWin(const std::pair<uint8_t, uint8_t> point);
  
  /**
   * Check if the board is full
   * @return true if full
  */
  [[nodiscard]] bool IsFull();

  /**
   * Print out a stylized connect four board on the command line
  */
  void PrintBoard();

 
private:
  uint8_t last_player;
  std::array<std::array<uint8_t, BOARD_WIDTH>, BOARD_HEIGHT> board {0};
};