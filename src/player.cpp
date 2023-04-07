#include <iostream>

#include "player.h"

#include <fmt/printf.h>
#include <fmt/format.h>

Player::Player(uint8_t number)
    : IUser(number)
{
}

const uint32_t Player::GetPlacement()
{
  uint32_t input {0};
  fmt::print("Enter a number between 0 and 6: ");
  std::cin >> input;

  while (input >= BOARD_WIDTH|| std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    fmt::print("Invalid input. Please enter a number between 0 and 6: ");
    std::cin >> input;
  }

  fmt::print("Input accepted: {:x}\n", input);
  return input;
}