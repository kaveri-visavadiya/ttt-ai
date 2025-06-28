#ifndef AI_H
#define AI_H
#include <array>
#include <vector>
using namespace std;

#define SIZE 3

array<int, 2> random_ai(const char board[SIZE][SIZE], const char player);

vector<vector<array<int, 2>>> get_all_lines_on_board(const char board[SIZE][SIZE]);
array<int, 2> find_winning_move_ai(const char board[3][3], const char player);

char get_opponent(const char player);
array<int, 2> find_winning_move_ai_for_block(const char board[SIZE][SIZE], const char player);
array<int, 2> find_winning_and_blocks_losing_moves_ai(const char board[SIZE][SIZE], const char player);

array<int, 2> human_player(const char board[SIZE][SIZE]);

void make_move(const char board[SIZE][SIZE], array<int, 2> move, char player, char new_board[SIZE][SIZE]);
char get_winner(const char board[SIZE][SIZE]);
vector<array<int, 2>> get_all_legal_moves(const char board[SIZE][SIZE]);
int minimax_score(const char board[SIZE][SIZE], char player_to_move, char player_to_optimize);
array<int, 2> minimax_ai(const char board[SIZE][SIZE], char player);

#endif 