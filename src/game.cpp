#include <iostream>
#include <thread>

#include "game.h"

#include <fmt/color.h>
#include <fmt/core.h>

void Game::begin()
{
  // Ask the user how many players will play max 2
  uint32_t input {0};
  fmt::print("Enter the number of players 0 and 2: ");
  std::cin >> input;

  while (input > 2 || std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    fmt::print("Invalid input. Please enter a number between 0 and 2: ");
    std::cin >> input;
  }

  // Make the correct users.

  switch (input) {
    case 0:
      m_players.at(0) = std::make_unique<Computer>(1);
      m_players.at(1) = std::make_unique<Computer>(2);
      fmt::print("The two computers will battle to the death!!!!");
      break;
    case 1:
      m_players.at(0) = std::make_unique<HumanPlayer>(1);
      m_players.at(1) = std::make_unique<Computer>(2);
      fmt::print("You are player 1 in red : {} \n", fmt::styled("@", fmt::fg(fmt::color::red)));
      break;
    case 2:
      m_players.at(0) = std::make_unique<HumanPlayer>(1);
      m_players.at(1) = std::make_unique<HumanPlayer>(2);
      fmt::print("HumanPlayer 1 in red : {} \n", fmt::styled("@", fmt::fg(fmt::color::red)));
      fmt::print("HumanPlayer 2 in yellow : {} \n", fmt::styled("0", fmt::fg(fmt::color::yellow)));
      break;
    default:
      m_players.at(0) = std::make_unique<HumanPlayer>(1);
      m_players.at(1) = std::make_unique<Computer>(2);
      fmt::print("You are player 1 in red : {} \n", fmt::styled("@", fmt::fg(fmt::color::red)));
      break;
  }

  loop();
}

void Game::loop()
{
  m_board.print_board();

  // Continue until board is full
  while (!m_board.is_full()) {
    std::pair<uint8_t, uint8_t> point;
    bool valid {false};

    // Ask player or computer for a column number
    // Put puck in the board if it is a valid placement
    while (!valid) {
      point.second = static_cast<uint8_t>(m_players.at(m_state)->get_placement());
      valid = m_board.set_puck(point, m_players.at(m_state)->get_number());
    }

    // Check the latest puck placement if it was winning
    // Return if player won
    if (m_board.check_for_win(point)) {
      m_board.print_board();
      fmt::print("HumanPlayer {} Won !!!\n", m_players.at(m_state)->get_number());
      return;
    }

    // Switch between players
    if (m_state == 0) {
      m_state = 1;
    } else {
      m_state = 0;
    }

    m_board.print_board();

    // I put this sleep here so you see the board animated when you have 2
    // computers play each other
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
  m_board.print_board();
  fmt::print("It is a draw!!!\n");
}