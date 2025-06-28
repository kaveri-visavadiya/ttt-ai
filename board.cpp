#include "board.h"
#include <iostream>
using namespace std;

char (*create_board())[SIZE] {
    static char board[SIZE][SIZE] = {{' ', ' ', ' '},
                               {' ', ' ', ' '},
                               {' ', ' ', ' '}};
    return board;
}

void print_board(const char board[SIZE][SIZE]) {
    cout << "   0 1 2 \n";
    cout << "  -------\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << i;
        for (int j = 0; j < SIZE; ++j) {
            if (j == 0) 
                cout << " |";
            if (board[i][j] == 'X') {
                cout << "\033[31m" << board[i][j] << "\033[0m|"; // Red for 'X'
            } else if (board[i][j] == 'O') {
                cout << "\033[32m" << board[i][j] << "\033[0m|"; // Green for 'O'
            } else {
                cout << board[i][j] << '|'; // Default color for empty
            }
        }
        cout << '\n';
        cout << "  -------\n";
    }
}

int is_move_valid(const char board[SIZE][SIZE], const array<int, 2> move) {
    if (move[0] < 0 || move[0] > 2 || move[1] < 0 || move[1] > 2 || board[move[0]][move[1]] != ' ')
        return 0;
    return 1;
}

int is_board_full(const char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}
