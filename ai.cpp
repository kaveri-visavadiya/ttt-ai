#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
#include "board.h"
using namespace std;

#define SIZE 3

array<int, 2> random_ai(const char board[SIZE][SIZE], const char player) {
    static array<int, 2> move;
    vector<array<int, 2>> possible_moves;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') possible_moves.push_back({i, j});
        }
    }
    
    if (possible_moves.empty()) {
        return {-1, -1};
    }

    int random_index = rand() % possible_moves.size();
    move = possible_moves[random_index];

    return move;
}

vector<vector<array<int, 2>>> get_all_lines_on_board(const char board[SIZE][SIZE]) {
    static vector<vector<array<int, 2>>> all_lines;

    for (int i = 0; i < SIZE; ++i) {
        vector<array<int, 2>> row;
        for (int j = 0; j < SIZE; ++j) {
            row.push_back({i, j});
        }
        all_lines.push_back(row);
    }
    for (int i = 0; i < SIZE; ++i) {
        vector<array<int, 2>> col;
        for (int j = 0; j < SIZE; ++j) {
            col.push_back({j, i});
        }
        all_lines.push_back(col);
    }
    vector<vector<array<int, 2>>> diagonals = {{{0, 0}, {1, 1}, {2, 2}}, {{0, 2}, {1, 1}, {2, 0}}};
    for (vector<array<int, 2>> d : diagonals) {
        all_lines.push_back(d);
    }

    return all_lines;
}

array<int, 2> find_winning_move_ai(const char board[SIZE][SIZE], const char player) {
    static array<int, 2> move; 
    vector<vector<array<int, 2>>> all_lines = get_all_lines_on_board(board);

    // for each 2d vec line, count whether there is 2 self(player) + 1 blank in this line
    // if so then return the blank coord as winning move. else return random move
    for (vector<array<int, 2>> line : all_lines) { // for each 2d line
        int n_self = 0;
        int n_other = 0;
        int n_blank = 0;
        array<int, 2> last_blank_coord; 
        
        for (array<int, 2> coord : line) {  // for each 1d vec coordinate within line, count
            char x_or_o_or_blank = board[coord[0]][coord[1]];
            if (x_or_o_or_blank == player) ++n_self;
            else if (x_or_o_or_blank == ' ') {
                ++n_blank;
                last_blank_coord = coord;
            }
            else ++n_other;
        }
        if (n_self == 2 && n_blank == 1) { // return winning move if it is there
            move[0] = last_blank_coord[0];
            move[1] = last_blank_coord[1];
            return move;
        } 
    }
    move = random_ai(board, player); // o/w return random move
    return move;
}

char get_opponent(const char player) {
    if (player == 'O') return 'X';
    else return 'O';
}

array<int, 2> find_winning_move_ai_for_block(const char board[SIZE][SIZE], const char player) {
    static array<int, 2> move; 
    vector<vector<array<int, 2>>> all_lines = get_all_lines_on_board(board);

    for (vector<array<int, 2>> line : all_lines) { 
        int n_self = 0;
        int n_other = 0;
        int n_blank = 0;
        array<int, 2> last_blank_coord; 
        
        for (array<int, 2> coord : line) {  
            char x_or_o_or_blank = board[coord[0]][coord[1]];
            if (x_or_o_or_blank == player) ++n_self;
            else if (x_or_o_or_blank == ' ') {
                ++n_blank;
                last_blank_coord = coord;
            }
            else ++n_other;
        }
        if (n_self == 2 && n_blank == 1) { 
            move[0] = last_blank_coord[0];
            move[1] = last_blank_coord[1];
            return move;
        } 
    }
    move.fill(-1);
    return move;
}

array<int, 2> find_winning_and_blocks_losing_moves_ai(const char board[SIZE][SIZE], const char player) {
    static array<int, 2> move; 
    
    // first priority: return winning move for player
    move = find_winning_move_ai_for_block(board, player);
    if (move != array<int, 2> {-1, -1}) return move;

    // second priority: return blocking move of opp player
    char player_opponent = get_opponent(player); 
    move = find_winning_move_ai(board, player_opponent);
    if (move != array<int, 2> {-1, -1}) return move;

    // third: return random move
    move = random_ai(board, player);
    return move; 
}

array<int, 2> human_player(const char board[SIZE][SIZE]) {
    static array<int, 2> move;

    while (1) {
        cout << "What is your move's X co-ordinate?: ";
        cin >> move[0];
        cout << "What is your move's Y co-ordinate?: ";
        cin >> move[1];

        if (!is_move_valid(board, move)){
            cout << "Invalid co-ordinates! Try again.\n";
        } else break;
    }

    return move;
}

void make_move(const char board[SIZE][SIZE], array<int, 2> move, char player, char new_board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            new_board[i][j] = board[i][j];
        }
    }
    new_board[move[0]][move[1]] = player;
}

char get_winner(const char board[SIZE][SIZE]) {
    // for each row
    for (int i = 0; i < SIZE; ++i) {
        int count = 0;
        for (int j = 0; j < SIZE-1; ++j) {
            if (board[i][j] != ' ') {
                if (board[i][j] == board[i][j+1]) ++count;
            }
        }
        if (count == SIZE-1) return board[i][0];
    }

    // for each column
    for (int i = 0; i < SIZE; ++i) {
        int count = 0;
        for (int j = 0; j < SIZE-1; ++j) {
            if (board[j][i] != ' ') {
                if (board[j][i] == board[j+1][i]) ++count;
            }
        }
        if (count == SIZE-1) return board[0][i];
    }

    // for each diag
    int count = 0;
    for (int i = 0; i < SIZE-1; ++i) {
        if (board[i][i] == board[i+1][i+1]) count += 1;
    }
    if (count == SIZE-1) return board[0][0];

    count = 0;
    for (int i = 0; i < SIZE-1; ++i) {
        if (board[i][2-i] == board[i+1][1-i]) count += 1;
    }
    if (count == SIZE-1) return board[0][2];

    return ' ';
}

vector<array<int, 2>> get_all_legal_moves(const char board[SIZE][SIZE]) {
    vector<array<int, 2>> legal_moves;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') legal_moves.push_back({i, j});
        }
    }
    return legal_moves;
}

int minimax_score(const char board[SIZE][SIZE], char player_to_move, char player_to_optimize) {
    char winner = get_winner(board); // base case
    if (winner != ' ') {
        if (winner == player_to_optimize) return 10;
        else return -10;
    }
    if (is_board_full(board)) return 0;

    vector<int> scores;
    for (array<int, 2> move : get_all_legal_moves(board)) {
        char new_board[SIZE][SIZE];  
        make_move(board, move, player_to_move, new_board);
        int score = minimax_score(new_board, get_opponent(player_to_move), player_to_optimize);
        scores.push_back(score);
    }

    if (player_to_move == player_to_optimize) {
        return *max_element(scores.begin(), scores.end()); // maximizing player
    } else {
        return *min_element(scores.begin(), scores.end()); // ninimizing player
    }
}

array<int, 2> minimax_ai(const char board[SIZE][SIZE], char player) {
    array<int, 2> best_move;
    int best_score = -100000;

    for (array<int, 2> move : get_all_legal_moves(board)) {
        char new_board[SIZE][SIZE];  
        make_move(board, move, player, new_board);
        
        int score = minimax_score(new_board, get_opponent(player), player);
        if (score > best_score) {
            best_score = score;
            best_move = move;
        }
    }
    return best_move;
}
