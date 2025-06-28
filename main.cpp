#include "board.h"
#include "ai.h"
#include "ai_selector.h"
#include <iostream>

using namespace std;

int main() {
    system("cls");
    srand(time(0));

    char players[2] = {'X', 'O'};;
    char (*board)[SIZE] = create_board();
    char winner;
    string option1, option2;
    array<int, 2> move;
    int i = 0;

    cout << '\n';
    cout << "\x1b[1;34;47m                                                                        \x1b[0m\n";
    cout << "\x1b[1;34;47m                          WELCOME TO TIC-TAC-TOE!                       \x1b[0m\n";
    cout << "\x1b[1;34;47m                                                                        \x1b[0m\n";
    cout << '\n';
    cout << "   Random AI (r)\n";
    cout << "   Finds winning moves AI (fw)\n";
    cout << "   Finds winning moves and blocks opponents winning moves AI (fwb)\n";
    cout << "   Minimax AI (mm)\n";
    cout << "   Human player (human)\n";
    cout << "First input represents X & second input represents O.\n";
    cout << "Enter the names of the two AIs you want to face off, or an AI you want to play against: ";

    while (1) {
        cin >> option1 >> option2; // option 1 represents X, option 2 represents O
        if (option1 != "r" && option1 != "fw" && option1 != "fwb" && option1 != "human" && option1 != "mm" &&
            option2 != "r" && option2 != "fw" && option2 != "fwb" && option2 != "human" && option2 != "mm") {
                cout << "Incorrect input! Type input again.\n";
        } else break;
    }

    array<string, 2> options {option1, option2};
    cout << '\n';
    print_board(board);
    cout << '\n';

    while (!is_board_full(board)) {
        char player = players[i % 2]; // player = X when i = 0, O when i = 1
        string option = options[i % 2];

        move = get_move(board, player, option);
        make_move(board, move, player, board); 
        print_board(board);
        cout << '\n';
        winner = get_winner(board);
        
        if (winner == 'X') {
            cout << "The winner is " << option1 << " (" << winner << ")!\n";
            break;
        }
        else if (winner == 'O') {
            cout << "The winner is " << option2 << " (" << winner << ")!\n";
            break;
        }
        ++i;
    }
    if (is_board_full(board) && winner == ' ') cout << "Draw!\n";

    return 0;
}