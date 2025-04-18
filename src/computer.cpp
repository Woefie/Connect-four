#include <random>

#include "computer.h"

#include "board.h"

Computer::Computer(uint8_t number)
    : Player(number)
{
}


auto Computer::get_placement() -> const uint32_t
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<uint32_t> distrib(0, BOARD_WIDTH - 1);
  return distrib(gen);
}