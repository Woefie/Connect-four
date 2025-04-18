#include <algorithm>
#include <string_view>
#include "board.h"

#include <fmt/color.h>
#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ranges.h>

#ifdef _WIN32
constexpr std::string_view CLEAR {"cls"};
#else
constexpr std::string_view CLEAR {"clear"};
#endif

auto Board::set_puck(std::pair<uint8_t, uint8_t>& point, uint8_t player) ->bool
{
  point.first = 0;  // Always start at the bottom

  // Check if column is not out of bounds and if player is ont greater then 2
  if (point.second >= BOARD_WIDTH || player > 2) {
    return false;
  }

  // Check if position !=0 this means that it is a valid placeable spot
  // if not valid add 1 to row 
  while (m_board.at(point.first).at(point.second) != 0) {
    point.first++;
    if (point.first >= BOARD_HEIGHT) {
      return false;
    }
  }

  // Set puck
  m_board.at(point.first).at(point.second) = player;
  m_last_player = player;
  return true;
}

auto Board::is_full() -> bool
{
// Scan every element(puck) of the board. If all not 0 then its full
  for (const auto& row : m_board) {
    for (const auto& elem : row) {
      if (elem == 0) {
        return false;
      }
    }
  }
  return true;
}

auto Board::check_for_win(std::pair<uint8_t, uint8_t> point) -> bool
{
  // Check all directions for the current stone
  for (int dr = -1; dr <= 1; dr++) {  // dr = delta row
    for (int dc = -1; dc <= 1; dc++) {  // dc = delta column
      // skip the current cell and continue to the next iteration
      if (dr == 0 && dc == 0) {
        continue;
      }

      // check connected stones on the left side direction
      int connected = 0;
      for (int i = -1; i >= -3; i--) {
        int r = point.first + (i * dr);
        int c = point.second + (i * dc);

        // check if we don't run out of bounds first
        if (r < 0 || r >= BOARD_HEIGHT || c < 0 || c >= BOARD_WIDTH) {
          break;
        }

        if (m_board.at(r).at(c) == m_last_player) {
          ++connected;
        } else {
          break;
        }
      }

      // now check only necessary remaining values on the right side
      for (int i = 1; i <= 3; i++) {
        int r = point.first + (i * dr);
        int c = point.second + (i * dc);

        // check if we don't run out of bounds first
        if (r < 0 || r >= BOARD_HEIGHT || c < 0 || c >= BOARD_WIDTH) {
          break;
        }

        if (m_board.at(r).at(c) == m_last_player) {
          ++connected;
        } else {
          break;
        }
      }

      // check if the player got 3 connected stones in a row (4 in total)
      if (connected == 3) {
        return true;
      } 
    }
  }

  return false;
}

void Board::print_board()
{
  // clear board
  system(CLEAR.data());
  
  fmt::print("\n╔{:═>{}}╗\n", "", BOARD_WIDTH);

  // Loop over each element of the board
  // Reverse loop so 0,0 is at the bottom
  std::for_each(m_board.rbegin(),
                m_board.rend(),
                [this](auto& row)
                {
                  fmt::print("║");
                  for (const auto& elem : row) {
                    if (elem == 1) {  //print player 1
                      fmt::print(fg(fmt::color::red), "@");
                    } else if (elem == 2) {  //print player 2
                      fmt::print(fg(fmt::color::yellow), "0");

                    } else {  // if point is empty print -
                      fmt::print("-");
                    }
                  }
                  fmt::print("║\n");
                });

  fmt::print("╚{:═>{}}╝\n", "", BOARD_WIDTH);
  fmt::print(" 1234567 \n");
}

