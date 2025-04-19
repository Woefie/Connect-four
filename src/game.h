#pragma once

#include <memory>

#include "board.h"
#include "computer.h"
#include "player.h"
#include "human_player.h"

constexpr uint8_t PLAYERCOUNT {2};

/**
 * Game class this contains the startup of connect four by asking how many players should play 
 * After this the game will loop until the game reaches a end
*/
class Game
{
public:
  Game() = default;
  ~Game() =default;
  explicit Game(std::array<std::unique_ptr<Player>, PLAYERCOUNT> m_players)
      : m_players(std::move(m_players))
  {
  }
  // Delete copy and move constructors
  Game(const Game& other) = delete;
  Game(Game&& other) = delete;
  auto operator=(const Game& other) -> Game& = delete;
  auto operator=(Game&& other) -> Game& = delete;

  /**
   * Begin connect four game
   * Ask user how many player will be playing
   * And initialized said players
  */
  void begin();

private:
/**
 * Game loop
 * Ask user for input
 * Check if the puck can be placed in said position
 * Check if the last puck was winning
*/
  void loop();

  Board m_board;
  uint8_t m_state {0};
  std::array<std::unique_ptr<Player>, PLAYERCOUNT> m_players;
};