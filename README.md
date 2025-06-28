# Implementation of Tic-Tac-Toe in C++

There are 3 header files: board.h, ai.h and ai.selector.h. 

board.h contains board manipulation functions (create, print, check validity).

ai.h contains 4 AI functions and some utilities. The 4 AI functions are random_ai, find_winning_move_ai, find_winning_and_blocks_losing_moves_ai and minimax_ai. 
random_ai returns a random valid move. find_winning_move_ai returns a terminal winning move (when there are two X's or O's in a row, column or diagonal) else a random move. find_winning_and_blocks_losing_moves_ai builds on find_winning_move by returning a move that blocks the opponent's terminal/winning move. minimax_ai is a perfect AI and its game can never end in its loss, only in its win or a draw. It uses the Minimax algorithm.

ai_selector.h contains an interface that allows a human player to play against another human, against any of the above 4 AIs, or face off two AIs against each other to compare their performance. Undoubtedly the order of strength in gameplay is as follows: random_ai < find_winning_move_ai < find_winning_and_blocks_losing_moves_ai < minimax_ai.

To compile the header files with the main file, you can type on the command line as follows: "g++ main.cpp board.cpp ai_selector.cpp ai.cpp -o main" to get a main.exe application that you can then run.

![image](https://github.com/user-attachments/assets/ae3b128f-fea3-435a-9467-3476cfd72947)

[Reference](https://robertheaton.com/2018/10/09/programming-projects-for-advanced-beginners-3-a/)
