#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() {
        // Initialize an empty board
        board = {{' ', ' ', ' '},
                 {' ', ' ', ' '},
                 {' ', ' ', ' '}};
        currentPlayer = 'X';
    }

    // Display the board
    void displayBoard() {
        cout << "Player X = X  Player O = O\n\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << endl;
            if (i < 2) cout << "---------" << endl;
        }
    }

    // Check if the current player has won
    bool checkWin() {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }

        // Check diagonals
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;

        return false;
    }

    // Check if the board is full (i.e., a tie)
    bool checkTie() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == ' ')
                    return false;
        return true;
    }

    // Make a move
    bool makeMove(int row, int col) {
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            return false;  // Invalid move
        }
        board[row][col] = currentPlayer;
        return true;
    }

    // Switch player
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Start the game
    void startGame() {
        int row, col;
        while (true) {
            displayBoard();
            cout << "Player " << currentPlayer << "'s turn. Enter row (0-2) and column (0-2): ";
            cin >> row >> col;

            if (makeMove(row, col)) {
                if (checkWin()) {
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    break;
                }
                if (checkTie()) {
                    displayBoard();
                    cout << "It's a tie!" << endl;
                    break;
                }
                switchPlayer();  // Switch to the other player
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }
    }
};

int main() {
    TicTacToe game;
    game.startGame();
    return 0;
}

