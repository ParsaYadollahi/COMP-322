
#include <iostream>
#include "tic_tac_toe.cpp"
using namespace std;

int main()
{
    // Display instructions
    greetAndInstruct();

    char board[27];
    int input;
    bool winner = false;

    displayBoard(board);

    while (winner == false)
    {

        cout << "Player's Turn: ";
        cin >> input;

        //Check if input is good
        bool is_legal = checkIfLegal(input, board);
        while (!is_legal)
        {
            // Check if input is an interger
            if (!std::isdigit(input))
            {
                cout << "Not an Integer, try again: ";
                std::cin.clear();
                std::cin.ignore();
            }
            // Did not put a correct input
            cout << "Cell already in use. Try again: ";
            cin >> input;
            is_legal = checkIfLegal(input, board);
        }
        // Add the valid input and display the board
        board[input] = 'X';
        displayBoard(board);

        // Check if theres a winner
        if (checkWinner(board))
        {
            cout << "Player won" << endl;
            break;
        }
        cout << endl;

        cout << "Computer's Turn ";
        cout
            << endl;

        // Make the computer take a turn and display board
        computerMove(board);
        displayBoard(board);

        if (checkWinner(board))
        {
            cout << "Computer won" << endl;
            break;
        }
        cout << endl;
    }
    return 0;
}
