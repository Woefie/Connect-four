#pragma once

#include <memory>

#include "board.h"
#include "computer.h"
#include "player.h"

constexpr uint8_t PLAYERCOUNT {2};

/**
 * Game class this contains the startup of connect four by asking how many players should play 
 * After this the game will loop until the game reaches a end
*/
class Game
{
public:
  Game() = default;
  // Delete copy and move constructors
  Game(const Game& other) = delete;
  Game(Game&& other) = delete;
  Game& operator=(const Game& other) = delete;
  Game& operator=(Game&& other) = delete;

  /**
   * Begin connect four game
   * Ask user how many player will be playing
   * And initialized said players
  */
  void Begin();

private:
/**
 * Game loop
 * Ask user for input
 * Check if the puck can be placed in said position
 * Check if the last puck was winning
*/
  void Loop();

  Board board;
  uint8_t state {0};
  std::array<std::unique_ptr<IUser>, PLAYERCOUNT> players;
};