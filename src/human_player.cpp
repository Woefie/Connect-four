#include <iostream>
#include <limits>

#include "human_player.h"

#include <fmt/printf.h>
#include <fmt/format.h>

HumanPlayer::HumanPlayer(uint8_t number)
    : Player(number)
{
}

auto HumanPlayer::get_placement() -> const uint32_t
{
  uint32_t input {0};
  fmt::print("Enter a number between 1 and 7: ");
  std::cin >> input;

  while ( input < 1 || input > BOARD_WIDTH|| std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    fmt::print("Invalid input. Please enter a number between 1 and 7: ");
    std::cin >> input;
  }

  fmt::print("Input accepted: {:x}\n", input);
  return input-1;
}