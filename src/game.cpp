

#include <chrono>
#include <iostream>
#include <thread>

#include "game.h"

#include <fmt/color.h>
#include <fmt/core.h>


void Game::Begin()
{
  // Ask the user how many players will play max 2
  uint32_t input {0};
  fmt::print("Enter the number of players 0 and 2: ");
  std::cin >> input;

   while (input > 2|| std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    fmt::print("Invalid input. Please enter a number between 0 and 2: ");
    std::cin >> input;
  }

  // Make the correct users.

  switch (input) {
    case 0:
      players.at(0) = std::make_unique<Computer>(1);
      players.at(1) = std::make_unique<Computer>(2);
      fmt::print("The two computers will battle to the death!!!!");
      break;
    case 1:
      players.at(0) = std::make_unique<Player>(1);
      players.at(1) = std::make_unique<Computer>(2);
      fmt::print("You are player 1 in red : {} \n", fmt::styled("@", fmt::fg(fmt::color::red)));
      break;
    case 2:
      players.at(0) = std::make_unique<Player>(1);
      players.at(1) = std::make_unique<Player>(2);
      fmt::print("Player 1 in red : {} \n", fmt::styled("@", fmt::fg(fmt::color::red)));
      fmt::print("Player 2 in yellow : {} \n", fmt::styled("0", fmt::fg(fmt::color::yellow)));
      break;
    default:
      players.at(0) = std::make_unique<Player>(1);
      players.at(1) = std::make_unique<Computer>(2);
      fmt::print("You are player 1 in red : {} \n", fmt::styled("@", fmt::fg(fmt::color::red)));
      break;
  }

  Loop();
}

void Game::Loop()
{
  board.PrintBoard();

  // Continue until board is full
  while (!board.IsFull()) {
    std::pair<uint8_t, uint8_t> point;
    bool valid {false};

    // Ask player or computer for a column number
    // Put puck in the board if it is a valid placement
    while (!valid) {
      point.second = static_cast<uint8_t>(players.at(state)->GetPlacement());
      valid = board.SetPuck(point, players.at(state)->GetNumber());
    }

    // Check the latest puck placement if it was winning
    // Return if player won
    if (board.CheckForWin(point)) {
      board.PrintBoard();
      fmt::print("Player {} Won !!!\n", players.at(state)->GetNumber());
      return;
    }

    // Switch between players
    if (state == 0) {
      state = 1;
    } else {
      state = 0;
    }

    board.PrintBoard();

    // I put this sleep here so you see the board animated when you have 2
    // computers play each other
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
  board.PrintBoard();
  fmt::print("It is a draw!!!\n");
}