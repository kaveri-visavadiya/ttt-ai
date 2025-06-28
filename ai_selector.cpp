#include "board.h"
#include "ai.h"
#include <iostream>

using namespace std;

array<int, 2> get_move(const char board[SIZE][SIZE], char player, string option) {
    static array<int, 2> move;

    if (player == 'X') {
        if (option == "r") {
            cout << "Random AI's turn\n";
            move = random_ai(board, player);
        }
        else if (option == "fw") {
            cout << "Finds winning moves AI's turn\n";
            move = find_winning_move_ai(board, player);
        }
        else if (option == "fwb") {
            cout << "Finds winning moves and blocks opponents winning moves AI's turn\n";
            move = find_winning_and_blocks_losing_moves_ai(board, player);
        }
        else if (option == "mm") {
            cout << "Minimax AI's turn\n";
            move = minimax_ai(board, player);
        }
        else if (option == "human") {
            cout << "YOUR TURN\n";
            move = human_player(board);
        }
    }

    if (player == 'O') {
        if (option == "r") {
            cout << "Random AI's turn\n";
            move = random_ai(board, player);
        }
        else if (option == "fw") {
            cout << "Finds winning moves AI's turn\n";
            move = find_winning_move_ai(board, player);
        }
        else if (option == "fwb") {
            cout << "Finds winning moves and blocks opponents winning moves AI's turn\n";
            move = find_winning_and_blocks_losing_moves_ai(board, player);
        }
        else if (option == "mm") {
            cout << "Minimax AI's turn\n";
            move = minimax_ai(board, player);
        } 
        else if (option == "human") {
            cout << "YOUR TURN\n";
            move = human_player(board);
        }
    }
    return move;
}