#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(char board[3][3]) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Function to check if the current player has won
bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the board is full (tie)
bool checkTie(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; // There's still an empty cell
            }
        }
    }
    return true; // Board is full
}

// Function to get user's move
void getUserMove(char board[3][3]) {
    int row, col;
    do {
        cout << "Enter row and column numbers (1-3) for your move: ";
        cin >> row >> col;
        // Adjust to 0-based indexing
        row--;
        col--;
    } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ');
    board[row][col] = 'X';
}

// Function to get AI's move
void getAIMove(char board[3][3]) {
    cout << "AI is making a move..." << endl;
    // Simple AI: Randomly choose an empty cell
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');
    board[row][col] = 'O';
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    bool playerTurn = true; // true for player X, false for player O

    srand(time(0)); // Seed for random number generator

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (true) {
        printBoard(board);

        if (playerTurn) {
            getUserMove(board);
        } else {
            getAIMove(board);
        }

        if (checkWin(board, playerTurn ? 'X' : 'O')) {
            printBoard(board);
            cout << (playerTurn ? "Player X" : "Player O") << " wins!" << endl;
            break;
        } else if (checkTie(board)) {
            printBoard(board);
            cout << "It's a tie!" << endl;
            break;
        }

        playerTurn = !playerTurn; // Switch turns
    }

    return 0;
}
