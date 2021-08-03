#include <iostream>
#include <string>

using namespace std;

void boardGraphic (string displayBoard[]){

    cout << displayBoard[0] << " | " << displayBoard[1] << " | " << displayBoard[2] << endl;
    cout << "---------" << endl;
    cout << displayBoard[3] << " | " << displayBoard[4] << " | " << displayBoard[5] << endl;
    cout << "---------" << endl;
    cout << displayBoard[6] << " | " << displayBoard[7] << " | " << displayBoard[8] << endl;

}

//This function tests the board matrix for a winner
bool boardStatus (string showBoard[]){

    int i = 0;
    if (showBoard[0] == showBoard[1] && showBoard[1] == showBoard[2]){
        return true;
    }
    else if (showBoard[3] == showBoard[4] && showBoard[4] == showBoard[5]){
        return true;
    }
    else if (showBoard[6] == showBoard[7] && showBoard[7] == showBoard[8]){
        return true;
    }
    else if (showBoard[0] == showBoard[3] && showBoard[3] == showBoard[6]){
        return true;
    }
    else if (showBoard[1] == showBoard[4] && showBoard[4] == showBoard[7]){
        return true;
    }
    else if (showBoard[2] == showBoard[5] && showBoard[5] == showBoard[8]){
        return true;
    }
    else if (showBoard[0] == showBoard[4] && showBoard[4] == showBoard[8]){
        return true;
    }
    else if (showBoard[2] == showBoard[4] && showBoard[4] == showBoard[6]){
        return true;
    }
    else
        return false;
}


int main()
{
    string start;
    //Variable to indicate status of game initialized to false at beginning
    bool winner = false;
    //These are the letter indicators assigned to each player and the standard size board (later to add selected nxn sized board determined by input
    string player1, player2, board[9];
    int selection;

    //Populates board with options
    for (int i = 0; i <= (sizeof(board)/sizeof(board[0]))-1; i++){
        board[i] = to_string(i + 1);
    }

    cout << "Welcome to TicTacToe" << endl;
    cout << "Would you like to play? (Type Yes or No)"<< endl;
    cin >> start;

    if (start == "Yes"){
        cout << "Welcome" << endl;
        cout << "This is a two player game" << endl;
        cout << "Player 1 chose X or O " << endl;
        cin >> player1;
        if (player1.compare("X") == 0){
            player2 = "O";
        }
        else{
            player2 = "X";
        }

        cout << "Player 1 will play as " << player1 << endl;
        cout << "Player 2 will play as " << player2 << endl;
        cout << "Lets begin" << endl;
        // boardStatus (boardPtr) call function to display current board passing pointers of player
        boardGraphic (board);
        int numTurns = 0;
        //While loop where the game is played that exits when a winner is declared.
        while (winner != true){
            cout << "Player 1, Please select a number position you would like to place a marker" << endl;
            cin >> selection;
            board[selection-1] = player1;
            boardGraphic (board);
            winner = boardStatus(board);
            if (winner == true){
                cout << "Congratulations Player 1 has won the game" << endl;
                break;
            }
            else{
                numTurns++;
            }
            cout << "Player 2, Please select a number position you would like to place a marker" << endl;
            cin >> selection;
            board[selection-1] = player2;
            boardGraphic (board);
            if (winner == true){
                cout << "Congratulations Player 1 has won the game" << endl;
                break;
            }
            else{
                numTurns++;
            }
            if (numTurns == 9){
                cout << "The game is a tie" << endl;
                break;
            }
        }
        cout << "Play again soon" << endl;
    }
    else {
        cout << "Goodbye" << endl;
    }
    return 0;
}
