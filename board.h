#ifndef BOARD_H
#define BOARD_H
#include <array>
using namespace std;

#define SIZE 3

char (*create_board())[SIZE];
void print_board(const char board[SIZE][SIZE]);
int is_move_valid(const char board[SIZE][SIZE], const array<int, 2> move);
int is_board_full(const char board[SIZE][SIZE]);

#endif