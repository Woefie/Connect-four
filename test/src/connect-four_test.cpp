#include <catch2/catch_test_macros.hpp>

#include "board.h"

TEST_CASE("set_puck input validation", "[board]")
{
  Board board;

  SECTION("Column 0 is valid (regression for the old '<= 0' bug)")
  {
    REQUIRE(board.set_puck(0, 1));
  }
  SECTION("Last column is valid")
  {
    REQUIRE(board.set_puck(BOARD_WIDTH - 1, 1));
  }
  SECTION("Column == BOARD_WIDTH is rejected")
  {
    REQUIRE_FALSE(board.set_puck(BOARD_WIDTH, 1));
  }
  SECTION("Player 0 is rejected")
  {
    REQUIRE_FALSE(board.set_puck(0, 0));
  }
  SECTION("Player above 2 is rejected")
  {
    REQUIRE_FALSE(board.set_puck(0, 3));
  }
}

TEST_CASE("set_puck stacks then reports a full column", "[board]")
{
  Board board;
  for (uint8_t i = 0; i < BOARD_HEIGHT; ++i) {
    INFO("drop #" << (int)i);
    CHECK(board.set_puck(2, 1));  // BOARD_HEIGHT drops all fit
  }
  CHECK_FALSE(board.set_puck(2, 1));  // one more must fail
}

TEST_CASE("set_puck can fill the whole board", "[board]")
{
  Board board;
  REQUIRE_FALSE(board.is_full());

  for (uint8_t col = 0; col < BOARD_WIDTH; ++col) {
    for (uint8_t i = 0; i < BOARD_HEIGHT; ++i) {
      CHECK(board.set_puck(col, 1));
    }
  }

  CHECK(board.is_full());
}