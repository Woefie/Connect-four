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
  */
  bool SetPuck(std::pair<uint8_t, uint8_t>& point, uint8_t player);

  /**
   * Check if last set puck has a winning position
  */
  bool CheckForWin(const std::pair<uint8_t, uint8_t> point);
  /**
   * Check if the board is full
   * @return If full return true else false
  */
  bool IsFull();

  /**
   * Print out the board
  */
  void PrintBoard();

 
private:
  uint8_t last_player;
  std::array<std::array<uint8_t, BOARD_WIDTH>, BOARD_HEIGHT> board {0};
};