#ifndef AI_SELECTOR_H
#define AI_SELECTOR_H
#include <array>
#include <vector>
#include <string>
#include "ai.h"
#include "board.h"
using namespace std;

#define SIZE 3

array<int, 2> get_move(const char board[SIZE][SIZE], char player, string option);

#endif