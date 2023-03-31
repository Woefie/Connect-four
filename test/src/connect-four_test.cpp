#include <catch2/catch_test_macros.hpp>

#include "board.h"

TEST_CASE("Connect-four board tests", "[library]")
{
  Board board;
  SECTION("Test Input")
  {
    std::pair<uint8_t, uint8_t> point {0, 8};
    REQUIRE_FALSE(board.SetPuck(point, 2));
    point.second = -2;
    REQUIRE_FALSE(board.SetPuck(point, 2));
    point.second = 0;
    REQUIRE(board.SetPuck(point, 2));
  }
  SECTION("Test player number")
  {
    std::pair<uint8_t, uint8_t> point {0, 0};
    REQUIRE_FALSE(board.SetPuck(point, 3));
    REQUIRE_FALSE(board.SetPuck(point, -1));
    REQUIRE(board.SetPuck(point, 2));
  }

  SECTION("Test board fullness")
  {
    REQUIRE_FALSE(board.IsFull());
    for (size_t i = 0; i < 6; i++) {
      for (size_t j = 0; j < 7; j++) {
        std::pair<uint8_t, uint8_t> point {i, j};
        board.SetPuck(point, 1);
      }
    }
    REQUIRE(board.IsFull());
  }
}
