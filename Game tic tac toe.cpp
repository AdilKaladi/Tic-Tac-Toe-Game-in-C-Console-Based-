#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'} };

char currentPlayer = 'X';

void drawBoard() {
    system("cls");  
    cout << "\n===== TIC TAC TOE =====\n\n";
    cout << "Player 1 (X)   |   Player 2 (O)\n\n";

    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "     |     |     \n\n";
}

bool placeMark(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

bool checkWin() {
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;

    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void resetBoard() {
    char count = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = count++;
}

int main() {
    int slot;
    char choice;

    do {
        resetBoard();
        currentPlayer = 'X';

        while (true) {
            drawBoard();
            cout << "Player " << currentPlayer << ", enter slot number (1-9): ";
            cin >> slot;

            if (slot < 1 || slot > 9) {
                cout << "Invalid input! Try again.\n";
                continue;
            }

            if (!placeMark(slot)) {
                cout << "Slot already taken! Try again.\n";
                continue;
            }

            if (checkWin()) {
                drawBoard();
                cout << "?? Player " << currentPlayer << " WINS!\n";
                break;
            }

            if (checkDraw()) {
                drawBoard();
                cout << "It's a DRAW!\n";
                break;
            }

            switchPlayer();
        }

        cout << "Play again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nThanks for playing!\n";
    return 0;
}
