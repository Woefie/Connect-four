#include "player.h"
#include <iostream>
#include <fmt/printf.h>

Player::Player(uint8_t number)
    : IUser(number)
{
}

const uint32_t Player::GetPlacement()
{
  uint32_t input {0};
  fmt::print("Enter a number between 0 and 6: ") ;
  std::cin >> input;

  while (input >= BOARD_WIDTH) {
    fmt::print("Invalid input. Please enter a number between 0 and 6: ");
    std::cin >> input;
  }

  fmt::print("Input accepted: {}", input);
  return input;
}