#pragma once

#include <memory>

#include "board.h"
#include "computer.h"
#include "player.h"

constexpr uint8_t PLAYERCOUNT {2};
class Game
{
public:
  Game() = default;
  // Delete copy and move constructors
  Game(const Game& other) = delete;
  Game(Game&& other) = delete;
  Game& operator=(const Game& other) = delete;
  Game& operator=(Game&& other) = delete;

  void Begin();

private:
  void Loop();
  uint8_t state {0};

  std::array<std::unique_ptr<IUser>, PLAYERCOUNT> players;

  Board board;
};