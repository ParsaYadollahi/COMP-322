#include <iostream>
#include <cstdlib>
using namespace std;

void greetAndInstruct();
void displayBoard(char board[]);
void board_status(char board[], int index);
bool checkIfLegal(int cellNbre, char board[]);
bool checkWinner(char board[]);
void computerMove(char board[]);

void greetAndInstruct() // Question 1
{
    cout << " " << endl;
    cout << "Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer." << endl;
    cout << " " << endl;
    cout << "The board is numbered from 1 to 27 as per the following:" << endl;
    cout << " " << endl;
    cout << "1 | 2 | 3    10 | 11 | 12    19 | 20 | 21" << endl;
    cout << "----------   -------------   ------------ " << endl;
    cout << "4 | 5 | 6    13 | 14 | 15    22 | 23 | 24" << endl;
    cout << "----------   -------------   ------------ " << endl;
    cout << "7 | 8 | 9    16 | 17 | 18    25 | 26 | 27" << endl;
    cout << " " << endl;
    cout << "Player starts first. Simply input the number of the cell you want to occupy. Player’s move" << endl;
    cout << "is marked with X. Computer’s move is marked with O." << endl;
    cout << " " << endl;
    cout << "Start? (y/n): ";
    string y_n;
    cin >> y_n;

    if (y_n == "y")
        return;
    else
        exit(0);
}

void displayBoard(char board[])
{
    // Row 1 - x
    cout << endl;
    board_status(board, 1), cout << " | ", board_status(board, 2), cout << " | ", board_status(board, 3), cout << "    ";
    board_status(board, 10), cout << " | ", board_status(board, 11), cout << " | ", board_status(board, 12), cout << "    ";
    board_status(board, 19), cout << " | ", board_status(board, 20), cout << " | ", board_status(board, 21), cout << "     " << endl;

    cout << "----------   ------------    ------------", cout << endl;

    board_status(board, 4), cout << " | ", board_status(board, 5), cout << " | ", board_status(board, 6), cout << "    ";
    board_status(board, 13), cout << " | ", board_status(board, 14), cout << " | ", board_status(board, 15), cout << "    ";
    board_status(board, 22), cout << " | ", board_status(board, 23), cout << " | ", board_status(board, 24), cout << "     " << endl;

    cout << "----------   ------------    ------------", cout << endl;

    board_status(board, 7), cout << " | ", board_status(board, 8), cout << " | ", board_status(board, 9), cout << "    ";
    board_status(board, 16), cout << " | ", board_status(board, 17), cout << " | ", board_status(board, 18), cout << "    ";
    board_status(board, 25), cout << " | ", board_status(board, 26), cout << " | ", board_status(board, 27), cout << "      " << endl;
    cout << endl;
    return;
}

void board_status(char board[], int index)
{
    if (board[index] != 'X' && board[index] != 'O')
    {
        cout << index;
    }
    else if (board[index] == 'X')
    {
        cout << 'X';
    }
    else if (board[index] == 'O')
    {
        cout << 'O';
    }
}

bool checkIfLegal(int cellNbre, char board[])
{
    // Out of bounds
    if (cellNbre < 1 || cellNbre > 27)
    {
        return false;
    }
    // If trying to put x and o in same square
    if (board[cellNbre] != 'X' && board[cellNbre] != 'O')
    {
        return true;
    }
    else
        return false;
    return true;
}

bool checkWinner(char board[])
{

    ////////////////////////////////////
    //              TIE               //
    ////////////////////////////////////
    bool tie = true;
    // check if board emptys
    for (int i = 1; i < 28; i++)
    {
        // early break to check if there's an empty cell
        if (board[i] != 'X' || board[i] != 'O')
        {
            tie = false;
            break;
        }
    }

    if (tie)
    {
        cout << "Tie" << endl;
        exit(0);
    }

    // check winner for player
    for (int i = 1; i < 28; i++)
    {
        ////////////////////////////////////
        //           1 - PLAYER           //
        ////////////////////////////////////

        //////////////////////////////////
        //           1 BOARD            //
        //////////////////////////////////
        // check row 1 board
        if ((i - 1) % 3 == 0 &&
            board[i] == 'X' &&
            board[i + 1] == 'X' &&
            board[i + 2] == 'X')
        {
            return true;
        }
        // check cols 1 board
        if ((i == 1 || i == 2 || i == 3 || i == 10 || i == 11 || i == 12 || i == 19 || i == 20 || i == 21) &&
            board[i] == 'X' &&
            board[i + 3] == 'X' &&
            board[i + 6] == 'X')
        {
            return true;
        }
        //////////////////////////////////
        //           DIAG 1 BOARD       //
        //////////////////////////////////
        // check diag 1 board
        if ((i == 1 || i == 10 || i == 19) &&
            board[i] == 'X' &&
            board[i + 4] == 'X' &&
            board[i + 8] == 'X')
        {
            return true;
        }

        // check diag 1 board
        if ((i == 3 || i == 12 || i == 21) &&
            board[i] == 'X' &&
            board[i + 2] == 'X' &&
            board[i + 4] == 'X')
        {
            return true;
        }

        //////////////////////////////////
        //           3 BOARD            //
        //////////////////////////////////
        // check row 3 boards
        if (board[i] == 'X' &&
            board[i + 9] == 'X' &&
            board[i + 18] == 'X')
        {
            return true;
        }
        // check rows 3 boards
        if ((i == 2 || i == 5 || i == 8) &&
            board[i] == 'X' &&
            board[i + 10] == 'X' &&
            board[i + 20] == 'X')
        {
            return true;
        }
        // check cols 3 boards
        if ((i == 1 || i == 2 || i == 3) &&
            board[i] == 'X' &&
            board[i + 12] == 'X' &&
            board[i + 24] == 'X')
        {
            return true;
        }

        //////////////////////////////////
        //         DIAG 3 BOARD         //
        //////////////////////////////////
        // check diag 3 boards
        if (board[1] == 'X' &&
            board[13] == 'X' &&
            board[25] == 'X')
        {
            return true;
        }

        // check diag 3 boards
        if (board[9] == 'X' &&
            board[14] == 'X' &&
            board[19] == 'X')
        {
            return true;
        }

        // check diag 3 boards
        if ((i == 7) &&
            board[7] == 'X' &&
            board[14] == 'X' &&
            board[21] == 'X')
        {
            return true;
        }

        // check diag 3 boards
        if (board[8] == 'X' &&
            board[14] == 'X' &&
            board[20] == 'X')
        {
            return true;
        }

        // check diag 3 boards
        if ((i == 1) &&
            board[i] == 'X' &&
            board[i + 13] == 'X' &&
            board[i + 26] == 'X')
        {
            return true;
        }

        // check diag 3 boards
        if (board[25] == 'X' &&
            board[14] == 'X' &&
            board[3] == 'X')
        {
            return true;
        }

        // check diag 3 boards
        if (board[9] == 'X' &&
            board[15] == 'X' &&
            board[21] == 'X')
        {
            return true;
        }

        // check diag 3 boards
        if (board[7] == 'X' &&
            board[14] == 'X' &&
            board[21] == 'X')
        {
            return true;
        }

        // check diag 3 boards
        if (board[27] == 'X' &&
            board[15] == 'X' &&
            board[3] == 'X')
        {
            return true;
        }

        // check diag 3 boards
        if (board[27] == 'X' &&
            board[14] == 'X' &&
            board[1] == 'X')
        {
            return true;
        }
    }

    for (int i = 1; i < 28; i++)
    {
        ////////////////////////////////////
        //          O - COMPUTER          //
        ////////////////////////////////////

        //////////////////////////////////
        //           1 BOARD            //
        //////////////////////////////////
        // check row 1 board
        if ((i - 1) % 3 == 0 &&
            board[i] == 'O' &&
            board[i + 1] == 'O' &&
            board[i + 2] == 'O')
        {
            return true;
        }
        // check cols 1 board
        if ((i == 1 || i == 2 || i == 3 || i == 10 || i == 11 || i == 12 || i == 19 || i == 20 || i == 21) &&
            board[i] == 'O' &&
            board[i + 3] == 'O' &&
            board[i + 6] == 'O')
        {
            return true;
        }
        //////////////////////////////////
        //           DIAG 1 BOARD       //
        //////////////////////////////////
        // check diag 1 board
        if ((i == 1 || i == 10 || i == 19) &&
            board[i] == 'O' &&
            board[i + 4] == 'O' &&
            board[i + 8] == 'O')
        {
            return true;
        }

        // check diag 1 board
        if ((i == 3 || i == 12 || i == 21) &&
            board[i] == 'O' &&
            board[i + 2] == 'O' &&
            board[i + 4] == 'O')
        {
            return true;
        }

        //////////////////////////////////
        //           3 BOARD            //
        //////////////////////////////////
        // check row 3 boards
        if (board[i] == 'O' &&
            board[i + 9] == 'O' &&
            board[i + 18] == 'O')
        {
            return true;
        }
        // check rows 3 boards
        if ((i == 2 || i == 5 || i == 8) &&
            board[i] == 'O' &&
            board[i + 10] == 'O' &&
            board[i + 20] == 'O')
        {
            return true;
        }
        // check cols 3 boards
        if ((i == 1 || i == 2 || i == 3) &&
            board[i] == 'O' &&
            board[i + 12] == 'O' &&
            board[i + 24] == 'O')
        {
            return true;
        }

        //////////////////////////////////
        //         DIAG 3 BOARD         //
        //////////////////////////////////
        // check diag 3 boards
        if (board[1] == 'O' &&
            board[13] == 'O' &&
            board[25] == 'O')
        {
            return true;
        }

        // check diag 3 boards
        if (board[9] == 'O' &&
            board[14] == 'O' &&
            board[19] == 'O')
        {
            return true;
        }

        // check diag 3 boards
        if ((i == 7) &&
            board[7] == 'O' &&
            board[14] == 'O' &&
            board[21] == 'O')
        {
            return true;
        }

        // check diag 3 boards
        if (board[8] == 'O' &&
            board[14] == 'O' &&
            board[20] == 'O')
        {
            return true;
        }

        // check diag 3 boards
        if ((i == 1) &&
            board[i] == 'O' &&
            board[i + 13] == 'O' &&
            board[i + 26] == 'O')
        {
            return true;
        }

        // check diag 3 boards
        if (board[25] == 'O' &&
            board[14] == 'O' &&
            board[3] == 'O')
        {
            return true;
        }

        // check diag 3 boards
        if (board[9] == 'O' &&
            board[15] == 'O' &&
            board[21] == 'O')
        {
            return true;
        }

        // check diag 3 boards
        if (board[7] == 'O' &&
            board[14] == 'O' &&
            board[21] == 'O')
        {
            return true;
        }

        // check diag 3 boards
        if (board[27] == 'O' &&
            board[15] == 'O' &&
            board[3] == 'O')
        {
            return true;
        }

        // check diag 3 boards
        if (board[27] == 'O' &&
            board[14] == 'O' &&
            board[1] == 'O')
        {
            return true;
        }
    }
    return false;
}

void computerMove(char board[])
{
    // Check for winning move for Computer
    for (int i = 1; i < 28; i++)
    {
        if (checkIfLegal(i, board) == true)
        {
            board[i] = 'O';
            if (!checkWinner(board))
            {
                board[i] = i;
            }
            else // Something filled in O
            {
                return;
            }
        }
    }

    // Check for winning move for Player
    for (int i = 1; i < 28; i++)
    {
        if (checkIfLegal(i, board) == true)
        {
            board[i] = 'X';
            if (!checkWinner(board))
            {
                board[i] = i;
            }
            else // Remove the winning move
            {
                board[i] = 'O';
                return;
            }
        }
    }
    int r = (rand() % 27) + 1;

    bool is_legal = checkIfLegal(r, board);

    while (!is_legal)
    {
        r = (rand() % 27) + 1;
        is_legal = checkIfLegal(r, board);
    }

    // Found a legal move, add to board and exit
    board[r] = 'O';
    return;
}
